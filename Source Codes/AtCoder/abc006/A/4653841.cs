using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    string s=Console.ReadLine();
    int n=int.Parse(s);
    if(n%3==0||s=="3")Console.WriteLine("YES");
    else Console.WriteLine("NO");
  }
}