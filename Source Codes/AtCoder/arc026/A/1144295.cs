using System;
using System.Linq;
class A{
static void Main()
{
int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
if(a[0]<=5){Console.WriteLine(a[0]*a[2]);}
else{ Console.WriteLine(a[2]*5+(a[0]-5)*a[1]);}
}
}