using System;
class A
 
{
static void Main()
{
int a=int.Parse(Console.ReadLine());
if(a==1){Console.WriteLine("BOWWOW");}
else{int s=0;
for(int i=1;i<=a;i++)
{s+=i;}
bool flag=false;
for(int i=1;i<s/2;i++){
if(s%i==0){flag=true;break;}
}
Console.WriteLine(flag?"BOWWOW":"WANWAN");
}
}}