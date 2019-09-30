#include<stdio.h>
int Prime[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,-1};
int Isprime( int n )
{
 int i ;
 for( i = 0 ; Prime[i] != -1 ; i++ )
 {
  if( Prime[i] == n )
   return 1 ;
 }
 return 0 ;
}
int main()
{
 int r ;
 int r1  = 0 ;
 scanf("%d",&r);
 while( r > 0 )
 {
  r--;
  r1++;
 int i ;
 int count = 0 ;
 int n ;
 scanf("%d",&n);
 int k = pow( 2 , n - 2 ) ; 
 int k1 ;
 int rank ;
 int j ;
 int s1[ 100 ] ;
 for( i = 1 ; i < k ; i++ )
 {
  k1 = 0 ;
  for( j = 0 ; j < n - 2 ; j++ )
  {
   if( ( i >> j ) & 1  == 1 )
   {
//    printf("%d",i>>j&1);
    s1[k1] = j + 2 ;
    k1++;
   }
   else
   {
//    printf("0");
   }
  }
//  printf("\n");
  s1[k1] = n ;
  k1++;
 
  rank = k1 ;

  while( ( rank != 1 ) )
  {
   for( j = 0 ; j < k1 ; j++ )
   {
    if( s1[j] == rank )
    {
     rank = j + 1 ;
     break;
    }
   }
   if( j == k1 )
   {
    break;
   }
  }

  if( rank == 1 )
  {
   count++;
  }
 }
 if( n == 1 )
 {
  printf("Case #%d: 1\n",r1);
 }
 else
 {
  count = count + 1 ;
  printf("Case #%d: %d\n",r1,count%100003);
 }
} 
}
