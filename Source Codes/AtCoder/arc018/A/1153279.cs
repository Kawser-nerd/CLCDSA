using System;
using System.Linq;class A{
static void Main()
{
double[]a=Console.ReadLine().Split().Select(double.Parse).ToArray();
Console.WriteLine((double)a[0]/(double)100*(double)a[0]/(double)100*(double)a[1]);
}
}