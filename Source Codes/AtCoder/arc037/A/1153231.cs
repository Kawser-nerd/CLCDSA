using System;using System.Linq;
class A{
static void Main()
{int ans=0;
int a=int.Parse(Console.ReadLine());
int []s=Console.ReadLine().Split().Select(Int32.Parse).ToArray();
for(int i=0;i<a;i++){
if(s[i]<80){ans+=80-s[i];}
}Console.WriteLine(ans);
}
}