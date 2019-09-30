using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.5.1.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;
using TMD.Algo.Collections.Generic;

namespace GCJ12R2
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
                int N = int.Parse(bits[0]);
                int[] pos = new int[N];
                int[] length = new int[N];
                
                for (int j = 0; j < N; j++)
                {
                    index++;
                    bits = lines[index].Split(' ');
                    pos[j] = int.Parse(bits[0]);
                    length[j] = int.Parse(bits[1]);
                }
                index++;
                int D = int.Parse(lines[index]);
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(pos, length, D)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int[] pos, int[] length, int D)        
        {
            int[] canReach = new int[pos.Length];
            Queue<int> toConsider = new Queue<int>();
            toConsider.Enqueue(0);
            canReach[0] = pos[0];
            int lastReached = 0;
            while (toConsider.Count > 0)
            {
                int cur = toConsider.Dequeue();
                if (pos[cur] + canReach[cur] >= D)
                    return "YES";
                for (int i = lastReached + 1; i < pos.Length; i++)
                {
                    if (canReach[i] > 0)
                    {
                        continue;
                    }
                    if (pos[cur] + canReach[cur] >= pos[i])
                    {
                        toConsider.Enqueue(i);
                        canReach[i] = Math.Min(length[i], pos[i] - pos[cur]);
                        lastReached = i;
                    }
                    else
                        break;
                }
            }

            return "NO";
        }

    }
}
