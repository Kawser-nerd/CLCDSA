using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC106D
{
    class ABC106D
    {
        static void Main(string[] args)
        {
            var dg = Console.ReadLine().Split(' ').Select(v => int.Parse(v)).ToArray();
            var n = dg[0];
            var m = dg[1];
            var q = dg[2];

            var map = new int[n + 1, n + 1];
            for (int i = 0; i < m; ++i)
            {
                var data = Console.ReadLine().Split(' ').Select(v => int.Parse(v)).ToArray();
                var x = data[0];
                var y = data[1];
                ++map[x, y];
            }

            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    var x = j - 1;
                    map[j, i] += map[x, i];

                }

                var y = i - 1;
                for (int j = 1; j <= n; ++j)
                {
                    map[j, i] += map[j, y];
                }
            }

            var count = new List<int>(q);
            for (int i = 0; i < q; ++i)
            {
                var ques = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                var s = ques[0];
                var e = ques[1];

                count.Add(map[e, e] - map[s - 1, e] - map[e, s - 1] + map[s - 1, s - 1]);
            }

            foreach (var v in count)
            {
                Console.WriteLine(v);
            }
        }
    }
}