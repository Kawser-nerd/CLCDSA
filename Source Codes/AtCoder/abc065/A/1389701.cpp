#include<iostream>
#include<stdio.h>
using namespace std;
int main ( )
{
int x,a,b;
scanf("%d%d%d",&x,&a,&b);
if(-a+b<=0)cout<<"delicious\n";
else if (-a + b <= x ) printf ( "safe\n") ;
else printf ( "dangerous \n" ) ;
}