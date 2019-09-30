using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GJamR1SubC_A
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0) return;

            string filename = args[0];
            var lines = File.ReadLines(filename).ToList();

            int testCount = int.Parse(lines.ElementAt(0));
            int lineNumber = 1;

            for (int i = 0; i < testCount; i++)
            {
                string line = lines[lineNumber];
                lineNumber++;
                int classCount = int.Parse(line);

                
                
                int[][] tree = new int[classCount][];
                for (int j = 0; j < classCount; j++)
                {
                    line = lines[lineNumber];
                    lineNumber++;
                    string[] t = line.Split(new char[]{' '});
                    int k = int.Parse(t[0]);
                    tree[j] = new int[k];
                    for (int m = 0; m < k; m++ )
                    {
                        tree[j][m] = int.Parse(t[m+1]);
                    }
                }

                bool res = HasDiamond(tree);

                File.AppendAllText(filename + ".out", "Case #" + (i+1) + ": "+ (res? "Yes": "No"));

                File.AppendAllText(filename + ".out", "\n");
            }
        }

        private static bool HasDiamond(int[][] tree)
        {
            for (int i = 0; i < tree.Length; i++)
            {
                {
                    try
                    {
                        List<int> parents = GetParents(tree, i);

                        if (parents.Count != parents.Distinct().Count())
                            return true;
                    }
                    catch
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        private static List<int> GetParents(int[][] tree, int index)
        {
            List<int> summary = new List<int>();
            for (int i = 0; i < tree[index].Length; i++)
            {
                if (summary.Count != summary.Distinct().Count())
                    throw new Exception("Diamond found");


                int indexToAdd = tree[index][i] - 1;

                summary.Add(indexToAdd);

                summary.AddRange(GetParents(tree, indexToAdd));
            }

            return summary;
        }
    }
}
