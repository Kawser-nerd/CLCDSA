typedef long unsigned int size_t;
extern int printf (const char *__restrict __format, ...);
extern int scanf (const char *__restrict __format, ...) ;
extern int getchar (void);
extern int putchar (int __c);
int nextInt(){int f=0;char s=0;char c=getchar();while((c<48)||(57<c)){if(c==45){s=1;c=getchar();break;}c=getchar();}while((48<=c)&&(c<=57)){f=f*10+(c-48);c=getchar();}return s?-f:f;}
char nextChar(){char f=0;char s=0;char c=getchar();while((c<48)||(57<c)){if(c==45){s=1;c=getchar();break;}c=getchar();}while((48<=c)&&(c<=57)){f=f*10+(c-48);c=getchar();}return s?-f:f;}
short int nextShort(){short f=0;char s=0;char c=getchar();while((c<48)||(57<c)){if(c==45){s=1;c=getchar();break;}c=getchar();}while((48<=c)&&(c<=57)){f=f*10+(c-48);c=getchar();}return s?-f:f;}
long long int nextLong(){long long int f=0;char s=0;char c=getchar();while((c<48)||(57<c)){if(c==45){s=1;c=getchar();break;}c=getchar();}while((48<=c)&&(c<=57)){f=f*10+(c-48);c=getchar();}return s?-f:f;}
void println(){putchar(10);}
void print(char *f){while(*f){putchar(*f);f++;}}
void printInt(int f){char c[10];if(!f){putchar(48);return;}if(f<0){f=-f;putchar(45);}char i=0;while(f){c[++i]=(f%10)+48;f/=10;}while(i){putchar(c[i--]);}}
void printLong(long long int f){char c[19];if(!f){putchar(48);return;}if(f<0){f=-f;putchar(45);}char i=0;while(f){c[++i]=(f%10)+48;f/=10;}while(i){putchar(c[i--]);}}
typedef int (*__compar_fn_t) (const void *, const void *);
extern void *bsearch (const void *__key, const void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar)__attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
int compare_int(const void *a, const void *b){return *(int*)a - *(int*)b;}
int compare_char(const void *a, const void *b){return *(char*)a - *(char*)b;}
int compare_short(const void *a, const void *b){return *(short*)a - *(short*)b;}
int compare_long(const void *a, const void *b){if(*(long long int*)a - *(long long int*)b < 0){return -1;}else if(*(long long int*)a - *(long long int*)b > 0){return 1;}else{return 0;}}
extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));
long long int x, t;
int main(){
 x = nextInt();
 t = (sqrt(x*8+1)-1)/2;
 if(t*(t+1)/2 >= x){
  printInt(t);
 }else{
  printInt(t+1);
 }
 println();
}