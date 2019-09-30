using System;
using System.Linq;

class prog{
  static void Main(){
    
    string S = Console.ReadLine();
    string T = Console.ReadLine();
    bool judge = false;
    
    for(int i = 0; i < S.Length; i++){
      if(S == T) judge = true;
      S = S.Substring(S.Length - 1) + S.Substring(0,S.Length - 1);
    }
    
    Console.WriteLine(judge ? "Yes" : "No");
    
  }
}