using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\2012-2\1\A-small-attempt0.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\2012-2\1\A-small-attempt0.out";


        static void Main(string[] args)
        {

            var sr = new StreamReader(InputPath);
            var sw = new StreamWriter(OutputPath);

            int N = Int32.Parse(sr.ReadLine());
            for (int n = 1; n <= N; n++)
            {
                var x = SolveNextInput(sr);

                sw.WriteLine(GetCaseSolutionString(x, n));

            }
            sr.Close();
            sw.Close();
        }

        private static string GetCaseSolutionString(string result, int n)
        {
            return string.Format("Case #{0}: {1}", n, result);
        }

        private static string SolveNextInput(StreamReader sr)
        {
            string phrase = sr.ReadLine();
            string result = "NO";

            int N = int.Parse(phrase);
            var d = new List<Int64>();
            var l = new List<Int64>();
            for (int i = 0; i < N; i++)
            {
                phrase = sr.ReadLine();
                var x = phrase.Split(' ').Select(Int64.Parse).ToList();
                d.Add(x[0]);
                l.Add(x[1]);
            }
            Int64 D = Int64.Parse(sr.ReadLine());
            Dictionary<Tuple<long, int>, bool> ddd = new Dictionary<Tuple<long, int>, bool>();

            long sPos = 0;
            int holding = 0;
            
            Queue<Tuple<long, int>> queue = new Queue<Tuple<long, int>>();
            queue.Enqueue(new Tuple<long, int>(sPos, holding));
            while (true)
            {
                if (queue.Count == 0)
                {
                    break;
                }
                var t = queue.Dequeue();
                if (ddd.ContainsKey(t))
                {
                    continue;
                }
                else
                {
                    ddd.Add(t, true);
                }
                // check winning
                sPos = t.Item1;
                holding = t.Item2;
                long len = d[holding] - sPos;
                if (D - d[holding] <= len)
                {
                    result = "YES";
                    break;
                }

                // reachables
                List<Tuple<long, int>> reachables = GetReachables(d, l, sPos, holding);

                foreach (var reachable in reachables)
                {
                    if (ddd.ContainsKey(reachable))
                    {
                        continue;
                    }
                    else
                    {
                        queue.Enqueue(reachable);
                    }
                }


            }
            return result;
        }

        private static List<Tuple<long, int>> GetReachables(List<long> d, List<long> l, long sPos, int holding)
        {
            var rs = new List<Tuple<long, int>>();

            long len = (d[holding] - sPos);
            for (int i = holding + 1; i < d.Count; i++)
            {
                long dst = d[i] - d[holding];
                if (dst <= len)
                {
                    // in
                    if (l[i] >= (dst))
                    {
                        rs.Add(new Tuple<long, int>(d[holding], i));
                    }
                    else
                    {
                        rs.Add(new Tuple<long, int>(d[i] - l[i], i));
                    }
                }
                else
                {
                    break;
                }
            }

            return rs;
        }

    }

}
