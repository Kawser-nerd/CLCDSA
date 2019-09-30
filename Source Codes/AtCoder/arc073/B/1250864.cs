//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Text;

public class Test
{
    public static void Main()
    {
        var line1 = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        var N = line1[0];
        var W = line1[1];
        var w = new long[N];  // weight
        var v = new long[N];  // value

        for (int i = 0; i < N; i++)
        {
            var line2 = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
            w[i] = line2[0];
            v[i] = line2[1];
        }

        var w1 = w[0];  // base weight

        // ?????????????????
        // ?????? 100^4 ?????????

        var valuesByWeight = new List<long>[4] {
            new List<long>(),
            new List<long>(),
            new List<long>(),
            new List<long>(),
        };

        for (int i = 0; i < N; i++)
        {
            valuesByWeight[w[i] - w1].Add(v[i]);
        }

        for (int j = 0; j < 4; j++)
        {
            valuesByWeight[j].Add(long.MinValue / 3);  // ??????????
            valuesByWeight[j] = valuesByWeight[j].OrderByDescending(x => x).ToList();
        }

        long maxValue = long.MinValue / 3;

        long sum0 = 0;
        for (int i0 = 0; i0 < valuesByWeight[0].Count; i0++)
        {

            long sum1 = 0;
            for (int i1 = 0; i1 < valuesByWeight[1].Count; i1++)
            {

                long sum2 = 0;
                for (int i2 = 0; i2 < valuesByWeight[2].Count; i2++)
                {

                    long sum3 = 0;
                    for (int i3 = 0; i3 < valuesByWeight[3].Count; i3++)
                    {
                        long totalWeight = i0 * w1 + i1 * (w1 + 1) + i2 * (w1 + 2) + i3 * (w1 + 3);

                        if (totalWeight <= W)
                        {
                            maxValue = Math.Max(maxValue, sum0 + sum1 + sum2 + sum3);
                        }

                        sum3 += valuesByWeight[3][i3];

                    }

                    sum2 += valuesByWeight[2][i2];
                }

                sum1 += valuesByWeight[1][i1];
            }

            sum0 += valuesByWeight[0][i0];
        }

        Console.WriteLine(maxValue);
    }
}