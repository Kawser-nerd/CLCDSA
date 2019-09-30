#include<stdio.h>
 
int main(void){
 
void Swap(long long int x[ ], long long int i,long long int j)
{
    long long int temp;
 
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}
 
void QSort(long long int x[ ], long long int left, long long int right)
{
    long long int i, j;
    long long int pivot;
 
    i = left;                      
    j = right;                    
 
 pivot = x[(left + right) / 2]; 
 
    while (1) {                    
 
        while (x[i] < pivot)       
            i++;                   
 
        while (pivot < x[j])      
            j--;                  
        if (i >= j)               
            break;                 
 
        Swap(x, i, j);             
        i++;                    
        j--;
    }
 
 
    if (left < i - 1)            
        QSort(x, left, i - 1);   
    if (j + 1 <  right)         
        QSort(x, j + 1, right);  
}
 
long long int a,n,z[200001],p = 0,c = 0;
 
scanf("%ld",&n);
 
z[0] = 0;
for(long long int i = 0; i < n; i++){
scanf("%ld",&a);
z[i+1] = z[i] + a;
if(z[i+1] == 0) p++;
}
 
QSort(z,1,n);
for(long long int i = 1; i < n; i++){
c = 0;
for(long long int j = i+1; j < n+1; j++){
if(z[i] == z[j]) c++;
else break;
}
i += c;
p += c*(c+1)/2;
}
printf("%ld",p);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:7: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
 scanf("%ld",&n);
       ^
./Main.c:52:7: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
 scanf("%ld",&a);
       ^
./Main.c:67:8: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
 printf("%ld",p);
        ^
./Main.c:48:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%ld",&n);
 ^
./Main.c:52:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%ld",&a);
 ^