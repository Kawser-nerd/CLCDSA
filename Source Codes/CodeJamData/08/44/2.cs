using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2008
{
    class Program
    {
        string s;
        int k;
        int[] perm;
        bool[] used;
        int mincost;
        int go(string s,int k)
        {
            this.s = s;
            this.k = k;
            perm = new int[k];
            used = new bool[k];
            mincost = int.MaxValue;
            generate(0);
            return mincost;
        }
        void generate(int at)
        {
            if (at == k)
            {
                int cost = 0;
                char last = '1';
                for (int i = 0; i < s.Length; i+=k)
                {
                    for(int j=0;j<k;j++)
                    {
                        char next = s[perm[j] + i];
                        if (next != last)
                        {
                            cost++;
                            last = next;
                        }
                    }
                }
                if (cost < mincost)
                {
                    mincost = cost;
                }
            }
            else
            {
                for (int i = 0; i < k; i++)
                {
                    if (!used[i])
                    {
                        used[i] = true;
                        perm[at] = i;
                        generate(at + 1);
                        used[i] = false;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("D-small-attempt0.in");
            string output = "";
            int lineAt = 0;
            int testCases = int.Parse(input[lineAt++]);
            for (int i = 0; i < testCases; i++)
            {
                int k = int.Parse(input[lineAt++]);
                string s = input[lineAt++];
                int res = 0;
                Program p = new Program();
                res = p.go(s, k);

                output += "Case #" + (i + 1) + ": " + res + Environment.NewLine;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
        static double power(double xs, double ys, double zs, int x, int y, int z, int p)
        {
            return (Math.Abs(xs - x) + Math.Abs(ys - y) + Math.Abs(zs - z)) / p;
        }
    }
}
