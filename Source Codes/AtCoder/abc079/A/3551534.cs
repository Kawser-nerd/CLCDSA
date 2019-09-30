using System;
using System.Linq;

class prog{
  static void Main(){
    string s = Console.ReadLine();
    Console.WriteLine((s[0] == s[1]&&s[1] == s[2])||(s[1] == s[2]&&s[2] == s[3]) ? "Yes" : "No");
  }
}