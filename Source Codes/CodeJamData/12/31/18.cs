using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace mappy4
{
    class Program
    {
        static bool check(List<int[]> graph, bool[] mark, int n)
        {
            if (mark[n] == true) return true;
            mark[n] = true;

            int[] g = graph[n];
            for (int i = 0; i < g.Length; i++)
            {
                if (check(graph, mark, g[i] - 1)) return true;
            }
            return false;
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0], Encoding.GetEncoding("Shift_JIS")))
            {
                int T = int.Parse(reader.ReadLine());
                for (int t = 0; t < T; t++)
                {
                    int N = int.Parse(reader.ReadLine());
                    List<int[]> graph = new List<int[]>();
                    for (int n = 0; n < N; n++) {
                        string[] ss = reader.ReadLine().Split(' ');
                        int size = int.Parse(ss[0]);
                        int[] g = new int[size];
                        for (int i = 0; i < size; i++) 
                        {
                            g[i] = int.Parse(ss[i + 1]);
                        }
                        graph.Add(g);
                    }

                    bool result = false;
                    bool[] mark = new bool[N];
                    for (int n = 0; n < N; n++)
                    {
                        for (int i = 0; i < mark.Length; i++) {
                            mark[i] = false;
                        }
                        result = check(graph, mark, n);
                        if (result) break;
                    }

                    Console.WriteLine("Case #" + (t + 1) + ": " + (result ? "Yes" : "No"));
                }
            }
        }
    }
}
