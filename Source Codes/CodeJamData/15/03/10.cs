using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace waterfood.CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputs = File.ReadAllLines(@"../../C-large.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                string[] line1 = inputs[x * 2 + 1].Split(' ');
                string line2 = inputs[x * 2 + 2];
                long L = long.Parse(line1[0]);
                long X = long.Parse(line1[1]);
                long len = L * X;
                int[] group = line2.ToCharArray().Select(IJKToInt).ToArray();
                bool ans = false;

                long lenForI = FindIFromLeft(group, L);
                long lenForK = FindKFromRight(group, L);
                if (lenForI != -1 && lenForK != -1 && len > (lenForI + lenForK))
                {
                    int middle = LongProd(group, lenForI, (len - lenForI - lenForK), L);
                    ans = (middle == IJKToInt('j'));
                }

                outputs.AppendLine(string.Format("Case #{0}: ", x + 1) + (ans ? "YES" : "NO"));
            }

            File.WriteAllText(@"../../large.out", outputs.ToString());
        }

        static int LongProd(int[] group, long start, long length, long L)
        {
            length = length % (4 * L);
            start = start % L;
            int res = IJKToInt('1');
            for (int i = 0; i < length; i++)
            {
                res = Prod[res, group[(start + i) % L]];
            }
            return res;
        }

        // for 4 groups at most
        static long FindIFromLeft(int[] group, long L)
        {
            int res = IJKToInt('1');
            for (int i = 0; i < 4; i++)
            {
                for (long j = 0; j < L; j++)
                {
                    res = Prod[res, group[j]];
                    if (res == IJKToInt('i'))
                    {
                        return i * L + j + 1;
                    }
                }
            }
            return -1;
        }

        static long FindKFromRight(int[] group, long L)
        {
            int res = IJKToInt('1');
            for (int i = 0; i < 4; i++)
            {
                for (long j = L - 1; j >= 0; j--)
                {
                    res = Prod[group[j], res];
                    if (res == IJKToInt('k'))
                    {
                        return i * L + (L - j);
                    }
                }
            }
            return -1;
        }

        // 0=1 1=i 2=j 3=k 4=-1 5=-i 6=-j 7=-k
        static int IJKToInt(char c)
        {
            switch (c)
            {
                case 'i': return 1;
                case 'j': return 2;
                case 'k': return 3;
                default: return 0;
            }
        }

        static int[,] Prod = new int[8, 8]
        {
            {0, 1, 2, 3, 4, 5, 6, 7},
            {1, 4, 3, 6, 5, 0, 7, 2},
            {2, 7, 4, 1, 6, 3, 0, 5},
            {3, 2, 5, 4, 7, 6, 1, 0},
            {4, 5, 6, 7, 0, 1, 2, 3},
            {5, 0, 7, 2, 1, 4, 3, 6},
            {6, 3, 0, 5, 2, 7, 4, 1},
            {7, 6, 1, 0, 3, 2, 5, 4},
        };
    }
}
