using System;
class A{static void Main()
{
string a=Console.ReadLine();
string str=Console.ReadLine();
for(int i=0;i<str.Length;i++){if(str.Substring(i,1)==a){}else{Console.Write(str.Substring(i,1));}}Console.WriteLine();Console.ReadLine();

}}