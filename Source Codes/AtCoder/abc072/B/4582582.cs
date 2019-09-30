using System;
using System.Linq;
public class s
{
  public static void Main()
  {
    string s=Console.ReadLine();
    string ans="";
    for(int i=0;i<s.Length;i++)
    {
      if(i%2==0)ans+=s[i];
    }
    Console.WriteLine(ans);
  }
}