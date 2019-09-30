using System;
using System.Linq;

class prog{
  static void Main(){
    string s = Console.ReadLine();
    string t = s.Substring(0, 1) + (s.Length - 2).ToString() + s.Substring(s.Length - 1);
    Console.WriteLine(t);
  }
}