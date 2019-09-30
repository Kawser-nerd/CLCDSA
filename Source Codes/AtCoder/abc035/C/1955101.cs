using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NQ = Console.ReadLine().Split().Select(int.Parse).ToArray();
        bool[] map = new bool[NQ[0] + 1];
        for (int i = 0; i < NQ[1]; i++)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            map[a[0] - 1] = !map[a[0] - 1];
            map[a[1]] = !map[a[1]];
        }
      System.Text.StringBuilder sb = new System.Text.StringBuilder();

        int sum = 0;
        for (int i = 0; i < NQ[0]; i++)
        {
            sum += (map[i] ? 1 : 0);
            sb.Append(sum % 2);
        }
        Console.WriteLine(sb.ToString());
    }
}