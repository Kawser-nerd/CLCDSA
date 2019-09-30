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
using System.Diagnostics;

namespace GCJ12R2Q2
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
                int W = int.Parse(bits[1]);
                int L = int.Parse(bits[2]);
                index++;
                bits = lines[index].Split(' ');
                int[] r = new int[N];
                for (int j = 0; j < N; j++)
                    r[j] = int.Parse(bits[j]);

                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(W, L, r)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private class Tri
        {
            public int X;
            public int Y;
            public int I;
        }

        private static string Solve(int W, int L, int[] radius)
        {
            long total = 0;
            for (int i = 0; i < radius.Length; i++)
            {
                total += radius[i];
            }
            StringBuilder result = new StringBuilder();
            if (2 * total <= W)
            {
                int cur=0;
                for (int i = 0; i < radius.Length; i++)
                {
                    Debug.Assert(cur <= W);
                    Write(result, cur, 0);
                    cur += radius[i];
                    if (i < radius.Length - 1)
                        cur += radius[i + 1];
                }
            }
            else if (2 * total <= L)
            {
                int cur = 0;
                for (int i = 0; i < radius.Length; i++)
                {
                    result.Append(0);
                    result.Append(' ');
                    Debug.Assert(cur <= L);
                    result.Append(cur);
                    result.Append(' ');
                    cur += radius[i];
                    if (i < radius.Length - 1)
                        cur += radius[i + 1];
                }
            }
            else
            {
                int[] indexes = new int[radius.Length];
                for (int i=0; i < indexes.Length; i++)
                    indexes[i] = i;
                Array.Sort(radius, indexes);
                Array.Reverse(radius);
                Array.Reverse(indexes);
                int curWidth = 2*radius[0];
                int curRight = radius[0];
                int curLeft = -radius[0];
                int curTop = -radius[0];
                int curHeight = 2* radius[0];
                int cur = 0;
                List<Tri> points = new List<Tri>();
                while (cur < radius.Length)
                {
                    int lastLeft = curLeft;
                    while (cur < radius.Length)
                    {
                        int x = lastLeft + radius[cur];
                        if (x < 0)
                            x = 0;
                        if (x > W)
                            break;
                        if (x + radius[cur] > curRight)
                            break;
                        int y = curTop + radius[cur];
                        y = Math.Max(0, y);
                        Debug.Assert(x >= 0);
                        Debug.Assert(x <= W);
                        Debug.Assert(y >= 0);
                        if (y > L)
                            break;
                        Debug.Assert(y <= L);
                        points.Add(new Tri() { X = x, Y = y, I = indexes[cur] });
                        lastLeft =x  + radius[cur];
                        cur++;
                    }
                    if (cur >= radius.Length)
                        break;
                    curTop += curHeight;
                    if (curTop + radius[cur] > L)
                    {
                        curLeft += curWidth;
                        curRight = curLeft + 2 * radius[cur];
                        curWidth = 2 * radius[cur];
                        curHeight = curWidth;
                        curTop = -radius[cur];
                    }
                    else
                    {
                        curHeight = 2 * radius[cur];
                    }


                }
                points.Sort((a, b) => a.I.CompareTo(b.I));
                points.ForEach(a => Write(result, a.X, a.Y));
            }

            string res = result.ToString();
            res = res.Trim();
            return res;
        }

        private static void Write(StringBuilder result, int x, int y)
        {
            result.Append(x);
            result.Append(' ');
            result.Append(y);
            result.Append(' ');
        }

    }
}
