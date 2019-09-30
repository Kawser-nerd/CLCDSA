using System;
using System.Linq;
class A{
static void Main()
{
double s=double.Parse(Console.ReadLine());
double []a=new double[(int)s];
for(int i=0;i<(int)s;i++)
{
double []d=Console.ReadLine().Split().Select(double.Parse).ToArray();
a[i]=d[0]+d[1]+d[2]+d[3]+(double)d[4]*110/900;
}
Array.Sort(a);
Console.WriteLine(a[(int)s-1]);
//Console.WriteLine(a[0])
//;Console.WriteLine(a[1]);
}
}