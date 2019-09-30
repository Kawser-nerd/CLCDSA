using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2015Round1C
{
    class Bsmall
    {
        static void Main(string[] args)
        {
            TextReader text = File.OpenText("../../input.txt");
            TextWriter outtext = File.CreateText("../../output.txt");
            int T = int.Parse(text.ReadLine());
            for (int n_case = 1; n_case <= T; n_case++)
            {
                String input = text.ReadLine();
                String[] inputs = input.Split(' ');
                int K = int.Parse(inputs[0]);
                int L = int.Parse(inputs[1]);
                int S = int.Parse(inputs[2]);
                String keyboard = text.ReadLine();
                String goal = text.ReadLine(); int overlappingindex = 1;
                Boolean found = false;
                double expexted = 0;
                while (overlappingindex < L && !found)
                {
                    if (goal.Substring(overlappingindex, L - overlappingindex).Equals(goal.Substring(0, L - overlappingindex)))
                    {
                        found = true;
                    }
                    else
                    {
                        overlappingindex++;
                    }
                }
                long max;
                if (!found)
                {
                    max = S / L;
                }
                else
                {
                    max = (S - (L - overlappingindex)) / overlappingindex;
                }
                for (int i = 0; i < L; i++)
                {
                    char c = goal[i];
                    if (!keyboard.Contains(c))
                    {
                        max = 0;
                        break;
                    }
                }
                long expected = solve(K, L, S, 0, goal, keyboard, "");
                double exp = expected / Math.Pow(K, S);
                outtext.WriteLine("Case #" + n_case + ": "+(max-exp));
            }
            outtext.Flush();
        }

        private static long solve(int K, int L, int S, int ind, string goal, string keyboard, string p)
        {
            if (ind == S)
            {
                long res = 0;
                for (int i = 0; i < S - L + 1; i++)
                {
                    if (p.Substring(i, L).Equals(goal)) res++;
                }
                return res;
            }
            else
            {
                long res = 0;
                foreach (char c in keyboard)
                {
                    long mmax = 0;
                    res += solve(K, L, S, ind + 1, goal, keyboard, p + c);
                }
                return res;
            }
        }
    }
}
