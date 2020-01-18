 /*
  * COPYRIGHT (c) International Business Machines Corp. 2001-2017
  *
  * This program is provided under the terms of the Common Public License,
  * version 1.0 (CPL-1.0). Any use, reproduction or distribution for this
  * software constitutes recipient's acceptance of CPL-1.0 terms which can be
  * found in the file LICENSE file or at
  * https://opensource.org/licenses/cpl1.0.php
  */

#define TestCert_Label "Self Signed Cert for PKCS#11"

char    DN[83] = {
48, 81, 49,  0, 49,  0, 49,  0, 49,  0,
49,  0, 49,  0, 49,  0, 49,  0, 49,  0,
49,  0, 49,  0, 49,  0, 49,  0, 49,  0,
49,  0, 49,  0, 49,  0, 49,  0, 49,  0,
49,  0, 49,  0, 49,  0, 49,  0, 49,  0,
49,  0, 49,  0, 49,  0, 49,  0, 49,  0,
49,  0, 49,  0, 49,  0, 49,  0, 49,  0,
49,  0, 49,  9, 48,  7,  6,  3, 85,  4,
 3, 19,  0
};

char    Issuer[83] = {
48, 81, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 9, 48, 7, 6, 3, 85, 4,
3, 19, 0
};

char    Cert[541] = {
48, 130, 2, 25, 48, 130, 1, 130, 160, 3,
2, 1, 2, 2, 4, 55, 196, 11, 144, 48,
13, 6, 9, 42, 134, 72, 134, 247, 13, 1,
1, 4, 5, 0, 48, 81, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 0, 49, 0,
49, 0, 49, 0, 49, 0, 49, 9, 48, 7,
6, 3, 85, 4, 3, 19, 0, 48, 30, 23,
13, 57, 57, 48, 56, 50, 52, 49, 53, 50,
56, 49, 54, 90, 23, 13, 48, 50, 48, 52,
49, 54, 49, 53, 50, 56, 49, 54, 90, 48,
81, 49, 0, 49, 0, 49, 0, 49, 0, 49,
0, 49, 0, 49, 0, 49, 0, 49, 0, 49,
0, 49, 0, 49, 0, 49, 0, 49, 0, 49,
0, 49, 0, 49, 0, 49, 0, 49, 0, 49,
0, 49, 0, 49, 0, 49, 0, 49, 0, 49,
0, 49, 0, 49, 0, 49, 0, 49, 0, 49,
0, 49, 0, 49, 0, 49, 0, 49, 0, 49,
0, 49, 9, 48, 7, 6, 3, 85, 4, 3,
19, 0, 48, 129, 159, 48, 13, 6, 9, 42,
134, 72, 134, 247, 13, 1, 1, 1, 5, 0,
3, 129, 141, 0, 48, 129, 137, 2, 129, 129,
0, 160, 224, 39, 50, 200, 43, 125, 162, 219,
163, 93, 182, 28, 38, 105, 248, 255, 78, 10,
54, 255, 234, 184, 7, 45, 219, 23, 131, 54,
130, 37, 184, 205, 41, 40, 38, 229, 190, 17,
130, 75, 151, 190, 209, 226, 37, 38, 145, 26,
237, 169, 117, 114, 169, 55, 107, 225, 24, 205,
171, 226, 82, 69, 57, 241, 149, 32, 188, 86,
234, 5, 206, 0, 20, 237, 210, 101, 109, 143,
160, 182, 15, 201, 2, 252, 237, 241, 120, 179,
187, 112, 143, 31, 156, 90, 173, 211, 130, 151,
164, 199, 235, 48, 223, 124, 145, 100, 3, 104,
188, 49, 110, 232, 54, 108, 30, 33, 169, 197,
137, 92, 244, 7, 135, 208, 216, 9, 141, 2,
3, 1, 0, 1, 48, 13, 6, 9, 42, 134,
72, 134, 247, 13, 1, 1, 4, 5, 0, 3,
129, 129, 0, 66, 115, 199, 229, 210, 234, 31,
199, 15, 171, 65, 13, 86, 149, 206, 161, 252,
120, 220, 228, 215, 39, 23, 180, 166, 151, 48,
77, 112, 119, 145, 165, 123, 159, 48, 0, 169,
191, 5, 16, 48, 199, 161, 49, 134, 91, 190,
235, 37, 80, 91, 96, 205, 43, 177, 13, 224,
10, 92, 211, 40, 50, 69, 103, 241, 121, 120,
227, 189, 99, 95, 92, 174, 83, 31, 45, 119,
103, 96, 192, 208, 245, 58, 248, 106, 203, 27,
218, 149, 139, 46, 204, 27, 104, 241, 98, 22,
58, 212, 207, 122, 100, 241, 39, 233, 54, 40,
66, 87, 177, 129, 12, 65, 107, 116, 30, 176,
220, 20, 183, 16, 104, 229, 84, 19, 35, 84,
204
};

char    PrivKey[633] = {
48, 130, 2, 117, 2, 1, 0, 48, 13, 6,
9, 42, 134, 72, 134, 247, 13, 1, 1, 1,
5, 0, 4, 130, 2, 95, 48, 130, 2, 91,
2, 1, 0, 2, 129, 129, 0, 160, 224, 39,
50, 200, 43, 125, 162, 219, 163, 93, 182, 28,
38, 105, 248, 255, 78, 10, 54, 255, 234, 184,
7, 45, 219, 23, 131, 54, 130, 37, 184, 205,
41, 40, 38, 229, 190, 17, 130, 75, 151, 190,
209, 226, 37, 38, 145, 26, 237, 169, 117, 114,
169, 55, 107, 225, 24, 205, 171, 226, 82, 69,
57, 241, 149, 32, 188, 86, 234, 5, 206, 0,
20, 237, 210, 101, 109, 143, 160, 182, 15, 201,
2, 252, 237, 241, 120, 179, 187, 112, 143, 31,
156, 90, 173, 211, 130, 151, 164, 199, 235, 48,
223, 124, 145, 100, 3, 104, 188, 49, 110, 232,
54, 108, 30, 33, 169, 197, 137, 92, 244, 7,
135, 208, 216, 9, 141, 2, 3, 1, 0, 1,
2, 129, 128, 9, 209, 3, 179, 78, 145, 144,
206, 2, 54, 250, 189, 229, 3, 215, 13, 145,
142, 146, 130, 254, 164, 180, 236, 3, 57, 78,
58, 252, 117, 126, 149, 195, 55, 18, 179, 36,
235, 175, 39, 211, 51, 4, 58, 204, 96, 213,
244, 158, 191, 7, 203, 25, 223, 7, 121, 182,
183, 139, 189, 68, 71, 30, 224, 44, 126, 87,
202, 196, 83, 124, 134, 139, 54, 29, 50, 175,
106, 126, 193, 7, 52, 67, 12, 115, 251, 84,
232, 222, 118, 41, 195, 5, 182, 176, 73, 79,
103, 107, 141, 96, 170, 242, 175, 183, 154, 13,
224, 45, 40, 49, 96, 146, 3, 9, 26, 21,
115, 33, 183, 118, 174, 68, 13, 198, 220, 105,
69, 2, 65, 0, 208, 30, 177, 14, 227, 148,
126, 152, 149, 117, 190, 215, 106, 133, 96, 66,
114, 141, 175, 245, 146, 81, 1, 197, 182, 147,
187, 214, 33, 125, 144, 126, 229, 192, 141, 200,
168, 106, 238, 231, 122, 104, 55, 70, 94, 82,
1, 155, 209, 245, 162, 101, 78, 1, 57, 33,
11, 205, 97, 202, 170, 26, 48, 43, 2, 65,
0, 197, 226, 253, 53, 187, 167, 237, 30, 197,
139, 227, 116, 80, 173, 71, 136, 99, 143, 199,
246, 94, 102, 86, 110, 152, 149, 122, 165, 243,
16, 98, 220, 143, 90, 3, 235, 88, 67, 41,
235, 146, 37, 192, 88, 54, 160, 79, 102, 76,
127, 246, 232, 222, 20, 70, 217, 22, 119, 50,
80, 182, 179, 153, 39, 2, 64, 122, 166, 203,
212, 41, 125, 23, 10, 151, 114, 151, 240, 222,
31, 18, 118, 182, 138, 23, 252, 18, 169, 216,
240, 139, 68, 15, 124, 7, 170, 183, 96, 129,
200, 116, 6, 160, 114, 188, 175, 0, 173, 176,
125, 177, 18, 133, 78, 46, 115, 163, 172, 46,
71, 124, 66, 164, 112, 250, 195, 244, 113, 144,
151, 2, 64, 52, 212, 28, 117, 51, 219, 232,
217, 198, 51, 74, 77, 203, 27, 247, 116, 217,
223, 144, 170, 157, 25, 5, 10, 17, 130, 22,
116, 39, 39, 192, 188, 209, 40, 94, 211, 125,
132, 176, 180, 75, 23, 248, 249, 147, 219, 200,
86, 175, 37, 154, 109, 32, 156, 153, 45, 107,
105, 246, 236, 197, 89, 189, 17, 2, 64, 92,
208, 59, 86, 221, 175, 121, 63, 31, 217, 197,
148, 228, 143, 254, 51, 187, 57, 71, 38, 153,
157, 38, 65, 121, 247, 184, 55, 159, 47, 207,
153, 186, 45, 117, 138, 229, 175, 95, 21, 161,
206, 167, 112, 119, 67, 201, 138, 92, 243, 1,
142, 133, 117, 15, 106, 195, 57, 136, 191, 217,
48, 0, 98,
};

char    PubKey[162] = {
48, 129, 159, 48, 13, 6, 9, 42, 134, 72,
134, 247, 13, 1, 1, 1, 5, 0, 3, 129,
141, 0, 48, 129, 137, 2, 129, 129, 0, 160,
224, 39, 50, 200, 43, 125, 162, 219, 163, 93,
182, 28, 38, 105, 248, 255, 78, 10, 54, 255,
234, 184, 7, 45, 219, 23, 131, 54, 130, 37,
184, 205, 41, 40, 38, 229, 190, 17, 130, 75,
151, 190, 209, 226, 37, 38, 145, 26, 237, 169,
117, 114, 169, 55, 107, 225, 24, 205, 171, 226,
82, 69, 57, 241, 149, 32, 188, 86, 234, 5,
206, 0, 20, 237, 210, 101, 109, 143, 160, 182,
15, 201, 2, 252, 237, 241, 120, 179, 187, 112,
143, 31, 156, 90, 173, 211, 130, 151, 164, 199,
235, 48, 223, 124, 145, 100, 3, 104, 188, 49,
110, 232, 54, 108, 30, 33, 169, 197, 137, 92,
244, 7, 135, 208, 216, 9, 141, 2, 3, 1,
0, 1
};
