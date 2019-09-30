using System;
using System.Linq;
class A{
static void  Main()
{
int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
if(a[1]==a[0]){Console.WriteLine("1");}
else{Console.WriteLine(a[0]);}
}

}