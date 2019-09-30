using System;
using System.IO;
using System.Linq;
using System.Runtime;
using System.Reflection;
using System.Diagnostics;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;
using static System.Math;


class P
{
    static void Main()
    {
        int[] sg = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        long[][] pos = new long[n + 2][];
        pos[0] = new long[] { sg[0], sg[1], 0 };
        pos[pos.Length - 1] = new long[] { sg[2], sg[3], 0 };
        for (int i = 1; i < pos.Length - 1; i++)
        {
            pos[i] = Console.ReadLine().Split().Select(long.Parse).ToArray();
        }

        double[][] dist = Enumerable.Repeat(0, pos.Length).Select(_ => new double[pos.Length]).ToArray();
        for (int i = 0; i < dist.Length; i++)
        {
            for (int j = 0; j < dist.Length; j++)
            {
                var distx = Abs(pos[i][0] - pos[j][0]);
                var disty = Abs(pos[i][1] - pos[j][1]);
                dist[i][j] = Max(0, Sqrt(distx * distx + disty * disty) - (pos[i][2] + pos[j][2]));
            }
        }

        double[] currentMin = Enumerable.Repeat((double)long.MaxValue, pos.Length).ToArray();
        bool[] isFixed = new bool[pos.Length];
        currentMin[0] = 0;
        while (true)
        {
            int minInd = -1;
            double min = int.MaxValue;
            for (int i = 0; i < currentMin.Length; i++)
            {
                if (isFixed[i]) continue;
                if (currentMin[i] < min)
                {
                    min = currentMin[i];
                    minInd = i;
                }
            }
            if (minInd < 0) break;
            isFixed[minInd] = true;
            for (int i = 0; i < dist.Length; i++)
            {
                if(currentMin[minInd] + dist[i][minInd] < currentMin[i])
                {
                    currentMin[i] = currentMin[minInd] + dist[i][minInd];
                }
            }
        }
        Console.WriteLine(currentMin.Last());
    }
}