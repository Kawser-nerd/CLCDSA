using System;
using System.Linq;
class A
{
static void Main()
{int an=0;
int a=int.Parse(Console.ReadLine());
int []s=Console.ReadLine().Split().Select(int.Parse).ToArray();
Array.Sort(s);
for(int i=0;i<a;i++){
if(i%2==0){an+=s[a-1-i];}
}Console.WriteLine(an);
}
}