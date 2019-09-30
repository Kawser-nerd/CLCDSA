using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;


class Ph
{
    static void Main()
    {
        var hw = Console.ReadLine().Split().Select(int.Parse).ToList();
        var c = Enumerable.Repeat(0, hw[0]).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToList()).ToList();
        var ruiseki = Enumerable.Repeat(0, hw[0] + 1).Select(_ => new int[hw[1] + 1]).ToArray();
        for (int i = 0; i < hw[0]; i++)
        {
            int sum = 0;
            for (int j = 0; j < hw[1]; j++)
            {
                if((i + j) % 2 == 0) sum += c[i][j];
                else sum -= c[i][j];
                ruiseki[i + 1][j + 1] = ruiseki[i][j + 1] + sum;
            }
        }

        int max = 0;
        for (int i = 0; i < hw[0]; i++)
        {
            for (int j = i + 1; j < hw[0] + 1; j++)
            {
                int w = j - i;
                Dictionary<int, int> dict = new Dictionary<int, int>();
                for (int k = 0; k < hw[1] + 1; k++)
                {
                    var area = ruiseki[j][k] - ruiseki[i][k];
                    if (dict.ContainsKey(area))
                    {
                        int h = k - dict[area];
                        max = Max(max, h * w);
                    }
                    if (!dict.ContainsKey(area)) dict.Add(area, k);
                }
            }
        }
        Console.WriteLine(max);
    }
}