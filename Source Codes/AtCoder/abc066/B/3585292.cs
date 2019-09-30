using System;
using System.Linq;

class prog{
  static void Main(){
    string S = Console.ReadLine();
    string T = "";
    int ans = 0;
    for(int i = S.Length - 3; i > 0; i--){
      T = S.Substring(0, i);
      if(T.Substring(0, i / 2) == T.Substring(i / 2 + 1)){
        ans = i + 1;
        break;
      }
    }
    Console.WriteLine(ans);
  }
}