using System;
using System.Collections.Generic;
using System.Linq;

class C
{
    public int Solve(int[] d, int[] n, int[] w, int[] e, int[] s, int[] delta_d, int[] delta_p, int[] delta_s)
    {
        var h = new int[2000];
        int ret = 0;
        while (n.Any(nn => nn > 0))
        {
            var nexth = new int[h.Length];

            var mind = d.Where((dd,i)=>n[i]>0).Min();
            var attack = Enumerable.Range(0, d.Length).Where(i => d[i] == mind && n[i] > 0).ToArray();
            foreach (int i in attack)
            {
                bool success = false;
                for (int j = w[i]; j < e[i]; j++)
                {
                    if (h[j + 1000] < s[i]) success = true;
                    nexth[j + 1000] = Math.Max(nexth[j + 1000], s[i]);
                }
                if (success) ret++;

                n[i]--;
                d[i] += delta_d[i];
                w[i] += delta_p[i];
                e[i] += delta_p[i];
                s[i] += delta_s[i];
            }

            h = h.Zip(nexth, Math.Max).ToArray();
        }

        return ret;
    }

    static IEnumerable<string> Output() {
        var N = int.Parse(Console.ReadLine());
        var tribes = Enumerable.Range(0, N).Select(i=>Console.ReadLine().Split(' ').Select(int.Parse).ToArray()).ToArray();
        var args = Enumerable.Range(0,8).Select(i=> tribes.Select(t=>t[i]).ToArray()).ToArray();
        yield return new C().Solve(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}

