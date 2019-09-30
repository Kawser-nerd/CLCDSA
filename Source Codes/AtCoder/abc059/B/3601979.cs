using System;
using System.Linq;

class prog{
  static void Main(){
    
    string a = Console.ReadLine();
    string b = Console.ReadLine();
    string ans = "EQUAL";
    
    if(a.Length > b.Length) ans = "GREATER";
    else if(a.Length < b.Length) ans = "LESS";
    else{
      if(a.CompareTo(b) < 0) ans = "LESS";
      else if(a.CompareTo(b) > 0) ans = "GREATER";
    }
    
    Console.WriteLine(ans);
    
  }
}