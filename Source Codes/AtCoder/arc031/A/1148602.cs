using System;
class A{
static void Main()
{
string a=Console.ReadLine();
string g="";
for(int i=a.Length-1;i>=0;i--){g+=a.Substring(i,1);}
if(a==g){Console.WriteLine("YES");}
else{Console.WriteLine("NO");}
}
}