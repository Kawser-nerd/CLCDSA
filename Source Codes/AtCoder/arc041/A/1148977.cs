using System;
using System.Linq;
class A{
static void Main()
{
int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
int s=int.Parse(Console.ReadLine());
if(a[1]>=s){Console.WriteLine(s+a[0]);}
else {
Console.WriteLine(a[1]+a[0]-(s-a[1]));
}
}
}