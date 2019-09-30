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

namespace GCJ10R2Q3
{
    class Q3
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
                int r = int.Parse(bits[0]);
                int[] x1 = new int[r];
                int[] x2 = new int[r];
                int[] y1 = new int[r];
                int[] y2 = new int[r];
                for (int j = 0; j < r; j++)
                {
                    index++;
                    string[] bits2 = lines[index].Split(' ');
                    x1[j] = int.Parse(bits2[0]);
                    x2[j] = int.Parse(bits2[2]);
                    y1[j] = int.Parse(bits2[1]);
                    y2[j] = int.Parse(bits2[3]);
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(r, x1, x2, y1, y2)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int r, int[] x1, int[] x2, int[] y1, int[] y2)
        {
            DisjointTracker<int> sets = new DisjointTracker<int>();
            for (int i = 0; i < r; i++) {
                sets.Add(i);
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = i + 1; j < r; j++)
                {
                    if (x1[i] > x2[j]+1 || x2[i] < x1[j]-1 || y1[i] > y2[j]+1 || y2[i] < y1[j]-1)
                        continue;
                    if (x1[i] == x2[j] + 1 && y1[i] == y2[j] + 1)
                        continue;
                    if (x1[j] == x2[i] + 1 && y1[j] == y2[i] + 1)
                        continue;
                    sets.Union(i, j);
                }
            }
            Dictionary<int, List<int>> setLookup = new Dictionary<int, List<int>>();
            for (int i = 0; i < r; i++)
            {
                int rep = sets.GetRepresentative(i);
                List<int> vals;
                if (setLookup.TryGetValue(rep, out vals))
                {
                    vals.Add(i);
                }
                else
                {
                    vals = new List<int>();
                    vals.Add(i);
                    setLookup[rep] = vals;
                }
            }
            int max = 0;
            foreach (List<int> set in setLookup.Values)
            {
                int maxx2 = int.MinValue;
                int maxy2 = int.MinValue;
                for (int i = 0; i < set.Count; i++)
                {
                    if (x2[set[i]] > maxx2)
                        maxx2 = x2[set[i]];
                    if (y2[set[i]] > maxy2)
                        maxy2 = y2[set[i]];
                }
                int selectedx1 = x1[set[0]];
                int selectedy1 = y1[set[0]];
                for (int i = 1; i < set.Count; i++)
                {
                    if (y1[set[i]] - selectedy1 < -1*( x1[set[i]] - selectedx1))
                    {
                        selectedy1 = y1[set[i]];
                        selectedx1 = x1[set[i]];
                    }
                }

                int thisTotal = maxx2 - selectedx1 + maxy2 - selectedy1 + 1;
                if (thisTotal > max)
                    max = thisTotal;
            }

            return max.ToString();
        }

        private class IndexedSorter : IComparer<int>
        {
            int[] indexes;
            public IndexedSorter(int[] indexes)
            {
                this.indexes = indexes;
            }

            public int Compare(int x, int y)
            {
                return indexes[x].CompareTo(indexes[y]);
            }
        }

    }
}
