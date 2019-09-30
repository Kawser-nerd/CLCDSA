#include "common.h"

__thread double _tls_time_laps[SYS_LAP_TIME_MAX];
__thread uint32_t _tls_mrand_x[521];
__thread int8_t _tls_mrand_init_flag = FALSE;
__thread int32_t _tls_mrand_cur;
__thread int32_t _tls_mrand_cur2;

void print_error(char *file, int line)
{
  /*
  int32_t ret;
  */
  
  fprintf(stderr, "[error] %s @ %s : %d\n", strerror(errno), file, line);
  fflush(stdout);
  /*
  ret = kill(getpid(), SIGQUIT);
  if(ret < 0) exit(1);
  */
  exit(1);
  return;
}

void btrace(void)
{
  int n;
  void *buf[4096];
  
  n = backtrace(buf, 4096);
  backtrace_symbols_fd(buf, n, 1);
  return;
}

void out(char *format, ...)
{
  va_list va_arg;
  
  va_start(va_arg, format);
  vprintf(format, va_arg);
  fflush(stdout);
  va_end(va_arg);
  return;
}

void outn(char *format, ...)
{
  va_list va_arg;
  
  va_start(va_arg, format);
  vprintf(format, va_arg);
  printf("\n");
  fflush(stdout);
  va_end(va_arg);
  return;
}

void err(char *format, ...)
{
  va_list va_arg;
  
  va_start(va_arg, format);
  vfprintf(stderr, format, va_arg);
  fflush(stderr);
  va_end(va_arg);
  return;
}

void errn(char *format, ...)
{
  va_list va_arg;
  
  va_start(va_arg, format);
  vfprintf(stderr, format, va_arg);
  fprintf(stderr, "\n");
  fflush(stderr);
  va_end(va_arg);
  return;
}

void* my_malloc(int64_t size)
{
  void *p;
  
  /*p = malloc(size);*/
  
  if(my_malloc_hook)
    {
      p = my_malloc_hook(size);
    }
  else
    {
      p = calloc(size, 1);
    }
  if(p == NULL) error();
  return p;
}

void* my_calloc(int64_t size)
{
  void *p;
  
  p = calloc(size, 1);
  if(p == NULL) error();
  return p;
}

void* my_realloc(void *old_p, int64_t size)
{
  void *p;
  
  if(my_realloc_hook)
    {
      p = my_realloc_hook(old_p, size);
    }
  else
    {
      p = realloc(old_p, size);
    }
  if(p == NULL) error();
  return p;
}

void my_free(void *p)
{
  if(my_free_hook)
    {
      my_free_hook(p);
    }
  else
    {
      free(p);
    }
  return;
}

double get_time(void)
{
  struct timeval tv;
  
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

void time_lap(int i)
{
  struct timeval tv;
  
  if(!(0 <= i && i < SYS_LAP_TIME_MAX)) error();
  gettimeofday(&tv, NULL);
  _tls_time_laps[i] = tv.tv_sec + tv.tv_usec * 1e-6;
  return;
}

double time_ref(int i)
{
  if(!(0 <= i && i < SYS_LAP_TIME_MAX)) error();
  return _tls_time_laps[i];
}

double time_diff(int i)
{
  struct timeval tv;
  
  if(!(0 <= i && i < SYS_LAP_TIME_MAX)) error();
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6 - _tls_time_laps[i];
}

void time_snapshot(int8_t *buf)
{
  int32_t offset, size;
  
  offset = 0;
  size = SYS_LAP_TIME_MAX * sizeof(double);
  memcpy(buf + offset, _tls_time_laps, size);
  offset += size;
  return;
}

void time_resume(int8_t *buf)
{
  int32_t offset, size;
  
  offset = 0;
  size = SYS_LAP_TIME_MAX * sizeof(double);
  memcpy(_tls_time_laps, buf + offset, size);
  offset += size;
  return;
}

void mrand_init(int32_t x0)
{
  int32_t i;
  
  _tls_mrand_x[0] = SYS_MRAND_A * x0;
  for(i = 1; i < 521; i++)
    {
      _tls_mrand_x[i] = SYS_MRAND_A * _tls_mrand_x[i - 1] + SYS_MRAND_B;
    }
  _tls_mrand_init_flag = TRUE;
  _tls_mrand_cur = 0;
  _tls_mrand_cur2 = 521;
  return;
}

double mrand_01(void)
{
  int32_t i;
  double d;
  
  if(_tls_mrand_init_flag == FALSE)
    {
      _tls_mrand_x[0] = SYS_MRAND_A * SYS_MRAND_X0;
      for(i = 1; i < 521; i++)
        {
          _tls_mrand_x[i] = SYS_MRAND_A * _tls_mrand_x[i - 1];
        }
      _tls_mrand_init_flag = TRUE;
      _tls_mrand_cur = 0;
      _tls_mrand_cur2 = 521;
    }
  
  _tls_mrand_x[_tls_mrand_cur] = _tls_mrand_x[_tls_mrand_cur] ^ _tls_mrand_x[_tls_mrand_cur2 - 32];
  d = _tls_mrand_x[_tls_mrand_cur] * SYS_MRAND_E32;
  _tls_mrand_cur++;
  _tls_mrand_cur2++;
  if(_tls_mrand_cur == 521)
    {
      _tls_mrand_cur = 0;
    }
  if(_tls_mrand_cur2 == 553)
    {
      _tls_mrand_cur2 = 32;
    }
  return d;
}

int32_t mrand_int(int32_t inf, int32_t sup)
{
  return inf + (int32_t)(mrand_01() * (sup - inf + 1));
}

void mrand_snapshot(int8_t *buf)
{
  int32_t offset, size;
  
  offset = 0;
  size = sizeof(int8_t);
  memcpy(buf + offset, &_tls_mrand_init_flag, size);
  offset += size;
  size = sizeof(int32_t);
  memcpy(buf + offset, &_tls_mrand_cur, size);
  offset += size;
  size = sizeof(int32_t);
  memcpy(buf + offset, &_tls_mrand_cur2, size);
  offset += size;
  size = 521 * sizeof(uint32_t);
  memcpy(buf + offset, _tls_mrand_x, size);
  offset += size;
  return;
}

void mrand_resume(int8_t *buf)
{
  int32_t offset, size;
  
  offset = 0;
  size = sizeof(int8_t);
  memcpy(&_tls_mrand_init_flag, buf + offset, size);
  offset += size;
  size = sizeof(int32_t);
  memcpy(&_tls_mrand_cur, buf + offset, size);
  offset += size;
  size = sizeof(int32_t);
  memcpy(&_tls_mrand_cur2, buf + offset, size);
  offset += size;
  size = 521 * sizeof(uint32_t);
  memcpy(_tls_mrand_x, buf + offset, size);
  offset += size;
  return;
}

void halt(double time)
{
  struct timespec spec;
  
  spec.tv_sec = (int)time;
  spec.tv_nsec = (int)((time - (int)time) * 1e9);
  nanosleep(&spec, NULL);
  return;
}

int32_t my_write(int fd, void *p, int32_t size)
{
  int32_t ret;
  
  ret = write(fd, (int8_t*)p, size);
  if(ret != size) return -1;
  if(ret < 0) return ret;
  return ret;
}

int32_t my_read(int fd, void *p, int32_t size)
{
  int32_t sum, ret;
  int8_t *tmp_p;
  
  tmp_p = (int8_t*)p;
  ret = 0;
  for(sum = 0; sum < size; sum += ret)
    {
      ret = read(fd, tmp_p + sum, size - sum);
      if(ret == 0) return ret;
      if(ret < 0) return ret;
    }
  return sum;
}
