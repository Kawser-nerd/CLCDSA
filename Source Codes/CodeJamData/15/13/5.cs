using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
    class C : GCJBase
    {
        public override void Solve()
        {
            throw new NotImplementedException();
        }

        public void Solve(string[] args)
        {
            string location = @"Z:\";
            if (args[0] == "s")
            {
                // Read file and split it into cases
                var input = File.OpenText(System.IO.Path.Combine(location, "input.txt"));
                int N = int.Parse(input.ReadLine());
                for (int i = 1; i <= N; i++)
                {
                    int M = int.Parse(input.ReadLine());
                    var output = File.CreateText(Path.Combine(location, string.Format("case{0}.in", i)));
                    output.WriteLine(M.ToString());
                    for (int j = 0; j < M; j++)
                    {
                        string s = input.ReadLine();
                        output.WriteLine(s);
                    }
                    output.Close();
                }
                input.Close();
            }
            else if (args[0] == "j")
            {
                var output = System.IO.File.CreateText(Path.Combine(location, "output.txt"));
                // Join cases into output
                for (int i = 1; i <= 14; i++)
                {
                    if (System.IO.File.Exists(Path.Combine(location, string.Format("case{0}.out", i))))
                    {
                        var input = File.OpenText(Path.Combine(location, string.Format("case{0}.out", i)));
                        output.WriteLine("Case #{0}:", i);
                        while (!input.EndOfStream)
                        {
                            output.WriteLine(input.ReadLine());
                        }
                        input.Close();
                    }
                }
                output.Close();
            }
            else
            {
                // Read file, process, output
                int iCase = int.Parse(args[0]);
                var input = File.OpenText(Path.Combine(location, string.Format("case{0}.in", iCase)));
                var output = File.CreateText(Path.Combine(location, string.Format("case{0}.out", iCase)));
                int N = int.Parse(input.ReadLine());
                List<Point> Ps = new List<Point>();
                for (int i = 0; i < N; i++)
                {
                    string[] sp = input.ReadLine().Split();
                    Point p = new Point();
                    p.x = int.Parse(sp[0]);
                    p.y = int.Parse(sp[1]);
                    Ps.Add(p);
                }

                string[] sOut = this.ProcessMulti(Ps);
                for (int i = 0; i < N; i++)
                {
                    output.WriteLine(sOut[i]);
                }
                output.Close();
                input.Close();
            }

            return;


            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                int N = int.Parse(Console.ReadLine());
                List<Point> Ps = new List<Point>();
                for (int i = 0; i < N; i++)
                {
                    string[] sp = Console.ReadLine().Split();
                    Point p = new Point();
                    p.x = int.Parse(sp[0]);
                    p.y = int.Parse(sp[1]);
                    Ps.Add(p);
                }

                string[] sOut = this.ProcessMulti(Ps);
                Console.WriteLine("Case #{0}:", iCase);
                System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                for (int j = 0; j < sOut.Length; j++)
                {
                    Console.WriteLine(sOut[j]);
                    System.Diagnostics.Debug.WriteLine(sOut[j]);
                }
            }

            if (bManual) Console.ReadKey();
        }

        private string[] ProcessMulti(List<Point> Ps)
        {
            int N = Ps.Count;
            long[] x = new long[N];
            long[] y = new long[N];
            for (int i = 0; i < N; i++)
            {
                x[i] = Ps[i].x;
                y[i] = Ps[i].y;
            }
            List<string> ret = new List<string>();
            for (int i = 0; i < N; i++)
            {
                int minCut = N - 1;
                for (int j = 0; j < N; j++)
                {
                    if (j != i)
                    {
                        long x1 = x[j] - x[i];
                        long y1 = y[j] - y[i];
                        //int online = 0;
                        int negline = 0;
                        int posline = 0;
                        for (int k = 0; k < N; k++)
                        {
                            if (k != i && k != j)
                            {
                                long x2 = x[k] - x[i];
                                long y2 = y[k] - y[i];
                                long xp = x1 * y2 - y1 * x2;
                                if (xp > 0) posline++;
                                if (xp < 0) negline++;
                                //if (xp == 0) online++;
                                if (posline >= minCut && negline >= minCut) break;
                            }
                        }
                        minCut = Math.Min(minCut, Math.Min(posline, negline));
                    }
                }
                ret.Add(minCut.ToString());
            }
            return ret.ToArray();
        }

        private class Point
        {
            public long x;
            public long y;
        }

    }
}
