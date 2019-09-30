using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.4.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;
using TMD.Algo.Collections.Generic;

namespace GCJ10R1AQ1
{
    class Q1
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                string[] bits = lines[index].Split(' ');
                int n = int.Parse(bits[0]);
                int k = int.Parse(bits[1]);
                int[,] array = new int[n,n];
                for (int j = 0; j < n; j++)
                {
                    index++;
                    int counter = 0;
                    foreach (char c in lines[index])
                    {
                        array[j,counter] = c == 'R' ? 1 : ((c == 'B') ? 2 : 0);
                        counter++;
                    }

                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(n, k, array)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int n, int k, int[,] array)
        {
            for (int i = 0; i < n; i++)
            {
                int lastj = n - 1;
                for (int j = n - 1; j >= 0; j--)
                {
                    if (array[i, j] != 0)
                    {
                        array[i, lastj] = array[i, j];
                        lastj--;
                    }
                }
                for (int j = lastj; j >= 0; j--)
                {
                    array[i, j] = 0;
                }
            }
            // Horiz
            DisjointTracker<int> tracker1 = new DisjointTracker<int>();
            // vert
            DisjointTracker<int> tracker2 = new DisjointTracker<int>();
            // down right
            DisjointTracker<int> tracker3 = new DisjointTracker<int>();
            // up right
            DisjointTracker<int> tracker4 = new DisjointTracker<int>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (array[i, j] != 0)
                    {
                        tracker1.Add(GetVal(i, j, n));
                        tracker2.Add(GetVal(i, j, n));
                        tracker3.Add(GetVal(i, j, n));
                        tracker4.Add(GetVal(i, j, n));
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (array[i, j] != 0)
                    {
                        if (i > 0)
                        {
                            if (array[i, j] == array[i - 1, j])
                                tracker2.Union(GetVal(i, j, n), GetVal(i - 1, j, n));
                        }
                        if (j > 0)
                        {
                            if (array[i, j] == array[i, j - 1])
                                tracker1.Union(GetVal(i, j, n), GetVal(i, j - 1, n));
                        }
                        if (i > 0 && j > 0)
                        {
                            if (array[i, j] == array[i - 1, j - 1])
                                tracker3.Union(GetVal(i, j, n), GetVal(i - 1, j - 1, n));
                        }
                        if (i > 0 && j < n - 1)
                        {
                            if (array[i, j] == array[i - 1, j + 1])
                                tracker4.Union(GetVal(i, j, n), GetVal(i - 1, j + 1, n));
                        }
                    }
                }
            }
            Dictionary<int, int> counter1 = new Dictionary<int, int>();
            Dictionary<int, int> counter2 = new Dictionary<int, int>();
            Dictionary<int, int> counter3 = new Dictionary<int, int>();
            Dictionary<int, int> counter4 = new Dictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (array[i, j] != 0)
                    {
                        IncrementByRepresentative(counter1, tracker1, GetVal(i, j, n));
                        IncrementByRepresentative(counter2, tracker2, GetVal(i, j, n));
                        IncrementByRepresentative(counter3, tracker3, GetVal(i, j, n));
                        IncrementByRepresentative(counter4, tracker4, GetVal(i, j, n));
                    }
                }
            }
            bool rWin=false;
            bool bWin = false;
            UpdateWin(array, counter1, k, ref rWin, ref bWin, n);
            UpdateWin(array, counter2, k, ref rWin, ref bWin, n);
            UpdateWin(array, counter3, k, ref rWin, ref bWin, n);
            UpdateWin(array, counter4, k, ref rWin, ref bWin, n);
            if (rWin && bWin)
                return "Both";
            if (rWin)
                return "Red";
            if (bWin)
                return "Blue";
            return "Neither";
        }

        private static void UpdateWin(int[,] array, Dictionary<int, int> counter1, int k, ref bool rWin, ref bool bWin, int n)
        {
            foreach (KeyValuePair<int, int> kvp in counter1)
            {
                if (kvp.Value >= k)
                {
                    int i = kvp.Key / n;
                    int j = kvp.Key % n;
                    if (array[i, j] == 1)
                        rWin = true;
                    else
                        bWin = true;
                }
            }
        }

        private static void IncrementByRepresentative(Dictionary<int, int> counter1, DisjointTracker<int> tracker1, int p)
        {
            int rep = tracker1.GetRepresentative(p);
            if (counter1.ContainsKey(rep))
            {
                counter1[rep] = counter1[rep] + 1;
            }
            else
            {
                counter1[rep] = 1;
            }
        }

        private static int GetVal(int i, int j, int n)
        {
            return i * n + j;
        }
    }
}
