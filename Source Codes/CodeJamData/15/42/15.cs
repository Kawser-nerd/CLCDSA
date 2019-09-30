using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        class Source
        {
            public readonly double R;
            public readonly double C;
            public Source(double R, double C)
            {
                this.R = R;
                this.C = C;
            }
        }
        private static double? Solve(double V, double X, Source[] sources)
        {
            if (X < sources.Min(x => x.C) || sources.Max(x => x.C) < X) { return null; }
            if (sources.Length == 1) { return V / sources[0].R; }
            if (sources[0].C == sources[1].C)
            {
                return V / (sources[0].R + sources[1].R);
            }
            double V0 = V * (X - sources[1].C) / (sources[0].C - sources[1].C);
            double V1 = V * (X - sources[0].C) / (sources[1].C - sources[0].C);
            return Math.Max(V0 / sources[0].R, V1 / sources[1].R);
        }
        static void Main(string[] args)
        {
            string filename = "../B-small-attempt2";
            var sr = new StreamReader(filename + ".in");
            var sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                var args1 = Array.ConvertAll(sr.ReadLine().Split(), double.Parse);
                int N = (int)args1[0];
                double V = args1[1];
                double X = args1[2];
                var sources = new Source[N];
                for (int j = 0; j < N; ++j)
                {
                    var args2 = Array.ConvertAll(sr.ReadLine().Split(), double.Parse);
                    sources[j] = new Source(args2[0], args2[1]);
                }
                var result = Solve(V, X, sources);
                sw.WriteLine("Case #{0}: {1}", i + 1, result.HasValue ? result.ToString() : "IMPOSSIBLE");
                Console.WriteLine("Case #{0}: Done", i + 1);
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
