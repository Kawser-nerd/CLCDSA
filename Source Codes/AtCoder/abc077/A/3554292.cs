using System;
using System.Linq;

class prog{
  static void Main(){
    string s1 = Console.ReadLine();
    string s2 = Console.ReadLine();
    
    Console.WriteLine(s1[0] == s2[2]&&s1[1] == s2[1]&&s1[2] == s2[0] ? "YES" : "NO");
    
  }
}