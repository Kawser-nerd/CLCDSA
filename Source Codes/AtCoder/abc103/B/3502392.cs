using System;
using System.Linq;

class prog{
  static void Main(){
    
    string S = Console.ReadLine();
    string T = Console.ReadLine();
    
    S += S;
    Console.WriteLine(S.Contains(T) ??"Yes" : "No");
    
  }
}