using System;
using System.Linq;
 
class Program {
  static void Main() {
    string s = Console.ReadLine();
    string ans = "";
    foreach (var t in s){
      if(t == '0'||t == '1') ans += t;
      else {
        if(ans == "") continue;
        else ans = ans.Substring(0, ans.Length - 1);
      }
    }
    Console.WriteLine(ans);
  }
}