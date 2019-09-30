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
    public class C_ThemePark
    {
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            Random rnd = new Random();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                long R = scanner.NextLong();
                long k = scanner.NextLong();
                int n = scanner.NextInt();
                var g = Enumerable.Range(0, n).Select(i => scanner.NextLong()).ToArray();
                var d = Enumerable.Repeat(-1, n).ToArray();
                var s = Enumerable.Repeat((long) 0, n + 1).ToArray();
                long answer = 0;
                for (int i = 0, r = 0; r < R; r++)
                {
                    if (d[i] > -1)
                    {
                        int l = r - d[i];
                        answer += (R - r) / l * (s[r] - s[d[i]]);
                        answer += s[(R - r) % l + d[i]] - s[d[i]];
                        break;
                    }
                    d[i] = r;
                    long c = 0;
                    int j = i;
                    while (c + g[i] <= k)
                    {
                        c += g[i];
                        i++;
                        if (i == n)
                            i = 0;
                        if (i == j)
                            break;
                    }
                    answer += c;
                    s[r + 1] = answer;
                }
                output.WriteLine("Case #{0}: {1}", caseId, answer);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
            new C_ThemePark().Solve(Console.In, Console.Out);
            new C_ThemePark().Solve(new StreamReader("C-small-attempt0.in"), new StreamWriter("C-small.out"));
            new C_ThemePark().Solve(new StreamReader("C-large.in"), new StreamWriter("C-large.out"));
        }

    }
}
