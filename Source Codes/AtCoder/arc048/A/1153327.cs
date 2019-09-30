using System;
using System.Linq;
class A{
static void Main()
{
int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
if(a[0]<0&a[1]>0){Console.WriteLine(a[0]*-1+a[1]-1);}
else{Console.WriteLine(a[1]-a[0]);}
}
}