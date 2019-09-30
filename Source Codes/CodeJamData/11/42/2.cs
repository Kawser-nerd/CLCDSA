/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2011Round2
{
    public class B_SpinningBlade
    {

        private int getShape(int[,] w, int[,] s, int i, int j, int x, int y)
        {
            return s[x, y] - s[i - 1, y] - s[x, j - 1] + s[i - 1, j - 1] - w[i, j] - w[x, j] - w[x, y] - w[i, y];
        }
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                
                int r = scanner.NextInt();
                int c = scanner.NextInt();
                int d = scanner.NextInt();

                int[,] w = new int[r + 1, c + 1];
                int[,] xw = new int[r + 1, c + 1];
                int[,] yw = new int[r + 1, c + 1];
                int[,] sw = new int[r + 1, c + 1];
                int[,] sx = new int[r + 1, c + 1];
                int[,] sy = new int[r + 1, c + 1];

                for (int i = 0; i < r; i++)
                {
                    string s = scanner.Next();
                    for (int j = 0; j < c; j++)
                    {
                        w[i + 1, j + 1] = s[j] - '0';
                        sw[i + 1, j + 1] = w[i + 1, j + 1];
                        xw[i + 1, j + 1] = w[i + 1, j + 1] * (i + 1);
                        yw[i + 1, j + 1] = w[i + 1, j + 1] * (j + 1);
                        sx[i + 1, j + 1] = xw[i + 1, j + 1];
                        sy[i + 1, j + 1] = yw[i + 1, j + 1];
                    }
                }
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                    {
                        sw[i + 1, j + 1] += sw[i + 1, j] + sw[i, j + 1] - sw[i, j];
                        sx[i + 1, j + 1] += sx[i + 1, j] + sx[i, j + 1] - sx[i, j];
                        sy[i + 1, j + 1] += sy[i + 1, j] + sy[i, j + 1] - sy[i, j];
                    }

                int answer = -1;
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                    {
                        for (int k = 3; k <= Math.Min(r - i, c - j); k++)
                        {
                            int tx = getShape(xw, sx, i + 1, j + 1, i + k, j + k);
                            int ty = getShape(yw, sy, i + 1, j + 1, i + k, j + k);
                            int tw = getShape(w, sw, i + 1, j + 1, i + k, j + k);
                            if (2 * tx == tw * (2 * i + 1 + k) && 2 * ty == tw * (2 * j + 1 + k))
                            {
                                answer = Math.Max(answer, k);
                            }
                        }
                    }

                if (answer == -1)
                    output.WriteLine("Case #{0}: IMPOSSIBLE", caseId);
                else
                    output.WriteLine("Case #{0}: {1}", caseId, answer);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
            //      new B_SpinningBlade().Solve(Console.In, Console.Out);
            //  new B_SpinningBlade().Solve(new StreamReader("B-small-attempt0.in"), new StreamWriter("B-small.out"));
            new B_SpinningBlade().Solve(new StreamReader("B-large.in"), new StreamWriter("B-large.out"));
        }
    }
}
