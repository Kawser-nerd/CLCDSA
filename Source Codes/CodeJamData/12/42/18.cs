using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GJamR2_B
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0) return;

            string filename = args[0];
            var lines = File.ReadLines(filename).ToList();

            int testCount = int.Parse(lines.ElementAt(0));
            int lineNumber = 1;

            for (int i = 0; i < testCount; i++)
            {
                string line = lines[lineNumber];
                string[] initS = line.Split(new char[] { ' ' });
                lineNumber++;
                int N = int.Parse(initS[0]);
                int W = int.Parse(initS[1]);
                int L = int.Parse(initS[2]);

                int[] r = new int[N];

                line = lines[lineNumber];
                lineNumber++;
                initS = line.Split(new char[] { ' ' });

                for (int j = 0; j < N; j++)
                {
                    r[j] = int.Parse(initS[j]);
                }

                int[,] res = Coordinate(N, W, L, r);

                File.AppendAllText(filename + ".out", "Case #" + (i + 1) + ":");
                for (int j = 0; j < N; j++)
                {
                    File.AppendAllText(filename + ".out", " " + res[j, 0] + " " + res[j, 1]);
                }

                File.AppendAllText(filename + ".out", "\n");
            }
        }

        private static int[,] Coordinate(int N, int W, int L, int[] r)
        {
            int minR = r.Min() / 2;
            if (minR == 0)
                minR = 1;

            int[,] res = new int[N, 2];
            bool[] located = new bool[N];

            for (int i = 0; i < N; i++)
            {
                int l = 0;
                int w = 0;

                while (!located[i])
                {
                    bool canPutHere = true;

                    for (int j = 0; j < i; j++)
                    {
                        int A = Math.Abs(w - res[j, 0]);
                        int B = Math.Abs(l - res[j, 1]);

                        double rad = (r[i] + r[j]);
                        double x = A;
                        double y = B;

                        if ( rad*rad <= x*x + y*y)
                            continue;
                        else
                        {
                            canPutHere = false;
                            break;
                        }
                    }

                    if (canPutHere)
                    {
                        res[i, 0] = w;
                        res[i, 1] = l;
                        located[i] = true;

                        break;
                    }
                    else
                    {
                        if (w + minR < W)
                        {
                            w += minR;
                        }
                        else
                        {
                            l += minR;
                            w = 0;

                            if (l > L)
                                throw new Exception();
                        }
                    }
                }
            }
            
            return res;
        }
    }
}
