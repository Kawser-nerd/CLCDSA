using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nc = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<int[]>[] channel = Enumerable.Repeat(0,nc[1]).Select(_ => new List<int[]>()).ToArray();
        for (int i = 0; i < nc[0]; i++)
        {
            int[] stc = Console.ReadLine().Split().Select(int.Parse).ToArray();
            channel[stc[2] - 1].Add(new int[] { stc[0], stc[1] });
        }
        int[] imos = new int[100010];
        for (int i = 0; i < channel.Length; i++)
        {
            int[][] a = channel[i].OrderBy(x => x[0]).ToArray();
            int endind = 0;
            imos[0]++;
            for (int j = 0; j < a.Length; j++)
            {
                if(endind != a[j][0])
                {
                    imos[endind]--;
                    imos[a[j][0] - 1]++;
                    endind = a[j][1];
                }
                endind = a[j][1];
            }
            imos[endind]--;
        }
        int current = 0;
        int max = 0;
        for (int i = 0; i < imos.Length; i++)
        {
            current += imos[i];
            max = Math.Max(max, current);
        }
        Console.WriteLine(max);
    }
}