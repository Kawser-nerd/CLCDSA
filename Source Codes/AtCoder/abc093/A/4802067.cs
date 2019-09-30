using System;
public class c
{
  public static void Main()
  {
    string s=Console.ReadLine();
    if(s=="abc"||s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba")Console.WriteLine("Yes");
    else Console.WriteLine("No");
  }
}