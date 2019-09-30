using System;
using System.Linq;
class A{
static void Main()
{
int []s=Console.ReadLine().Split().Select(int.Parse).ToArray();
int a=s[0];
int b=s[1];
if(a<0){a*=-1;}
if(b<0){b*=-1;}
if(a<b){Console.WriteLine("Ant");}
else if(a==b){Console.WriteLine("Draw");}
else{Console.WriteLine("Bug");}
}
}