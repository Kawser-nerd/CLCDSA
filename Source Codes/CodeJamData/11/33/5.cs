using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BotTrust
{
    class Program
    {
        private string Solve(long T)
        {
            long N = Int64.Parse(Nx());
            long L = Int64.Parse(Nx());
            long H = Int64.Parse(Nx());

            //long gcd = Int64.Parse(Nx());

            var ps = new List<long>();
            for (int i = 0; i < N; ++i)
            {
                var next = Int64.Parse(Nx());
                ps.Add(next);
            }
            for (long t = L; t <= H; ++t)
            {
                bool good = true;
                for (int i = 0; i < N && good; ++i)
                {
                    var next = ps[i];

                    if (!(t < next && (next % t) == 0 ||
                        t >= next && (t % next) == 0))
                    {
                        good = false;
                    }
                }

                if (good)
                {
                    return t.ToString();
                }
            }

            return "NO";
        }

        public long Gcd(long a, long b)
        {
            if ((a % b) == 0)
            {
                return b;
            }

            return Gcd(b, a % b);
        }

        public class Pr
        {
            public long D;
            public long C;

            public override string ToString()
            {
                return String.Format("D = {0}, C = {1}", D, C);
            }
        }

        public static void Run()
        {
            var T = Int32.Parse(input[0]);
            tokenIdx = 1;

            for (long i = 1; i <= T; ++i)
            {
                output
                    .AppendFormat("Case #{0}: {1}", i, new Program().Solve(i))
                    .AppendLine();
            }
        }

        static long tokenIdx;
        static string[] input;
        static StringBuilder output;

        public string Nx()
        {
            return input[tokenIdx++];
        }

        static void Main(string[] args)
        {
            input = String.Join(" ", File.ReadAllLines("in.txt")).Split(' ');
            output = new StringBuilder();

            Run();

            File.WriteAllText("../../out.txt", output.ToString());
        }
    }
}
