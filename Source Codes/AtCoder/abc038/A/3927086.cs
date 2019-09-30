using System;
using System.Linq;

class P{
  static void Main(){
    string S = Console.ReadLine();
    Console.WriteLine(S[S.Length - 1] == 'T' ? "YES" : "NO");
  }
}