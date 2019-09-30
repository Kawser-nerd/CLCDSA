using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CodeJam2017
{
    public class QR_C
    {
        public static void Solve(TextReader input, TextWriter output)
        {
            int t = Convert.ToInt32(input.ReadLine());

            for (int z = 1; z <= t; z++)
            {
                string[] data = input.ReadLine().Split(' ');
                long n = Int64.Parse(data[0]);
                long k = Int64.Parse(data[1]);

                var index = new SortedDictionary<long, long>(Comparer<long>.Create((x, y) => -x.CompareTo(y)));
                index.Add(n, 1);

                while (index[n] < k)
                {
                    long a = n / 2;
                    long b = (n - 1) / 2;

                    index[a] = index.ContainsKey(a) ? index[a] + index[n] : index[n];
                    index[b] = index.ContainsKey(b) ? index[b] + index[n] : index[n];

                    k -= index[n];
                    index.Remove(n);

                    n = index.Keys.First();
                }

                output.WriteLine("Case #{0}: {1} {2}", z, n / 2, (n - 1) / 2);
            }
        }
    }
}
