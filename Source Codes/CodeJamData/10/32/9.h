#ifndef _common_
#define _common_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <netdb.h>
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdarg.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <malloc.h>
#include <regex.h>
#include <libgen.h>
#include <time.h>
#include <utime.h>
#include <setjmp.h>
#include <ucontext.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define FALSE 0
#define TRUE 1
#define UNDEF -1
#define SUCCESS 0
#define FAILURE 1

#define PIPE_OUT 0
#define PIPE_IN 1

#define PI 3.14159265358979323846264338327950288
#define E 2.71828182845904523536028747135266249
#define EPS6 1e-6
#define EPS12 1e-12
#define FNAME_SIZE 256
#define PAGESIZE 4096

#define SYS_MRAND_A 645
#define SYS_MRAND_B 1234567
#define SYS_MRAND_X0 137
#define SYS_MRAND_E32 (1.0 / (1 << 16) / (1 << 16))
#define SYS_LAP_TIME_MAX 128
#define SYS_MRAND_BUF_SIZE (sizeof(uint32_t) * 521 + sizeof(int8_t) + sizeof(int32_t) * 2)
#define SYS_TIME_BUF_SIZE (SYS_LAP_TIME_MAX * sizeof(double))

#define error() print_error(__FILE__, __LINE__);
#define throw(ret) if((ret) == FALSE) return (ret)
#define catch(ret) if((ret) == FALSE) error()

extern __thread double _tls_lap_times[SYS_LAP_TIME_MAX];
extern __thread uint32_t _tls_mrand_x[521];
extern __thread int8_t _tls_mrand_init_flag;
extern __thread int32_t _tls_mrand_cur;
extern __thread int32_t _tls_mrand_cur2;

extern void* __attribute__((weak)) my_malloc_hook(int64_t size);
extern void* __attribute__((weak)) my_realloc_hook(void *old_p, int64_t size);
extern void __attribute__((weak)) my_free_hook(void *p);

void print_error(char *file, int line);
void btrace(void);
void out(char *format, ...);
void outn(char *format, ...);
void err(char *format, ...);
void errn(char *format, ...);
void* my_malloc(int64_t size);
void* my_calloc(int64_t size);
void* my_realloc(void *old_p, int64_t size);
void my_free(void *p);
double get_time(void);
void time_lap(int i);
double time_ref(int i);
double time_diff(int i);
void time_snapshot(int8_t *buf);
void time_resume(int8_t *buf);
void mrand_init(int32_t x0);
double mrand_01(void);
void mrand_snapshot(int8_t *buf);
void mrand_resume(int8_t *buf);
int32_t mrand_int(int32_t inf, int32_t sup);
void halt(double time);
int32_t my_write(int fd, void *p, int32_t size);
int32_t my_read(int fd, void *p, int32_t size);

#endif
