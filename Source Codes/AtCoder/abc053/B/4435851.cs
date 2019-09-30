using System;

class Program
{
  static void Main()
  {
    var str = Console.ReadLine();
    var l = str.Length;
    var a = 0;
    var z = l;
    for (int i=0; i<l; i++)
    {
      if (str[i]=='A') { a=i; break;}
    }
    for (int j=l-1; j>0; j--)
    {
      if (str[j]=='Z') { z=j; break;}
    }
    Console.WriteLine(z-a+1);
  }
}