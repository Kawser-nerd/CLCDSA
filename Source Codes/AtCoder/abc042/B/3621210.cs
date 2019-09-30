using System;
using System.Linq;
 
class Program {
  static void Main()
  {    
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int N = n[0];
    string[] S = new string[N];
    for (int i = 0; i < N; i++) {
      S[i] = Console.ReadLine();
    }
    S = S.OrderBy(x => x).ToArray();
    string ans = "";
    for (int i = 0; i < N; i++) {
      ans += S[i];
    }
    Console.WriteLine(ans);   
  }
}