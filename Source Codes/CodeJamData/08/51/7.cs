using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GCJ08R3Q1
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
                int L = int.Parse(lines[index]);
                index++;
                List<string> S = new List<string>();
                List<int> T = new List<int>();
                while (T.Count < L)
                {
                    string[] bits = lines[index].Split(' ');
                    index++;
                    for (int j = 0; j < bits.Length; j++)
                    {
                        if (S.Count > T.Count)
                        {
                            T.Add(int.Parse(bits[j]));
                        }
                        else
                        {
                            S.Add(bits[j]);
                        }
                    }
                }
               // Process
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(S, T)));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static int Solve(List<string> S, List<int> T)
        {
            Stopwatch watch = new Stopwatch();
            watch.Start();
            int[,] array = new int[6003, 6003];
            int X = 3001;
            int Y = 3001;
            int dir = 0;
            for (int i = 0; i < S.Count; i++)
            {
                for (int j = 0; j < T[i]; j++)
                {
                    for (int k = 0; k < S[i].Length; k++)
                    {
                        if (S[i][k] == 'L')
                        {
                            dir = (dir +3) % 4;
                        }
                        else if (S[i][k] == 'R')
                        {
                            dir = (dir + 1) % 4;
                        }
                        else
                        {
                            Join(ref X, ref Y, dir, array);
                        }
                    }
                }
            }
            int total = 0;
            bool[,] check = new bool[6002, 6002];
            // do two scans one horizontal one vertical.
            int lastChange = int.MaxValue;
            int lastChange2 = int.MaxValue;
            for (int i = 0; i < 6002; i++)
            {
                bool inside = false;
                bool inside2 = false;
                for (int j = 0; j < 6003; j++)
                {
                    if ((array[i, j] & (1 << 1)) != 0)
                    {
                        inside = !inside;
                        if (inside && lastChange != int.MaxValue)
                        {
                            for (int k = lastChange; k < j; k++)
                            {
                                if (!check[i, k])
                                {
                                    check[i, k] = true;
                                    total++;
                                }
                            }
                        }
                        lastChange = j;
                    }
                    if ((array[j, i] & (1 << 2)) != 0)
                    {
                        inside2 = !inside2;
                        if (inside2 && lastChange2 != int.MaxValue)
                        {
                            for (int k = lastChange2; k < j; k++)
                            {
                                if (!check[k, i])
                                {
                                    check[k, i] = true;
                                    total++;
                                }
                            }
                        }
                        lastChange2 = j;
                    }
                }
            }
            watch.Stop();
            Console.Out.WriteLine(watch.ElapsedMilliseconds);
            return total;
        }

        private static void Join(ref int X, ref int Y, int dir, int[,] array)
        {
            switch (dir)
            {
                case 0:
                    {
                        int Y2 = Y - 1;
                        int X2 = X;
                        array[X, Y] |= 1 << 0;
                        array[X2, Y2] |= 1 << 2;
                        Y = Y2;
                        X = X2;
                    }
                    break;
                case 1:
                    {
                        int Y2 = Y;
                        int X2 = X+1;
                        array[X, Y] |= 1 << 1;
                        array[X2, Y2] |= 1 << 3;
                        Y = Y2;
                        X = X2;
                    }
                    break;
                case 2:
                    {
                        int Y2 = Y + 1;
                        int X2 = X;
                        array[X, Y] |= 1 << 2;
                        array[X2, Y2] |= 1 << 0;
                        Y = Y2;
                        X = X2;
                    }
                    break;
                case 3:
                    {
                        int Y2 = Y;
                        int X2 = X-1;
                        array[X, Y] |= 1 << 3;
                        array[X2, Y2] |= 1 << 1;
                        Y = Y2;
                        X = X2;
                    }
                    break;
            }
        }
    }
}
