using System;
using System.Linq;

class prog{
  static void Main(){
   string S = Console.ReadLine();
    for(int i = 0; i < S.Length; i += 2){
      Console.Write(S[i]);
    }
  }
}