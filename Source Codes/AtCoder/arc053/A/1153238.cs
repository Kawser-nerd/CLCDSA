using System;
using System.Linq;
class A{
static void Main()

{
int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
Console.WriteLine((a[0]-1)*a[1]+(a[1]-1)*a[0]);
}
}