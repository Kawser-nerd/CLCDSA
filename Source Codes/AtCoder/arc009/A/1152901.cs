using System;
using System.Linq;
class A{
static void Main()
{
int d=int.Parse(Console.ReadLine());int ans=0;
for(int i=0;i<d;i++){int []a=Console.ReadLine().Split().Select(Int32.Parse).ToArray();ans+=a[1]*a[0];}
 
double s=(double)ans*1.05;
//double f=s%(double)1;
Console.WriteLine((int)s/1);
}
}