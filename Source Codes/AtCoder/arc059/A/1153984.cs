using System;using System.Linq;
class A{
static void Main()
{
double s=int.Parse(Console.ReadLine());
double []a=Console.ReadLine().Split().Select(double.Parse).ToArray();
double z=0;
for(int i=0;i<(int)s;i++){z+=a[i];}
double ret = Math.Round((double)z/s, MidpointRounding.AwayFromZero);
int d=(int)ret;
int ans=0;
for(int i=0;i<(int)s;i++)
{//int u=(int)a[i]-d;if(u<0){u*=-1;}
ans+=((int)a[i]-d)*((int)a[i]-d);}
Console.WriteLine(ans);
}}