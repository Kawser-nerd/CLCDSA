using System;using System.Linq;
class A{
static void Main()
{
string s=Console.ReadLine();
int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
for(int i=0;i<s.Length;i++){
/*
????
????


??
?????
????
?????????????????

*/if(i==0&&a[0]==0){Console.Write('"');}
Console.Write(s.Substring(i,1));
if(i+1==a[0]||i==a[1]-1||i+1==a[2]||a[3]==i+1){Console.Write('"');}
}Console.WriteLine();
}}