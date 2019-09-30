using System;
using System.Linq;

class prog{
  static void Main(){
    
    string S = Console.ReadLine();
    string T = Console.ReadLine();
    bool flag = false;
    for(int i = 0; i < S.Length; i++){
      S = S.Substring(S.Length - 1) + S.Substring(0, S.Length - 1);
      if(S == T) flag = true;
    }
    Console.WriteLine(flag ? "Yes" : "No");
    
  }
}