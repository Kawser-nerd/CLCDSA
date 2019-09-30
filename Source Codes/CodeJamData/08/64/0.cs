using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
// If TMD.Algo used, it is available from www.themissingdocs.net/downloads/TMD.Algo.0.0.3.0.zip

namespace GCJOnSite1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int loopvariable = 0; loopvariable < cases; loopvariable++)
            {
                // Parse
                int L = int.Parse(lines[index]);
                index++;
                int[] aFrom = new int[L];
                int[] aTo = new int[L];
                for (int i = 0; i < L-1; i++)
                {
                    string[] bits = lines[index].Split(' ');
                    index++;
                    aFrom[i] = int.Parse(bits[0]);
                    aTo[i] = int.Parse(bits[1]);
                }
                int M = int.Parse(lines[index]);
                index++;
                int[] bFrom = new int[L];
                int[] bTo = new int[L];
                for (int i = 0; i < M-1; i++)
                {
                    string[] bits = lines[index].Split(' ');
                    index++;
                    bFrom[i] = int.Parse(bits[0]);
                    bTo[i] = int.Parse(bits[1]);
                }

                // Process
                output.Add(string.Format("Case #{0}: {1}", loopvariable + 1, Solve(aFrom, aTo, bFrom, bTo)));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int[] aFrom, int[] aTo, int[] bFrom, int[] bTo)
        {
            int M = bFrom.Length + 1;
            int N = aFrom.Length + 1;

            int[] pattern = new int[N];
            bool[,] a = new bool[N, N];
            bool[,] b = new bool[M, M];
            for (int i = 0; i < N - 1; i++)
            {
                a[aFrom[i], aTo[i]] = true;
                a[aTo[i], aFrom[i]] = true;
            }
            for (int i = 0; i < M - 1; i++)
            {
                b[bFrom[i], bTo[i]] = true;
                b[bTo[i], bFrom[i]] = true;
            }
            return Recurse(a, b, pattern, 0);
        }

        private static string Recurse(bool[,] a, bool[,] b, int[] pattern, int p)
        {
            if (p == pattern.Length)
            {
                bool ok = true;
                for (int i = 0; i < b.GetLength(0); i++)
                {
                    for (int j = 0; j < b.GetLength(0); j++)
                    {
                        if (b[i, j] && !a[pattern[i], pattern[j]])
                        {
                            return "NO";
                        }
                    }
                }
                return "YES";
            }
            else
            {
                for (int i = 0; i < a.GetLength(0); i++)
                {
                    bool match = false;
                    for (int j = 0; j < p; j++)
                    {
                        if (pattern[j] == i)
                        {
                            match = true;
                            break;
                        }
                    }
                    if (match)
                        continue;
                    pattern[p] = i;
                    string res = Recurse(a, b, pattern, p + 1);
                    if (res == "YES")
                        return "YES";
                }
            }
            return "NO";
        }

    }
}
