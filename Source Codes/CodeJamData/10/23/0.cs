/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2010QualRound
{
    public class C_YourRankIsPure
    {
        const int Modulus = 100003;
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            Random rnd = new Random();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                int n = scanner.NextInt();
                var f = new long[n + 1, n + 1];
                var c = new long[n + 1, n + 1];
                for (int i = 0; i <= n; i++)
                {
                    c[i, 0] = 1;
                    c[i, i] = 1;
                    for (int j = 1; j < i; j++)
                    {
                        c[i, j] = (c[i - 1, j] + c[i - 1, j - 1]) % Modulus;
                    }
                }
                
                for (int i = 2; i <= n; i++)
                {
                    f[i, 1] = 1;
                    for (int j = 2; j < i; j++)
                    {
                        f[i, j] = 0;
                        for (int k = 1; k < j; k++)
                            f[i, j] += (f[j, k] * c[i - j - 1, j - k - 1]) % Modulus;
                        f[i, j] %= Modulus;
                    }
                }
                long answer = 0;
                for (int j = 1; j < n; j++)
                    answer += f[n, j];
                answer %= Modulus;
                output.WriteLine("Case #{0}: {1}", caseId, answer % Modulus);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
            new C_YourRankIsPure().Solve(Console.In, Console.Out);
            new C_YourRankIsPure().Solve(new StreamReader("C-small-attempt0.in"), new StreamWriter("C-small.out"));
            new C_YourRankIsPure().Solve(new StreamReader("C-large.in"), new StreamWriter("C-large.out"));
        }

    }
}
