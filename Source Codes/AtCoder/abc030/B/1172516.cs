using System;
using System.Linq;
class A{
static  void Main()
{
double []a=Console.ReadLine().Split().Select(double.Parse).ToArray();
double s=(a[0]%12)*30-a[1]*5.5;
if(s<0){s*=-1;}
if(s>180){s=360-s;}
Console.WriteLine(s);
}
}