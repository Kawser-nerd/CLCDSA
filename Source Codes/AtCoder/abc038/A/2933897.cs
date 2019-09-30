using System;

class Program
{
  static void Main(string[] args)
  {
    string s = Console.ReadLine();
    
    if(s[s.Length - 1] == 'T') Console.WriteLine("YES");
    else Console.WriteLine("NO");
  }
}