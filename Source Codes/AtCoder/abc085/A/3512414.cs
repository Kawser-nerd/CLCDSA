using System;
using System.Linq;

class prog{
  static void Main(){
    
    string input = Console.ReadLine();
    string ans = "2018" + input.Substring(4);
    Console.WriteLine(ans);
    
  }
}