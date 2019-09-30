#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct tree 
{
 char str[ 100 ] ;
 int n ;
 struct tree *Child[ 100 ] ;
}Tree ;

int Rec( Tree * T , char *str ) 
{
 int k ;
 int i ;
 char s[ 100 ] ;
 i = 0 ;
 int flag  = 0 ;
 if( str[0] == 0 )
 {
  return 0 ;
 }
 //printf("Value to function%s\n",str);

 while( str[i] != '/' && str[i] != 0 )
 {
  i++;
 }
 if( str[i] == 0 ) 
 {
  flag = 1;
 }
 strncpy( s , str , i ) ;
 s[i] = 0 ;
 for( k = 0 ; k < T->n ; k++ )
 {
  if( strcmp ( s , T->Child[k]->str ) == 0 && flag == 0 )
  {
   return Rec( T->Child[k] , str + i + 1 ) ;
  }
  else if( strcmp ( s , T->Child[k]->str ) == 0 && flag == 1 )
  {
   return 0 ; 
  }
 }

 T->Child[ T->n ] = malloc( sizeof( Tree ) ) ;
 strcpy( T->Child[T->n]->str , s ); 
 (T->Child[T->n])->n = 0;
 T->n++; 
 if( flag == 1 )
  return 1  ;
 return Rec( T->Child[T->n-1] , str + i + 1 ) + 1 ;
}

int main()
{
 int t ; 
 int l = 0;
 scanf("%d",&t);
 while( t > 0 )
 {
  l++;
  t--;
  Tree *T =(Tree*) malloc(sizeof( Tree ) ) ;
  int count = 0 ;
  char str[ 100 ] ;
  int n ;
  int m ;
  scanf( "%d %d" , &n , &m ) ;
  int i ;
  T->str[0] = '/';
  T->str[1] = 0 ;
  T->n = 0 ;

  for( i = 0 ;i < n ; i++ )
  {
   scanf("%s",str) ;
   Rec( T , str + 1 ) ; 
  }

  count = 0 ;
  for( i = 0 ; i < m ; i++ )
  {
   str[0] = 0; 
   scanf("%s",str) ;
   count = count + Rec( T , str + 1 ) ;
//   printf("%d\n",count);
  }
  printf("Case #%d: %d\n",l,count);
 }
} 
