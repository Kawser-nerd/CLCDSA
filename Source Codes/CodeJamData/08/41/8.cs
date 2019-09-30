using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ08R2Q1
{
    class ProgramQ1
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
                int M = int.Parse(bits[0]);
                int V = int.Parse(bits[1]);
                int[] vals = new int[M];
                bool[] mod = new bool[(M - 1) / 2];
                bool[] gates = new bool[(M - 1) / 2];
                for (int j = 0; j < M; j++)
                {
                    if (j < (M - 1) / 2)
                    {
                        string[] bits2 = lines[index].Split(' ');
                        int G = int.Parse(bits2[0]);
                        vals[j] = -1;
                        gates[j] = G == 1;
                        int C = int.Parse(bits2[1]);
                        mod[j] = C == 1;
                    }
                    else
                    {
                        int val = int.Parse(lines[index]);
                        vals[j] = val;
                    }
                    index++;
                }
                // Process
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(vals, mod, gates, M, V)));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int[] vals, bool[] mod, bool[] gates, int M, int V)
        {
            for (int i = (M - 1) / 2 - 1; i >= 0; i--)
            {
                Calc(i, vals, gates);
            }
            cache =  new int[M, 2];
            for (int i = 0; i < M; i++)
            {
                cache[i, 0] = -1;
                cache[i, 1] = -1;
            }
            int min = Min(0, vals, mod, gates, V);
            if (min <20000)
                return min.ToString();
            else
                return "IMPOSSIBLE";
        }

        private static int[,] cache;

        private static int Min(int index, int[] vals, bool[] mod, bool[] gates, int V)
        {
            if (cache[index, V] != -1)
                return cache[index, V];
            if (vals[index] == V)
                return Cache(index, V, 0);
            if (index >= mod.Length)
                return Cache(index, V, 20000);
            if (V == 1)
            {
                int childSum = vals[2 * index + 1] + vals[2 * index + 1];
                if (childSum > 0)
                {
                    if (mod[index])
                        return Cache(index, V, 1);
                    else if (vals[2 * index + 1] == 0)
                        return Cache(index, V, Min(2 * index + 1, vals, mod, gates, 1));
                    else
                        return Cache(index, V, Min(2 * index + 2, vals, mod, gates, 1));
                }
                else
                {
                    if (gates[index])
                    {
                        if (!mod[index])
                            return Cache(index, V,
                                Min(2 * index + 1, vals, mod, gates, 1) + Min(2 * index + 2, vals, mod, gates, 1));
                        else
                            return Cache(index, V,
                                Math.Min(Min(2 * index + 1, vals, mod, gates, 1) + Min(2 * index + 2, vals, mod, gates, 1),
                                Math.Min(1 + Min(2 * index + 1, vals, mod, gates, 1), 1 + Min(2 * index + 2, vals, mod, gates, 1))));
                    }
                    else
                    {
                        return Cache(index, V,
                            Math.Min(Min(2 * index + 1, vals, mod, gates, 1), Min(2 * index + 2, vals, mod, gates, 1)));
                    }
                }
            }
            else
            {
                int childSum = vals[2 * index + 1] + vals[2 * index + 1];
                if (childSum < 2)
                {
                    if (mod[index])
                        return Cache(index, V, 1);
                    else if (vals[2 * index + 1] == 1)
                        return Cache(index, V, Min(2 * index + 1, vals, mod, gates, 0));
                    else
                        return Cache(index, V, Min(2 * index + 2, vals, mod, gates, 0));
                }
                else
                {
                    if (!gates[index])
                    {
                        if (!mod[index])
                            return Cache(index, V,
                                Min(2 * index + 1, vals, mod, gates, 0) + Min(2 * index + 2, vals, mod, gates, 0));
                        else
                            return Cache(index, V,
                                Math.Min(Min(2 * index + 1, vals, mod, gates, 0) + Min(2 * index + 2, vals, mod, gates, 0),
                                Math.Min(1 + Min(2 * index + 1, vals, mod, gates, 0), 1 + Min(2 * index + 2, vals, mod, gates, 0))));
                    }
                    else
                    {
                        return Cache(index, V,
                            Math.Min(Min(2 * index + 1, vals, mod, gates, 0), Min(2 * index + 2, vals, mod, gates, 0)));
                    }
                }
            }
        }

        private static int Cache(int index, int V, int p)
        {
            cache[index, V] = p;
            return p;
        }

        private static void Calc(int i, int[] vals, bool[] gates)
        {
            if (gates[i])
            {
                vals[i] = (vals[i * 2+1] + vals[i * 2 + 2]) == 2 ? 1 : 0;
            }
            else
            {
                vals[i] = (vals[i * 2+1] + vals[i * 2 + 2]) > 0 ? 1 : 0;
            }
        }
    }
}
