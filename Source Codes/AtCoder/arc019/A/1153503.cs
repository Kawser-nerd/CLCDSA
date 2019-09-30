using System;
using System.Linq;
class A{

static void Main()
{
string a=Console.ReadLine();
for(int i=0;i<a.Length;i++){
string g=a.Substring(i,1);
if(g=="Z"){Console.Write("2");}
else if(g=="B"){Console.Write("8");}
else if(g=="Z"){Console.Write("2");}
else if(g=="O"||g=="D"){Console.Write("0");}
else if(g=="I"){Console.Write("1");}
else if(g=="S"){Console.Write("5");}else{Console.Write(g);}
}
Console.WriteLine();
}}