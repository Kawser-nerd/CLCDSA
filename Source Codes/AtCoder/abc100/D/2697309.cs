using System;
using System.Linq;

namespace ABC100_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var NM = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var N = NM[0];
            var M = NM[1];
            var cake = new long[N][];
            var value = new long[8][];

            for (int i = 0; i < 8; i++)
                value[i] = new long[N];

            for (int i = 0; i < N; i++)
            {
                cake[i] = Console.ReadLine().Split().Select(long.Parse).ToArray();
                
                value[0][i] = cake[i][0] + cake[i][1] + cake[i][2];
                value[1][i] = cake[i][0] + cake[i][1] - cake[i][2];
                value[2][i] = cake[i][0] - cake[i][1] + cake[i][2];
                value[3][i] = cake[i][0] - cake[i][1] - cake[i][2];
                value[4][i] = -1 * cake[i][0] + cake[i][1] + cake[i][2];
                value[5][i] = -1 * cake[i][0] + cake[i][1] - cake[i][2];
                value[6][i] = -1 * cake[i][0] - cake[i][1] + cake[i][2];
                value[7][i] = -1 * cake[i][0] - cake[i][1] - cake[i][2];
            }

            long mv = -10000000000;
            foreach (var v in value)
            {
                Array.Sort(v);
                Array.Reverse(v);
                var sum = v.Take(M).Sum();
                if (sum > mv)
                    mv = sum;
            }
            Console.WriteLine(mv);
        }
    }
}