#include <stdio.h>

long long r,c,m, i,j, k,l,m,n, tt, t;
char s[100][100];

void vypis() {
 
  for(i=0;i<r;i++) printf("%s\n", s[i]);

return;
}


int vypis_2() {
long long ii, jj;

for(i=2;i<=r;i++)
 for(j=2;j<=c;j++)
   if(2*i+2*j-4 <= m && i*j >= m) {  
//     printf("%lld %lld\n",i,j);
   
     for(ii=0;ii<r;ii++) s[ii][c] = 0;
   
     for(ii=0;ii<r;ii++)
      for(jj=0;jj<c;jj++) s[ii][jj] = '*';
     
     for(ii=0;ii<i;ii++) s[ii][0] = s[ii][1] = '.';
     for(jj=0;jj<j;jj++) s[0][jj] = s[1][jj] = '.';
     
     m -= 2*i + 2*j - 4;
     
     for(ii = 2; ii < i; ii++)
       for(jj= 2; jj < j; jj++)
         if(m) {s[ii][jj] = '.'; m--;}
     
     
     s[0][0] = 'c';
     vypis();
     
     return 1;
   }


return 0;
}

void vypis_r() {


s[0][c] = 0;
for(i=0;i<c;i++) s[0][i] = '*';
for(i=0;i<m;i++) s[0][i] = '.';
s[0][0] = 'c';

vypis();
return;
}

void vypis_c() {

for(i=0;i<r;i++) s[i][1] = 0;
for(i=0;i<r;i++) s[i][0] = '*';
for(i=0;i<m;i++) s[i][0] = '.';
s[0][0] = 'c';

vypis();
return;
}



void vypis_1() {

for(i=0;i<r;i++)
 {
 s[i][c] = 0;
 for(j=0;j<c;j++) 
   s[i][j] = '*';  
 }

s[0][0] = 'c';

vypis();
return;
} 

int main() {

scanf("%lld",&t);

for(tt=1;tt<=t;tt++) {
  printf("Case #%lld:\n",tt);
  
  scanf("%lld %lld %lld", &r, &c, &m);

//  printf("%lld %lld %lld\n",r,c,m);

  m = r*c-m;

//printf("m = %lld\n",m);


  if(m == 1)  {vypis_1(); continue;}

  if(r == 1) {vypis_r(); continue;}

  if(c == 1) {vypis_c(); continue;}
  
  if(!vypis_2()) printf("Impossible\n");
}

return 0;
}