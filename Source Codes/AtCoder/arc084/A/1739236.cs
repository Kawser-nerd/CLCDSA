using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace atcoder_sharp
{
    class ProgramC
    {
        const int MaxN = 100000;

        static void Main(string[] args)
        {
            int[][] v = new int[3][];
            BigInteger[][] s = new BigInteger[3][];

            int n = int.Parse(Console.ReadLine());

            for (int i = 0; i < 3; i++)
            {
                v[i] = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
                s[i] = new BigInteger[n];

                Array.Sort(v[i]);

                if (i == 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        s[i][j] = j + 1;
                    }
                }
                else
                {
                    for (int j = 0, k = -1; j < n; j++)
                    {
                        while (k + 1 < n && v[i - 1][k + 1] < v[i][j])
                        {
                            k++;
                        }

                        s[i][j] = 0;
                        if (j > 0)
                        {
                            s[i][j] += s[i][j - 1];
                        }
                        if (k >= 0)
                        {
                            s[i][j] += s[i - 1][k];
                        }
                    }
                }
            }

            Console.WriteLine(s[2][n - 1]);
        }
    }
}