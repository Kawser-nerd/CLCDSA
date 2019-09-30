using System;
using System.Linq;

namespace atcoder_BegginerContest89_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var hwd = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var H = hwd[0];
            var W = hwd[1];
            var D = hwd[2];
            var ah = new int[90001];
            var aw = new int[90001];
            var d = new int[90001];
            var tmp = new int[hwd[0]][];

            for (int i = 0; i < H; i++)
            {
                tmp[i] = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < W; j++)
                {
                    ah[tmp[i][j]] = i;
                    aw[tmp[i][j]] = j;
                }
            }

            for (int i = D + 1; i <= H * W; i++)
            {
                d[i] = d[i - D] + Math.Abs(ah[i] - ah[i - D]) + Math.Abs(aw[i] - aw[i - D]);
            }

            var q = int.Parse(Console.ReadLine());
            var lr = new int[2];

            for (int i = 0; i < q; i++)
            {
                lr = Console.ReadLine().Split().Select(int.Parse).ToArray();
                Console.WriteLine(d[lr[1]] - d[lr[0]]);
            }
        }
    }
}