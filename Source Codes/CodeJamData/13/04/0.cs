using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Chest
        {
            public int key;
            public int[] keys;
        }

        class Solver
        {
            Dictionary<int, int> map;

            private int[] MapKeys(int[] keys)
            {
                int[] counts = new int[map.Count];
                for (int i = 0; i < keys.Length; i++)
                {
                    int key;
                    if (map.TryGetValue(keys[i], out key))
                    {
                        counts[key] += 1;
                    }
                }
                return counts;
            }

            private bool SolutionExists(Chest[] chests, bool[] used, int[] keys)
            {
                bool loop = true;
                while (loop)
                {
                    loop = false;
                    for (int i = 0; i < chests.Length; i++)
                    {
                        if (!used[i] && keys[chests[i].key] > 0)
                        {
                            for (int k = 0; k < keys.Length; k++)
                            {
                                keys[k] += chests[i].keys[k];
                            }
                            used[i] = true;
                            loop = true;
                        }
                    }
                }

                for (int i = 0; i < used.Length; i++)
                {
                    if (!used[i])
                    {
                        return false;
                    }
                }
                return true;
            }

            public string Solve(int[] keys, Chest[] chests)
            {
                map = new Dictionary<int, int>();
                for (int i = 0; i < chests.Length; i++)
                {
                    if (!map.ContainsKey(chests[i].key))
                    {
                        map[chests[i].key] = map.Count;
                    }
                    chests[i].key = map[chests[i].key];
                }

                keys = MapKeys(keys);
                for (int i = 0; i < chests.Length; i++)
                {
                    chests[i].keys = MapKeys(chests[i].keys);
                }

                int[] answer = new int[chests.Length];
                bool[] used = new bool[chests.Length];
                for (int i = 0; i < chests.Length; i++)
                {
                    bool found = false;
                    for (int j = 0; j < chests.Length; j++)
                    {
                        if (!used[j] && keys[chests[j].key] > 0)
                        {
                            bool[] used2 = (bool[])used.Clone();
                            int[] keys2 = (int[])keys.Clone();
                            used2[j] = true;
                            keys2[chests[j].key] -= 1;
                            for (int k = 0; k < keys2.Length; k++)
                            {
                                keys2[k] += chests[j].keys[k];
                            }
                            if (SolutionExists(chests, used2, (int[])keys2.Clone()))
                            {
                                answer[i] = j;
                                used[j] = true;
                                found = true;
                                keys = keys2;
                                break;
                            }
                        }
                    }
                    if (!found)
                    {
                        return "IMPOSSIBLE";
                    }
                }

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < chests.Length; i++)
                {
                    if (i > 0)
                    {
                        sb.Append(' ');
                    }
                    sb.Append(answer[i] + 1);
                }

                return sb.ToString();
            }
        }

        static void Main(string[] args)
        {
            //string filename = "sample2";
            //string filename = "D-small-attempt0";
            string filename = "D-large";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    Solver solver = new Solver();
                    for (int i = 0; i < T; i++)
                    {
                        string[] tmp = reader.ReadLine().Split();
                        int k = Int32.Parse(tmp[0]);
                        int n = Int32.Parse(tmp[1]);

                        int[] keys = new int[k];
                        tmp = reader.ReadLine().Split();
                        for (int j = 0; j < k; j++)
                        {
                            keys[j] = Int32.Parse(tmp[j]);
                        }

                        Chest[] chests = new Chest[n];
                        for (int j = 0; j < n; j++)
                        {
                            chests[j] = new Chest();
                            tmp = reader.ReadLine().Split();
                            chests[j].key = Int32.Parse(tmp[0]);
                            chests[j].keys = new int[Int32.Parse(tmp[1])];
                            for (int l = 0; l < chests[j].keys.Length; l++)
                            {
                                chests[j].keys[l] = Int32.Parse(tmp[l + 2]);
                            }
                        }
                        writer.WriteLine("Case #" + (i + 1) + ": " + solver.Solve(keys, chests));
                    }
                }
            }
        }
    }
}
