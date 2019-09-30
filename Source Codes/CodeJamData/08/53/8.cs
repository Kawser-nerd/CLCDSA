using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        static int M, N;
        static string[] map;

        static void Main(string[] args)
        {
            int total = int.Parse(Console.ReadLine());
            for (int casen = 1; casen <= total; casen++)
            {
                string[] buf = Input();
                M = int.Parse(buf[0]);
                N = int.Parse(buf[1]);
                map = new string[M];
                for (int i = 0; i < M; i++)
                    map[i] = Console.ReadLine();

                int[] masks = new int[M];
                int[] f = new int[1 << N];
                for (int row = 0; row < M; row++)
                {
                    masks[row] = 0;
                    for (int i = 0; i < N; i++)
                        if (map[row][i] == 'x') masks[row] |= (1 << i);
                    int[] nf = new int[1 << N];
                    for(int i=0; i<nf.Length; i++)
                    {
                        if((i & masks[row]) != 0) continue;
                        if (!IsValid(0, i)) continue;
                        nf[i] = 0;
                        for (int j = 0; j < f.Length; j++)
                        {
                            if(row > 0 && (j & masks[row-1]) != 0) continue;
                            if (IsValid(j, i)) nf[i] = Math.Max(nf[i], f[j]);
                        }
                        nf[i] += count1Bits(i);
                    }
                    f = nf;
                }

                int result = 0;
                for (int i = 0; i < f.Length; i++)
                {
                    result = Math.Max(result, f[i]);
                }
                Console.WriteLine("Case #{0}: {1}", casen, result);
            }
        }

        static bool IsValid(int mask1, int mask2)
        {
            int[] digitsA = ToDigits(mask1);
            int[] digitsB = ToDigits(mask2);
            for (int i = 0; i < N; i++)
            {
                if (digitsB[i] != 0)
                {
                    if (i > 0 && digitsA[i - 1] != 0) return false;
                    if (i < N - 1 && digitsA[i + 1] != 0) return false;
                    if (i < N - 1 && digitsB[i + 1] != 0) return false;
                }
            }
            return true;
        }

        static int[] ToDigits(int mask)
        {
            int[] d = new int[N];
            for (int i = 0; i < N; i++)
            {
                d[i] = mask % 2;
                mask /= 2;
            }
            return d;
        }

        static int count1Bits(int mask)
        {
            int result = 0;
            for (int i = 0; i < N; i++)
            {
                if (mask % 2 == 1) result++;
                mask /= 2;
            }
            return result;
        }

        static string[] Input()
        {
            return Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }
    }
}
