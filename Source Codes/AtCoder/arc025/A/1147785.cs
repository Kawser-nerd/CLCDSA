using System;
using System.Linq;
class A{
static void Main()
{
int [,]a=new int[7,2];
for(
int i=0;i<2;i++){
int []g=Console.ReadLine().Split().Select(int.Parse).ToArray();
for(int k=0;k<7;k++){a[k,i]=g[k];}}
int ans=0;
for(int i=0;i<7;i++){
if(a[i,1]>a[i,0]){ans+=a[i,1];}
else{ans+=a[i,0];}
}
Console.WriteLine(ans);
}}