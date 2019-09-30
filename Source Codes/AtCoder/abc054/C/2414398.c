/*

import "core"
import "std/algorithm"
import "procon"

type Edge {
  s Int
  t Int
}

var g Array[8, Vec[Int]]

fn max(a Int, b Int) Int {
  if (a > b) {
    a
  } else {
    b
  }
}

fn is_route(check Vec[Bool]) Bool {
  for i in range(0, length(check)-1) {
    if (not(get(check, i))) {
      return(false)
    }
  }
  true
}

destructor(b Bool) {}
destructor(b Int) {}

fn dfs(v Int, check Vec[Bool]) Int {
  if (get(check, v)) {
    return(0)
  }
  ans := 0
  c := copy(check)
  set(c, v, true)
  if (is_route(c)) {
    debug(check)
    ans += 1
  }
  for i in range(0, length(get(g, v))-1) {
    debug(v, get(get(g, v), i))
    ans += dfs(get(get(g, v), i), c)
  }
  ans
}

fn main() {
  n := read_int()
  m := read_int()
  for i in range(0, n-1) {
    set(g, i, vec[Int]())
  }
  for i in range(0, m-1) {
    s := read_int()
    t := read_int()
    push(rget(g, s-1), t-1)
    push(rget(g, t-1), s-1)
  }

  check := vec[Bool]()
  for i in range(0, n-1) {
    push(check, false)
  }
  println(dfs(0, check))
}

main()

*/
#define RELEASE

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "inttypes.h"
#include "stdio.h"
#include "math.h"


struct core_string_String {
char* p;
int64_t len;
};
struct core_vec_Vec_core_string_String {
struct core_string_String* data;
bool* isinit;
int64_t cap;
int64_t len;
};
struct Array1024_core_prelude_Char { char data[1024]; };
struct c_Edge {
int64_t s;
int64_t t;
};
struct core_vec_Vec_core_prelude_Int {
int64_t* data;
bool* isinit;
int64_t cap;
int64_t len;
};
struct Array8_core_vec_Vec_core_prelude_Int { struct core_vec_Vec_core_prelude_Int data[8]; };
struct core_vec_Vec_core_prelude_Bool {
bool* data;
bool* isinit;
int64_t cap;
int64_t len;
};

void* core_pointer_nullGG_();
char* core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_p, int64_t core_pointer_i);
char core_string_getGG_core_prelude_CString_core_prelude_Int(char* core_string_cs, int64_t core_string_i);
char core_string_charGG_core_prelude_Int(int64_t core_string_c);
char* core_pointer_allocGcore_prelude_CharG_core_prelude_Int(int64_t core_pointer_len);
void core_pointer_memcpyGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_dest, char* core_pointer_src, int64_t core_pointer_len);
struct core_string_String core_string_stringGG_core_prelude_CString(char* core_string_cs);
char* core_string_to_csGG_core_string_String(struct core_string_String core_string_s);
int64_t core_string_lengthGG_core_string_String(struct core_string_String core_string_s);
char* core_pointer_reallocGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_ptr, int64_t core_pointer_len);
void core_string_pushGG_core_string_String_core_prelude_CString(struct core_string_String* core_string_dest, char* core_string_src);
bool* core_pointer_allocGcore_prelude_BoolG_core_prelude_Int(int64_t core_pointer_len);
bool* core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(bool* core_pointer_p, int64_t core_pointer_i);
bool* core_pointer_reallocGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(bool* core_pointer_ptr, int64_t core_pointer_len);
bool core_definitions_is_release_fnGG_();
bool core_definitions_is_debug_fnGG_();
int64_t procon_read_intGG_();
int64_t core_vec_lengthGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool core_vec_v);
bool core_vec_getGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int(struct core_vec_Vec_core_prelude_Bool core_vec_v, int64_t core_vec_i);
bool c_is_routeGG_core_vec_Vec_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool c_check);
void c_destructGG_core_prelude_Bool(bool c_b);
void c_destructGG_core_prelude_Int(int64_t c_b);
struct core_vec_Vec_core_prelude_Bool core_vec_vecGcore_prelude_BoolG_core_prelude_Int_core_prelude_Int(int64_t core_vec_len, int64_t core_vec_cap);
void core_vec_setGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool* core_vec_v, int64_t core_vec_i, bool core_vec_value);
struct core_vec_Vec_core_prelude_Bool core_vec_copyGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool core_vec_v);
int64_t core_vec_lengthGcore_prelude_IntG_core_vec_Vec_core_prelude_Int(struct core_vec_Vec_core_prelude_Int core_vec_v);
int64_t* core_pointer_plusexclGcore_prelude_IntG_core_pointer_Ptr_core_prelude_Int_core_prelude_Int(int64_t* core_pointer_p, int64_t core_pointer_i);
int64_t core_vec_getGcore_prelude_IntG_core_vec_Vec_core_prelude_Int_core_prelude_Int(struct core_vec_Vec_core_prelude_Int core_vec_v, int64_t core_vec_i);
int64_t c_dfsGG_core_prelude_Int_core_vec_Vec_core_prelude_Bool(int64_t c_v, struct core_vec_Vec_core_prelude_Bool c_check);
int64_t* core_pointer_allocGcore_prelude_IntG_core_prelude_Int(int64_t core_pointer_len);
struct core_vec_Vec_core_prelude_Int core_vec_vecGcore_prelude_IntG_core_prelude_Int_core_prelude_Int(int64_t core_vec_len, int64_t core_vec_cap);
struct core_vec_Vec_core_prelude_Int core_vec_vecGcore_prelude_IntG_();
int64_t* core_pointer_reallocGcore_prelude_IntG_core_pointer_Ptr_core_prelude_Int_core_prelude_Int(int64_t* core_pointer_ptr, int64_t core_pointer_len);
void core_vec_extendGcore_prelude_IntG_core_vec_Vec_core_prelude_Int(struct core_vec_Vec_core_prelude_Int* core_vec_v);
void core_vec_pushGcore_prelude_IntG_core_vec_Vec_core_prelude_Int_core_prelude_Int(struct core_vec_Vec_core_prelude_Int* core_vec_v, int64_t core_vec_value);
struct core_vec_Vec_core_prelude_Bool core_vec_vecGcore_prelude_BoolG_();
void core_vec_extendGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool* core_vec_v);
void core_vec_pushGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool* core_vec_v, bool core_vec_value);
void c_mainGG_();


bool core_prelude_true;
bool core_prelude_false;
void* core_pointer_nullGG_() {
return ((void*)(0));
}
void* core_pointer_null;
float core_math_M_PI;
char* core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_p, int64_t core_pointer_i) {
return ((char*)((((int64_t)(core_pointer_p)) + core_pointer_i)));
}
char core_string_getGG_core_prelude_CString_core_prelude_Int(char* core_string_cs, int64_t core_string_i) {
return (*(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(((char*)(core_string_cs)), core_string_i)));
}
char core_string_charGG_core_prelude_Int(int64_t core_string_c) {
return ((char)(core_string_c));
}
char* core_pointer_allocGcore_prelude_CharG_core_prelude_Int(int64_t core_pointer_len) {
return ((char*)(malloc((sizeof(char) * core_pointer_len))));
}
void core_pointer_memcpyGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_dest, char* core_pointer_src, int64_t core_pointer_len) {
memcpy(((void*)(core_pointer_dest)), ((void*)(core_pointer_src)), (sizeof(char) * core_pointer_len));
}
struct core_string_String core_string_stringGG_core_prelude_CString(char* core_string_cs) {
int64_t core_string_len = strlen(core_string_cs);
struct core_string_String core_string_s = (struct core_string_String){core_pointer_allocGcore_prelude_CharG_core_prelude_Int((core_string_len + 1)), core_string_len};
core_pointer_memcpyGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_s.p, ((char*)(core_string_cs)), core_string_len);
(*(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_s.p, core_string_len))) = core_string_charGG_core_prelude_Int(0);
return core_string_s;
}
char* core_string_to_csGG_core_string_String(struct core_string_String core_string_s) {
return ((char*)(core_string_s.p));
}
int64_t core_string_lengthGG_core_string_String(struct core_string_String core_string_s) {
return core_string_s.len;
}
char* core_pointer_reallocGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(char* core_pointer_ptr, int64_t core_pointer_len) {
return ((char*)(realloc(((void*)(core_pointer_ptr)), (sizeof(char) * core_pointer_len))));
}
void core_string_pushGG_core_string_String_core_prelude_CString(struct core_string_String* core_string_dest, char* core_string_src) {
int64_t core_string_l = (core_string_lengthGG_core_string_String(*core_string_dest) + strlen(core_string_src));
core_string_dest->p = core_pointer_reallocGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_dest->p, (core_string_l + 1));
core_pointer_memcpyGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_dest->p, core_string_lengthGG_core_string_String(*core_string_dest)), ((char*)(core_string_src)), strlen(core_string_src));
(*(core_pointer_plusexclGcore_prelude_CharG_core_pointer_Ptr_core_prelude_Char_core_prelude_Int(core_string_dest->p, core_string_l))) = core_string_charGG_core_prelude_Int(0);
core_string_dest->len = core_string_l;
}
char core_string_cr;
char core_string_lf;
bool* core_pointer_allocGcore_prelude_BoolG_core_prelude_Int(int64_t core_pointer_len) {
return ((bool*)(malloc((sizeof(bool) * core_pointer_len))));
}
bool* core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(bool* core_pointer_p, int64_t core_pointer_i) {
return ((bool*)((((int64_t)(core_pointer_p)) + core_pointer_i)));
}
bool* core_pointer_reallocGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(bool* core_pointer_ptr, int64_t core_pointer_len) {
return ((bool*)(realloc(((void*)(core_pointer_ptr)), (sizeof(bool) * core_pointer_len))));
}
bool core_definitions_is_windows;
bool core_definitions_is_compiletime;
bool core_definitions_is_runtime;
bool core_definitions_is_jscodegen;
bool core_definitions_is_release_fnGG_() {
bool __floritmp1 = core_prelude_true;
bool __floritmp0 = __floritmp1;
return __floritmp0;
}
bool core_definitions_is_debug_fnGG_() {
bool __floritmp3 = core_prelude_true;
bool __floritmp2 = __floritmp3;
return !(__floritmp2);
}
bool core_definitions_is_release;
bool core_definitions_is_debug;
#define procon_INF 999999999
#define procon_MOD 1000000007
int64_t procon_read_intGG_() {
int64_t procon_ret;
scanf("%" PRId64, &procon_ret);
return procon_ret;
}
struct Array8_core_vec_Vec_core_prelude_Int c_g;
int64_t core_vec_lengthGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool core_vec_v) {
return core_vec_v.len;
}
bool core_vec_getGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int(struct core_vec_Vec_core_prelude_Bool core_vec_v, int64_t core_vec_i) {
return (*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v.data, ((core_vec_i * sizeof(bool))))));
}
bool c_is_routeGG_core_vec_Vec_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool c_check) {
{
int64_t c_i = 0;
while ((c_i <= (core_vec_lengthGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(c_check) - 1))) {
if (!(core_vec_getGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int(c_check, c_i))) {
return core_prelude_false;
} else {};
(c_i += 1);
};

}
;
;
;
return core_prelude_true;
}
void c_destructGG_core_prelude_Bool(bool c_b) {
}
void c_destructGG_core_prelude_Int(int64_t c_b) {
}
struct core_vec_Vec_core_prelude_Bool core_vec_vecGcore_prelude_BoolG_core_prelude_Int_core_prelude_Int(int64_t core_vec_len, int64_t core_vec_cap) {
struct core_vec_Vec_core_prelude_Bool core_vec_v = (struct core_vec_Vec_core_prelude_Bool){core_pointer_allocGcore_prelude_BoolG_core_prelude_Int(core_vec_cap), core_pointer_allocGcore_prelude_BoolG_core_prelude_Int(core_vec_cap), core_vec_cap, core_vec_len};
{
int64_t core_vec_i = 0;
while ((core_vec_i <= (core_vec_cap - 1))) {
(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v.isinit, (core_vec_i * sizeof(bool))))) = core_prelude_false;
;
(core_vec_i += 1);
};

}
;
;
;
return core_vec_v;
}
void core_vec_setGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool* core_vec_v, int64_t core_vec_i, bool core_vec_value) {
if ((*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, ((core_vec_i * sizeof(bool))))))) {
c_destructGG_core_prelude_Bool((*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->data, ((core_vec_i * sizeof(bool)))))));
} else {}(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, ((core_vec_i * sizeof(bool)))))) = core_prelude_true;
(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->data, ((core_vec_i * sizeof(bool)))))) = core_vec_value;
}
struct core_vec_Vec_core_prelude_Bool core_vec_copyGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool core_vec_v) {
struct core_vec_Vec_core_prelude_Bool core_vec_ret = core_vec_vecGcore_prelude_BoolG_core_prelude_Int_core_prelude_Int(core_vec_v.len, core_vec_v.cap);
{
int64_t core_vec_i = 0;
while ((core_vec_i <= (core_vec_lengthGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(core_vec_v) - 1))) {
{};
;
core_vec_setGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int_core_prelude_Bool(&core_vec_ret, core_vec_i, core_vec_getGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int(core_vec_v, core_vec_i));
;
;
;
(core_vec_i += 1);
};

}
;
;
;
return core_vec_ret;
}
int64_t core_vec_lengthGcore_prelude_IntG_core_vec_Vec_core_prelude_Int(struct core_vec_Vec_core_prelude_Int core_vec_v) {
return core_vec_v.len;
}
int64_t* core_pointer_plusexclGcore_prelude_IntG_core_pointer_Ptr_core_prelude_Int_core_prelude_Int(int64_t* core_pointer_p, int64_t core_pointer_i) {
return ((int64_t*)((((int64_t)(core_pointer_p)) + core_pointer_i)));
}
int64_t core_vec_getGcore_prelude_IntG_core_vec_Vec_core_prelude_Int_core_prelude_Int(struct core_vec_Vec_core_prelude_Int core_vec_v, int64_t core_vec_i) {
return (*(core_pointer_plusexclGcore_prelude_IntG_core_pointer_Ptr_core_prelude_Int_core_prelude_Int(core_vec_v.data, ((core_vec_i * sizeof(int64_t))))));
}
int64_t c_dfsGG_core_prelude_Int_core_vec_Vec_core_prelude_Bool(int64_t c_v, struct core_vec_Vec_core_prelude_Bool c_check) {
if (core_vec_getGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int(c_check, c_v)) {
return 0;
} else {}int64_t c_ans = 0;
struct core_vec_Vec_core_prelude_Bool c_c = core_vec_copyGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(c_check);
core_vec_setGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Int_core_prelude_Bool(&c_c, c_v, core_prelude_true);
if (c_is_routeGG_core_vec_Vec_core_prelude_Bool(c_c)) {
{};
;
(c_ans += 1);
} else {}{
int64_t c_i = 0;
while ((c_i <= (core_vec_lengthGcore_prelude_IntG_core_vec_Vec_core_prelude_Int(((c_g).data[c_v])) - 1))) {
{};
;
(c_ans += c_dfsGG_core_prelude_Int_core_vec_Vec_core_prelude_Bool(core_vec_getGcore_prelude_IntG_core_vec_Vec_core_prelude_Int_core_prelude_Int(((c_g).data[c_v]), c_i), c_c));
;
(c_i += 1);
};

}
;
;
;
return c_ans;
}
int64_t* core_pointer_allocGcore_prelude_IntG_core_prelude_Int(int64_t core_pointer_len) {
return ((int64_t*)(malloc((sizeof(int64_t) * core_pointer_len))));
}
struct core_vec_Vec_core_prelude_Int core_vec_vecGcore_prelude_IntG_core_prelude_Int_core_prelude_Int(int64_t core_vec_len, int64_t core_vec_cap) {
struct core_vec_Vec_core_prelude_Int core_vec_v = (struct core_vec_Vec_core_prelude_Int){core_pointer_allocGcore_prelude_IntG_core_prelude_Int(core_vec_cap), core_pointer_allocGcore_prelude_BoolG_core_prelude_Int(core_vec_cap), core_vec_cap, core_vec_len};
{
int64_t core_vec_i = 0;
while ((core_vec_i <= (core_vec_cap - 1))) {
(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v.isinit, (core_vec_i * sizeof(bool))))) = core_prelude_false;
;
(core_vec_i += 1);
};

}
;
;
;
return core_vec_v;
}
struct core_vec_Vec_core_prelude_Int core_vec_vecGcore_prelude_IntG_() {
return core_vec_vecGcore_prelude_IntG_core_prelude_Int_core_prelude_Int(0, 8);
}
int64_t* core_pointer_reallocGcore_prelude_IntG_core_pointer_Ptr_core_prelude_Int_core_prelude_Int(int64_t* core_pointer_ptr, int64_t core_pointer_len) {
return ((int64_t*)(realloc(((void*)(core_pointer_ptr)), (sizeof(int64_t) * core_pointer_len))));
}
void core_vec_extendGcore_prelude_IntG_core_vec_Vec_core_prelude_Int(struct core_vec_Vec_core_prelude_Int* core_vec_v) {
core_vec_v->data = core_pointer_reallocGcore_prelude_IntG_core_pointer_Ptr_core_prelude_Int_core_prelude_Int(core_vec_v->data, (core_vec_v->cap * 2));
core_vec_v->isinit = core_pointer_reallocGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, (core_vec_v->cap * 2));
{
int64_t core_vec_i = core_vec_v->cap;
while ((core_vec_i <= ((core_vec_v->cap * 2) - 1))) {
(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, (core_vec_i * sizeof(bool))))) = core_prelude_false;
;
(core_vec_i += 1);
};

}
;
;
;
core_vec_v->cap = (core_vec_v->cap * 2);
}
void core_vec_pushGcore_prelude_IntG_core_vec_Vec_core_prelude_Int_core_prelude_Int(struct core_vec_Vec_core_prelude_Int* core_vec_v, int64_t core_vec_value) {
if ((core_vec_v->cap < (core_vec_v->len + 1))) {
core_vec_extendGcore_prelude_IntG_core_vec_Vec_core_prelude_Int(core_vec_v);
} else {}if ((*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, ((core_vec_v->len * sizeof(bool))))))) {
c_destructGG_core_prelude_Int((*(core_pointer_plusexclGcore_prelude_IntG_core_pointer_Ptr_core_prelude_Int_core_prelude_Int(core_vec_v->data, ((core_vec_v->len * sizeof(int64_t)))))));
} else {}(*(core_pointer_plusexclGcore_prelude_IntG_core_pointer_Ptr_core_prelude_Int_core_prelude_Int(core_vec_v->data, ((core_vec_v->len * sizeof(int64_t)))))) = core_vec_value;
(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, ((core_vec_v->len * sizeof(bool)))))) = core_prelude_true;
(core_vec_v->len += 1);
}
struct core_vec_Vec_core_prelude_Bool core_vec_vecGcore_prelude_BoolG_() {
return core_vec_vecGcore_prelude_BoolG_core_prelude_Int_core_prelude_Int(0, 8);
}
void core_vec_extendGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool* core_vec_v) {
core_vec_v->data = core_pointer_reallocGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->data, (core_vec_v->cap * 2));
core_vec_v->isinit = core_pointer_reallocGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, (core_vec_v->cap * 2));
{
int64_t core_vec_i = core_vec_v->cap;
while ((core_vec_i <= ((core_vec_v->cap * 2) - 1))) {
(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, (core_vec_i * sizeof(bool))))) = core_prelude_false;
;
(core_vec_i += 1);
};

}
;
;
;
core_vec_v->cap = (core_vec_v->cap * 2);
}
void core_vec_pushGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Bool(struct core_vec_Vec_core_prelude_Bool* core_vec_v, bool core_vec_value) {
if ((core_vec_v->cap < (core_vec_v->len + 1))) {
core_vec_extendGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool(core_vec_v);
} else {}if ((*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, ((core_vec_v->len * sizeof(bool))))))) {
c_destructGG_core_prelude_Bool((*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->data, ((core_vec_v->len * sizeof(bool)))))));
} else {}(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->data, ((core_vec_v->len * sizeof(bool)))))) = core_vec_value;
(*(core_pointer_plusexclGcore_prelude_BoolG_core_pointer_Ptr_core_prelude_Bool_core_prelude_Int(core_vec_v->isinit, ((core_vec_v->len * sizeof(bool)))))) = core_prelude_true;
(core_vec_v->len += 1);
}
void c_mainGG_() {
int64_t c_n = procon_read_intGG_();
int64_t c_m = procon_read_intGG_();
{
int64_t c_i = 0;
while ((c_i <= (c_n - 1))) {
(&c_g)->data[c_i] = core_vec_vecGcore_prelude_IntG_();
;
(c_i += 1);
};

}
;
;
;
{
int64_t c_i = 0;
while ((c_i <= (c_m - 1))) {
int64_t c_s = procon_read_intGG_();
int64_t c_t = procon_read_intGG_();
core_vec_pushGcore_prelude_IntG_core_vec_Vec_core_prelude_Int_core_prelude_Int((&((&c_g)->data[(c_s - 1)])), (c_t - 1));
core_vec_pushGcore_prelude_IntG_core_vec_Vec_core_prelude_Int_core_prelude_Int((&((&c_g)->data[(c_t - 1)])), (c_s - 1));
;
(c_i += 1);
};

}
;
;
;
struct core_vec_Vec_core_prelude_Bool c_check = core_vec_vecGcore_prelude_BoolG_();
{
int64_t c_i = 0;
while ((c_i <= (c_n - 1))) {
core_vec_pushGcore_prelude_BoolG_core_vec_Vec_core_prelude_Bool_core_prelude_Bool(&c_check, core_prelude_false);
;
(c_i += 1);
};

}
;
;
;
printf("%lld", c_dfsGG_core_prelude_Int_core_vec_Vec_core_prelude_Bool(0, c_check));
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
core_pointer_null = core_pointer_nullGG_();
core_math_M_PI = M_PI;
core_string_cr = core_string_charGG_core_prelude_Int(13);
core_string_lf = core_string_charGG_core_prelude_Int(10);
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
core_definitions_is_release = core_definitions_is_release_fnGG_();
core_definitions_is_debug = core_definitions_is_debug_fnGG_();
c_mainGG_();
}
int main(int argc, char** argv) { flori_main(); } ./Main.c: In function ‘c_mainGG_’:
./Main.c:462:8: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int64_t {aka long int}’ [-Wformat=]
 printf("%lld", c_dfsGG_core_prelude_Int_core_vec_Vec_core_prelude_Bool(0, c_check));
        ^
./Main.c: In function ‘procon_read_intGG_’:
./Main.c:232:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%" PRId64, &procon_ret);
 ^