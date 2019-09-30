/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2010Round2
{
    public class B_WorldCup2010
    {
        const int Inf = 10000003;
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            Random rnd = new Random();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                int n = scanner.NextInt();
                var f = new long[1 << (n + 1), n + 1];
                for (int i = 0; i < (1 << n); i++)
                {
                    int m = scanner.NextInt();
                    for (int j = 0; j <= n; j++)
                        f[i, j] = (j < n - m) ? Inf : 0;
                }
                int offset = 1 << n;
                int offsetOld = 0;
                for (int i = n - 1; i >= 0; i--)
                {
                    for (int j = 0; j < (1 << i); j++)
                    {
                        int p = scanner.NextInt();
                        for (int k = 0; k <= n - 1; k++)
                            f[offset + j, k] = Math.Min(f[offsetOld + j * 2, k + 1] + f[offsetOld + j * 2 + 1, k + 1] + p, 
                                f[offsetOld + j * 2, k] + f[offsetOld + j * 2 + 1, k]);
                    }
                    offset += 1 << i;
                    offsetOld  += 1 << (i + 1);
                }
                
                output.WriteLine("Case #{0}: {1}", caseId, f[offsetOld, 0]);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
           // new B_WorldCup2010().Solve(Console.In, Console.Out);
           // new B_WorldCup2010().Solve(new StreamReader("B-small-attempt0.in"), new StreamWriter("B-small.out"));
            new B_WorldCup2010().Solve(new StreamReader("B-large.in"), new StreamWriter("B-large.out"));
        }

    }
}
