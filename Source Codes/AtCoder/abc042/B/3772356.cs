using System;

class Program
{
  static void Main(string[] args)
  {
    string[] str = Console.ReadLine().Split(' ');
    int n = int.Parse(str[0]);

    string[] s = new string[n];
    for (int i=0; i<n; i++) {
      s[i] = Console.ReadLine();
    }

    Array.Sort(s);
    string ret = "";
    for (int i=0; i<n; i++) {
      ret += s[i];
    }
    Console.WriteLine(ret);
  }
}