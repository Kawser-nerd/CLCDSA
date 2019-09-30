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
int min(int a, int b){return a>b?b:a;}
int d, i;
int g, p[11], c[11];
int n, a;
int ans;
int s1, need;
int main(){
 d=nextInt();
 g=nextInt();
 for(i = 0; i < d; ++i){
  p[i]=nextInt();
  c[i]=nextInt();
 }
 ans = 1e9;
 n = 1<<d;
 for(a=0; a<n; a++){
  int s = 0, num = 0, rest_max = -1;
  for(i=0; i<d; i++){
   if(a>>i&1){
    s += 100 * (i+1) * p[i] + c[i];
    num += p[i];
   }else{
    rest_max = i;
   }
  }
  if(s<g){
   s1 = 100 * (rest_max + 1);
   need = (g - s + s1 - 1) / s1;
   if(need >= p[rest_max]){
    continue;
   }
   num += need;
  }
  ans = min(ans, num);
 }
 printInt(ans);
 println();
}