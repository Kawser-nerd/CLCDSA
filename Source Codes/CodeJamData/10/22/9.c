#include<stdio.h>
int main()
{
 int p ;
 int p1= 0 ;
 scanf("%d",&p);
 while( p > 0 )
 {
  p1++;
  p--;
 int n ;
 int i ;
 int j ;
 int k ;
 int b; 
 int t ;
 int count = 0 ;
 int swap = 0 ;
 int x[ 100 ] ;
 int v[ 100 ] ; 
 int flag[ 100 ] ;
 scanf( "%d %d %d %d", &n , &k , &b , &t ) ;
 for( i = 0 ; i < n ; i++ )
 {
  flag[i] = 0 ;
  scanf("%d",&x[i]);
 }
 for( i = 0 ; i < n ; i++ )
 {
  scanf("%d",&v[i]);
 }
 for( i = 0 ; i < n ; i++ )
 {
  if( x[i] + v[i] * t >= b )
  {
   //printf("%d\n",i);
   flag[i] = 1 ;
  }
 }

 for( i = n - 1 ; i >= 0 && count != k ; i-- ) 
 {  
  if( flag [i] == 1 )
  { 
   count ++ ;
   for( j = i + 1 ; j < n ; j++ )
   {
  //  printf("%d %d\n",i,j);
    if( flag[j] == 0 )
    {
     swap++; 
    }
   }
  }

 }
 printf("Case #%d: ",p1);
 if( count == k )
 {
  printf("%d\n",swap);
 }
 else
 {
  printf("IMPOSSIBLE\n");
 }
 }
}
