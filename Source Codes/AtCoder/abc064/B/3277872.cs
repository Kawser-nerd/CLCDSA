using System;

namespace ABC064B
{
  class Program
  {
    static void Main(string[] args)
    {
      int N = int.Parse(Console.ReadLine());
      string[] bufs = Console.ReadLine().Split(' ');

      int max = -1;
      int min = 0x30303030;

      for (int i = 0; i < N; i++) {
        int pos = int.Parse(bufs[i]);
        if (max < pos) {
          max = pos;
        }
        if (min > pos) {
          min = pos;
        }
      }


      Console.WriteLine(max - min);
    }
  }
}