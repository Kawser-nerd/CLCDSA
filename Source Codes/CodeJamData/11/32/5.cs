using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BotTrust
{
    class Program
    {
        private long Solve(long T)
        {
            long L = Int64.Parse(Nx());
            long t = Int64.Parse(Nx());
            long N = Int64.Parse(Nx());
            long C = Int64.Parse(Nx());

            var dist = new List<Pr>();
            for (long i = 0; i < C; ++i)
            {
                dist.Add(new Pr() { D = Int32.Parse(Nx()) });
            }

            var loopDist = dist.Select(d => d.D).Sum();

            var loop = N / C;
            var rest = N % C;

            long totalDist = loopDist * (loop); // +dist.Select(d => d.D).Take(rest).Sum();
            for (int i = 0; i < rest; ++i)
            { totalDist += dist[i].D; }
            

            long trvDistBefore = t / 2;

            if (totalDist <= trvDistBefore)
            {
                return (totalDist * 2);
            }

            long loopBefore = trvDistBefore / loopDist;
            long inLoopRest = trvDistBefore % loopDist;

            var loopAfter = loop - (loopBefore + 1);

            bool done = false;

            for (int i = 0; i < C; ++i)
            {
                // last
                if (i < rest)
                {
                    dist[i].C++;
                }

                dist[i].C += loopAfter;

                // fist
                if (done)
                {
                    dist[i].C++;
                }

                if (!done && inLoopRest < dist[i].D)
                {
                    dist.Add(new Pr() { D = dist[i].D - inLoopRest, C = 1 });
                    done = true;
                }
                else
                {
                    inLoopRest -= dist[i].D;
                }
            }

            Comparison<Pr> cmp = (a, b) => { return b.D == a.D ? 0 : a.D > b.D ? -1 : 1; };

            dist.Sort(cmp);

            long totalSave = 0;

            long ll = L;

            foreach (var p in dist)
            {
                var u = Math.Min(ll, p.C);

                totalSave += u * p.D;

                ll -= u;
            }


            var res = totalDist * 2 - totalSave;

            return res;
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
