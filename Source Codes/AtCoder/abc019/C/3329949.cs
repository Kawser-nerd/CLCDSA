using System;
using System.Collections;

namespace ABC019C
{
  class Program
  {
    static void Main(string[] args)
    {
      int N = int.Parse(Console.ReadLine());
      string[] bufs = Console.ReadLine().Split(' ');

      Hashtable set = new Hashtable(N);
      for (int i = 0; i < N; i++) {
        int num = int.Parse(bufs[i]);
        while ((num & 1) == 0) {
          num >>= 1;
        }

        if (!set.Contains(num)) {
          set.Add(num, 0);
        }
      }

      Console.WriteLine(set.Count);
    }
  }
}