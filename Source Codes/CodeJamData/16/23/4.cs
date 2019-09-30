using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2016Round1B
{
    public class ProblemC
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Round1B\";

        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText(Path + "in_C.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var n = int.Parse(textReader.ReadLine());
                    var g = new Dictionary<int, List<int>>();
                    var s1 = new Dictionary<string, int>();
                    var s2 = new Dictionary<string, int>();
                    int j = 0;
                    int k = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        var p = textReader.ReadLine().Split(' ').ToArray();

                        var l = j;
                        if (!s1.ContainsKey(p[0]))
                            s1.Add(p[0], j++);
                        else
                            l = s1[p[0]];

                        var r = k;
                        if (!s2.ContainsKey(p[1]))
                            s2.Add(p[1], k++);
                        else
                            r = s2[p[1]];

                        if (!g.ContainsKey(l))
                            g.Add(l, new List<int>());
                        g[l].Add(r);
                    }

                    result.AppendLine($"Case #{t}: {Solve(g, j, k, n)}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_C.txt"))
                textWriter.Write(result.ToString());
        }

        private int Solve(Dictionary<int, List<int>> g, int n, int k, int t)
        {
            var r = new int[k].Select(i => -1).ToArray();
            var result = 0;
            for (int v = 0; v < n; ++v)
            {
                var used = new bool[n];
                if (Match(v, used, g, r))
                    result++;
            }
            result += t - n - k;
            return result;
        }

        private bool Match(int v, bool[] used, Dictionary<int, List<int>> g, int[] r)
        {
            if (used[v]) return false;
            used[v] = true;
            for (int i = 0; i < g[v].Count; ++i)
            {
                int to = g[v][i];
                if (r[to] == -1 || Match(r[to], used, g, r))
                {
                    r[to] = v;
                    return true;
                }
            }
            return false;
        }
    }
}
