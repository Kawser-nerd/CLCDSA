/*

import "core"
import "stdio"

fn get_len(x Int) Int {
  num := x
  l := 0
  while (num != 0) {
    num = cast[Int](num / 10)
    l += 1
  }
  l
}

fn main() {
  n := read_int()
  sq := cast[Int](sqrt(cast[Double](n)))

  ans := 99999999
  for i in range(1, sq) {
    if (n % i == 0) {
      j := cast[Int](n / i)
      left := get_len(i)
      right := get_len(j)
      if (left > right) {
        if (left < ans) {
          ans = left
        }
      } else {
        if (right < ans) {
          ans = right
        }
      }
    }
  }
  println(ans)
}

main()

*/
#include "stdbool.h"
#include "stdint.h"
bool core_prelude_true;
bool core_prelude_false;
bool core_definitions_is_windows;
bool core_definitions_is_compiletime;
bool core_definitions_is_runtime;
bool core_definitions_is_jscodegen;
#include "math.h"
float core_math_M_PI;
#include "stdio.h"
void* core_pointer_nullGG_() {
void* core_pointer_tmpid39 = ((void*)(0));
return core_pointer_tmpid39;
}
void* core_pointer_null;
char* core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char__core_prelude_Int(char* core_pointer_p, int64_t core_pointer_i) {
char* core_pointer_tmpid40 = ((char*)((((int64_t)(core_pointer_p)) + core_pointer_i)));
return core_pointer_tmpid40;
}
char core_string_getGG_core_prelude_CString_core_prelude_Int(char* core_string_cs, int64_t core_string_i) {
char core_string_tmpid41 = (*(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char__core_prelude_Int(((char*)(core_string_cs)), core_string_i)));
return core_string_tmpid41;
}
#include "string.h"
struct core_string_String {
char* p;
int64_t len;
};
char core_string_charGG_core_prelude_Int(int64_t core_string_c) {
char core_string_tmpid44 = ((char)(core_string_c));
return core_string_tmpid44;
}
char core_string_cr;
char core_string_lf;
#include "inttypes.h"
int64_t stdio_read_intGG_() {
int64_t stdio_ret;
scanf("%" PRId64, &stdio_ret);
int64_t stdio_tmpid65 = stdio_ret;
return stdio_tmpid65;
}
struct Array1024_core_prelude_Char { char data[1024]; };
int64_t a3_get_lenGG_core_prelude_Int(int64_t a3_x) {
int64_t a3_num = a3_x;
int64_t a3_l = 0;
while ((a3_num != 0)) {
double __floritmp0 = (((double)(a3_num)) / ((double)(10)));
a3_num = ((int64_t)(__floritmp0));
(a3_l += 1);
};
int64_t a3_tmpid67 = a3_l;
return a3_tmpid67;
}
void a3_mainGG_() {
int64_t a3_n = stdio_read_intGG_();
int64_t a3_sq = ((int64_t)(sqrt(((double)(a3_n)))));
int64_t a3_ans = 99999999;
{
int64_t a3_i = 1;
while ((a3_i <= a3_sq)) {
if (((a3_n % a3_i) == 0)) {
double __floritmp2 = (((double)(a3_n)) / ((double)(a3_i)));
int64_t a3_j = ((int64_t)(__floritmp2));
int64_t a3_left = a3_get_lenGG_core_prelude_Int(a3_i);
int64_t a3_right = a3_get_lenGG_core_prelude_Int(a3_j);
if ((a3_left > a3_right)) {
if ((a3_left < a3_ans)) {
a3_ans = a3_left;
} else {}} else {if ((a3_right < a3_ans)) {
a3_ans = a3_right;
} else {}}} else {};
(a3_i += 1);
};

}
;
;
;
printf("%lld", a3_ans);
;
;
printf("%s", "\n");
;
;
;
}

void flori_main() {
core_prelude_true = 1;
core_prelude_false = 0;
core_definitions_is_windows = 
#ifdef _WIN32
#define is_windows true
#elif _WIN64
#define is_windows true
#else
#define is_windows false
#endif
  is_windows;
core_definitions_is_compiletime = 
#ifdef FLORI_COMPILETIME
#define is_compiletime true
#else
#define is_compiletime false
#endif
  is_compiletime;
core_definitions_is_runtime = !(core_definitions_is_compiletime);
core_definitions_is_jscodegen = 
#ifdef FLORI_JSCODEGEN
#define is_jscodegen true
#else
#define is_jscodegen false
#endif
  is_jscodegen;
core_math_M_PI = M_PI;
core_pointer_null = core_pointer_nullGG_();
core_string_cr = core_string_charGG_core_prelude_Int(13);
core_string_lf = core_string_charGG_core_prelude_Int(10);
a3_mainGG_();
}
int main(int argc, char** argv) { flori_main(); } ./Main.c: In function ‘a3_mainGG_’:
./Main.c:122:8: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int64_t {aka long int}’ [-Wformat=]
 printf("%lld", a3_ans);
        ^
./Main.c: In function ‘stdio_read_intGG_’:
./Main.c:81:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%" PRId64, &stdio_ret);
 ^