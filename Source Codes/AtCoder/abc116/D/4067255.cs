using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC116_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var NK = Console.ReadLine().Split().Select(long.Parse).ToArray();
            var N = NK[0];
            var K = NK[1];
            var tds = new Model[N];

            for (long i = 0; i < N; i++)
            {
                var td = Console.ReadLine().Split().Select(long.Parse).ToArray();
                tds[i] = new Model() { t = td[0], d = td[1] };
            }

            tds = tds.OrderByDescending(x => x.d).ToArray();

            long sum = 0;
            var type = new Dictionary<long, long>();
            for (long i = 0; i < K; i++)
            {
                long tt = tds[i].t;
                if (type.ContainsKey(tt)) type[tt]++;
                else type.Add(tt, 1);

                sum += tds[i].d;
            }

            long res = (long)Math.Pow(type.Count(), 2) + sum;
            long last = K - 1;
            for (long i = K; i < N; i++)
            {
                var tt = tds[i].t;
                if (type.ContainsKey(tt)) continue;

                while (last > 0 && type[tds[last].t] <= 1)
                {
                    last--;
                }
                if (last == 0) break;

                type[tds[last].t]--;
                type.Add(tt, 1);

                sum = sum - tds[last].d + tds[i].d;
                last--;

                res = Math.Max(res, (long)Math.Pow(type.Count(), 2) + sum);
            }

            Console.WriteLine(res);
        }

        public class Model
        {
            public long d { get; set; }
            public long t { get; set; }
        }
    }
}