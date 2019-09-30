using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.5.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;
using TMD.Algo.Collections.Generic;

namespace GCJ12R1AQ2
{
    class Q2
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
                int[] star1Req = new int[N];
                int[] star2Req = new int[N];
                for (int j = 0; j < N; j++)
                {
                    index++;
                    string[] bits2 = lines[index].Split(' ');
                    star1Req[j] = int.Parse(bits2[0]);
                    star2Req[j] = int.Parse(bits2[1]);
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(star1Req, star2Req)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int[] star1Req, int[] star2Req)
        {
            Dictionary<int, int> completed = new Dictionary<int, int>();
            int[] indexes = Enumerable.Range(0, star1Req.Length).ToArray();
//            int[] indexes2 = Enumerable.Range(0, star1Req.Length).ToArray();

            Array.Sort(star2Req, indexes);
//            Array.Sort(star1Req, indexes2);

            int pos2 = 0;
            //int pos1 = 0;
            int accumulated = 0;
            int count = 0;
            bool progress = true;
            while (progress)
            {
                progress = false;
                while (pos2 < star2Req.Length && star2Req[pos2] <= accumulated)
                {
                    progress = true;
                    int done;
                    if (!completed.TryGetValue(indexes[pos2], out done))
                        done = 0;
                    if (done < 2)
                    {
                        accumulated += 2 - done;
                        count++;
                        completed[indexes[pos2]] = 2;
                    }
                    pos2++;
                }
                for (int i = star2Req.Length - 1; i >= 0; i--)
                {
                    if (star1Req[indexes[i]] <= accumulated)
                    {
                        int done;
                        if (!completed.TryGetValue(indexes[i], out done))
                            done = 0;
                        if (done < 1)
                        {
                            progress = true;
                            accumulated++;
                            completed[indexes[i]] = 1;
                            count++;
                            break;
                        }
                    }
                }
            }
            if (pos2 < star2Req.Length)
                return "Too Bad";

            return count.ToString();
        }

    }
}
