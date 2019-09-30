using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{

    static void Main()
    {
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[][] a = Enumerable.Repeat(0, hw[0]).Select(_ => Console.ReadLine().Select(x => x - '0').ToArray()).ToArray();
        int[][] b = Enumerable.Repeat(0, hw[0]).Select(_ => new int[hw[1]]).ToArray();
        for (int i = 0; i < a.Length; i++)
        {
            for (int j = 0; j < a[i].Length; j++)
            {
                while (a[i][j] > 0)
                {
                    a[i][j]--;
                    a[i + 2][j]--;
                    a[i + 1][j + 1]--;
                    a[i + 1][j - 1]--;

                    b[i + 1][j]++;

                    Debug.WriteLine(string.Join("\n", a.Select(x => string.Join("", x)).ToArray()));
                }
            }
        }
        Console.WriteLine(string.Join("\n",b.Select(x => string.Join("",x)).ToArray()));
    }
}