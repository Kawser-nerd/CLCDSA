using System;
using System.Linq;
class A{
static void Main()
{
int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
Console.WriteLine(18*60-(a[0]*60+a[1]));
}
}