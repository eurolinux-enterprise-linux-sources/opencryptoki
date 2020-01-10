Name:			opencryptoki
Summary:		Implementation of the PKCS#11 (Cryptoki) specification v2.11
Version:		2.4.3.1
Release:		1%{?dist}
License:		CPL
Group:			System Environment/Base
URL:			http://sourceforge.net/projects/opencryptoki
Source:			http://downloads.sourceforge.net/%{name}/%{name}-%{version}-tar.gz
Patch0:			%{name}-2.3.2-do-not-create-group-in-pkcs11_startup.patch
# https://bugzilla.redhat.com/show_bug.cgi?id=732756
Patch1:			opencryptoki-2.4-group.patch
# fix locks dir installation
Patch2:			%{name}-2.4.3-locks.patch
BuildRoot:		%(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)
Requires(pre):		shadow-utils coreutils sed
Requires(post):		chkconfig
Requires(preun):	chkconfig
# This is for /sbin/service
Requires(preun):	initscripts
Requires(postun):	initscripts
BuildRequires:		openssl-devel trousers-devel
BuildRequires:		autoconf automake libtool
%ifarch s390 s390x
BuildRequires:		libica-devel >= 2.0
%endif
Requires:		%{name}-libs%{?_isa} = %{version}-%{release}

%description
openCryptoki implements the PKCS#11 specification v2.11. It includes support
for cryptographic hardware such as the IBM 4758 Cryptographic CoProcessor,
the IBM eServer Cryptographic Accelerator (FC 4960 on pSeries) or the Trusted
Platform Module (TPM) as well as a software token for testing.

%package libs
Group:			System Environment/Libraries
Summary:		The runtime libraries for opencryptoki package

%description libs
The runtime libraries for use with openCryptoki based applications.

%package devel
Group:			Development/Libraries
Summary:		Development files for openCryptoki
Requires:		%{name}-libs = %{version}-%{release}

%description devel
This package contains the development header files for building openCryptoki
based applications.

%prep
%setup -q -n %{name}-%{name}
%patch0 -p1
%patch1 -p1 -b .group
%patch2 -p1 -b .locks

%build
# Upstream tarball has unnecessary executable perms set on the sources
find . -name '*.[ch]' -print0 | xargs -0 chmod -x

./bootstrap.sh
%configure	\
%ifarch s390 s390x
    --enable-icatok --enable-ccatok
%else
    --disable-icatok --disable-ccatok
%endif

make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT

make install DESTDIR=$RPM_BUILD_ROOT

mkdir -p $RPM_BUILD_ROOT/%{_sharedstatedir}/%{name}

# Remove unwanted cruft
rm -f $RPM_BUILD_ROOT/%{_libdir}/%{name}/*.la
rm -f $RPM_BUILD_ROOT/%{_libdir}/%{name}/stdll/*.la

%clean
rm -rf $RPM_BUILD_ROOT

%postun libs -p /sbin/ldconfig

%post libs -p /sbin/ldconfig

%postun
if [ "$1" -ge "1" ] ; then
	/sbin/service pkcsslotd condrestart >/dev/null 2>&1
fi
exit 0

%post
/sbin/chkconfig --add pkcsslotd
exit 0

%preun
if [ "$1" = "0" ] ; then
	/sbin/service pkcsslotd stop >/dev/null 2>&1
	/sbin/chkconfig --del pkcsslotd
fi
exit 0

%pre
getent group pkcs11 >/dev/null || groupadd -r pkcs11
exit 0

%files
%defattr(-,root,root,-)
%doc FAQ README LICENSE doc/*
%{_initddir}/pkcsslotd
%{_sbindir}/*
%{_mandir}/man*/*
%dir %attr(770,root,pkcs11) %{_sharedstatedir}/%{name}

%files libs
%defattr(-,root,root,-)
%{_sysconfdir}/ld.so.conf.d/*
# Unversioned .so symlinks usually belong to -devel packages, but opencryptoki
# needs them in the main package, because:
#   pkcs11_startup looks for opencryptoki/stdll/*.so, and
#   documentation suggests that programs should dlopen "PKCS11_API.so".
%{_libdir}/opencryptoki
%{_libdir}/pkcs11

%files devel
%defattr(-,root,root,-)
%{_includedir}/%{name}


%changelog
* Thu Jul 11 2013 Dan Horák <dhorak@redhat.com> 2.4.3.1-1
- rebased to 2.4.3.1 (#948349)
- Resolves: #948349

* Mon Sep  5 2011 Dan Horák <dhorak@redhat.com> 2.4-2
- don't add root to pkcs11 group (#732756)
- document implications of the pkcs11 group membership (#730903)
- Resolves: #732756, #730903

* Wed Jul 13 2011 Dan Horák <dhorak@redhat.com> 2.4-1
- rebased to 2.4 (#693779)
- Resolves: #693779

* Wed Apr 27 2011 Dan Horák <dhorak@redhat.com> 2.3.3-2
- don't always mark data as invalid when stripping padding data (#699408)
- Resolves: #699408

* Fri Jan 14 2011 Dan Horák <dhorak@redhat.com> 2.3.3-1
- rebased to 2.3.3 (#632765)
- Resolves: #632765

* Wed Jan 12 2011 Dan Horák <dhorak@redhat.com> 2.3.2-1
- rebased to 2.3.2 (#632765)
- Resolves: #632765

* Thu May 20 2010 Dan Horák <dhorak@redhat.com> 2.3.1-5
- rebuilt with CCA enabled (#604287)
- Resolves: #604287

* Thu May 20 2010 Dan Horák <dhorak@redhat.com> 2.3.1-4
- fixed issues from #546274
- Resolves: #546274

* Fri Apr 30 2010 Dan Horák <dhorak@redhat.com> 2.3.1-3
- fixed one more issue in the initscript (#547324)
- Related: #547324

* Tue Apr 27 2010 Dan Horák <dhorak@redhat.com> 2.3.1-2
- fixed pidfile creating and usage (#547324)
- Related: #547324

* Tue Mar  2 2010 Dan Horák <dhorak@redhat.com> 2.3.1-1
- New upstream release 2.3.1. (#559364)
- opencryptoki-2.3.0-fix-nss-breakage.patch was merged.
- updated pkcsslotd initscript (#547324)
- Resolves: #559364
- Related: #547324

* Mon Feb  8 2010 Dan Horák <dhorak@redhat.com> 2.3.0-6
- added missing action to pkcsslotd initscript (#547324)
- Related: #547324

* Fri Jan 22 2010 Dan Horák <dhorak@redhat.com> 2.3.0-5
- made pkcsslotd initscript LSB compliant (#547324)
- Resolves: #547324

* Fri Dec 11 2009 Dennis Gregorovic <dgregor@redhat.com> - 2.3.0-4.1
- Rebuilt for RHEL 6

* Mon Sep 07 2009 Michal Schmidt <mschmidt@redhat.com> 2.3.0-4
- Added opencryptoki-2.3.0-fix-nss-breakage.patch on upstream request.

* Fri Aug 21 2009 Tomas Mraz <tmraz@redhat.com> - 2.3.0-3
- rebuilt with new openssl

* Sun Aug 16 2009 Michal Schmidt <mschmidt@redhat.com> 2.3.0-2
- Require libica-2.0.

* Fri Aug 07 2009 Michal Schmidt <mschmidt@redhat.com> 2.3.0-1
- New upstream release 2.3.0:
  - adds support for RSA 4096 bit keys in the ICA token.

* Tue Jul 21 2009 Michal Schmidt <mschmidt@redhat.com> - 2.2.8-5
- Require arch-specific dependency on -libs.

* Tue Jul 21 2009 Michal Schmidt <mschmidt@redhat.com> - 2.2.8-4
- Return support for crypto hw on s390.
- Renamed to opencryptoki.
- Simplified multilib by putting libs in subpackage as suggested by Dan Horák.

* Tue Jul 21 2009 Michal Schmidt <mschmidt@redhat.com> - 2.2.8-2
- Fedora package based on RHEL-5 package.
