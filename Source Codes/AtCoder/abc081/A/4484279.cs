using System;
public class c
{
  public static void Main()
  {
    string s=Console.ReadLine();
    string s_1="";
    s_1=s.Replace("1", "");
    Console.WriteLine(s.Length-s_1.Length);
  }
}