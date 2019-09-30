using System;
using System.Collections.Generic;
class Program
{
  static void Main(string[] args)
  {
    string[] s = Console.ReadLine().Split(' ');
    int N = int.Parse(s[0]);
    int K = int.Parse(s[1]);
    List<int> T = new List<int>();
    for (int i = 0; i < N; i++) { T.Add(int.Parse(Console.ReadLine())); }
    T.Sort();
    List<int> D = new List<int>();
    for (int i = 0; i <= N - K; i++) { D.Add(T[i + K - 1] - T[i]); }
    D.Sort();
    Console.WriteLine(D[0].ToString());
  }
}