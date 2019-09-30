using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ08R2Q4
{
    class ProgramQ4
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                // Parse
                string[] bits = lines[index].Split(' ');
                index++;
                int k = int.Parse(bits[0]);
                string s = lines[index];
                index++;
                // Process
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(k, s)));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static int Solve(int k, string s)
        {
            int[] perm = new int[k];
            return Recurs(perm, 0, k, s);
        }

        private static int Recurs(int[] perm, int depth, int k, string s)
        {
            if (depth == k)
            {

                string temp = s;
                temp = ApplyPerm(temp, perm, k);
                return Count(temp);
            }
            else
            {
                int best = s.Length;
                for (int i = 0; i < k; i++)
                {
                    bool ok = true;
                    for (int j = 0; j < depth; j++)
                    {
                        if (perm[j] == i)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                    {
                        perm[depth] = i;
                        int trial = Recurs(perm, depth + 1, k, s);
                        if (trial < best)
                            best = trial;
                    }
                }
                return best;
            }
        }

        private static string ApplyPerm(string temp, int[] perm, int k)
        {
            char[] ans = new char[temp.Length];
            for (int i = 0; i < temp.Length; i+=k)
            {
                for (int j = 0; j < perm.Length; j++)
                {
                    ans[i + j] = temp[i + perm[j]];
                }
            }
            return new string(ans);
        }

        private static int Count(string s)
        {
            int total = 0;
            char last = '0';
            foreach (char c in s)
            {
                if (c != last)
                {
                    total++;
                }
                last = c;
            }
            return total;
        }
    }
}
