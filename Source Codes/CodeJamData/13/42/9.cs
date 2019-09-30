using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BaseApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\Current\CodeJam\4\B-large.in";
            string output = @"d:\Work\Current\CodeJam\4\B-large.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task2(sin);
                        sout.WriteLine("Case #{0}: {1}", i, result);
                        Console.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
        }

        private static string Task2(StreamReader sin)
        {
            var s = sin.ReadLine().Split(' ');
            var N = BigInteger.Parse(s[0]);
            var P = BigInteger.Parse(s[1]);

            var N2 = Pow(N);
            if (P == N2) return (P-1).ToString() + " " + (P-1).ToString();

            var BN2 = N2;
            long i = 0;
            while (P < BN2)
            {
                i += 1;
                BN2 /= 2;
            }
            var badi = i;

            var GN2 = N2/2;
            BigInteger sum = GN2;
            long goodi = 0;
            while (P > sum)
            {
                goodi++;
                GN2 /= 2;
                sum += GN2;
            }

            
            BigInteger g = 0;
            if (goodi == 0)
            {
                g = 0;
            }
            else
            {
                g = Pow(goodi+1)-1-1;
            }

            BigInteger b = N2 - Pow(badi);
            


            return g.ToString() + " " + b.ToString();
        }

        private static BigInteger Pow(BigInteger N)
        {
            BigInteger m = 1;
            for (int i = 0; i < N; i++)
            {
                m *= 2;
            }
            return m;
        }

        public class Ticket
        {
            public long from;
            public long to;
            public long count;
        }
        private static string Task1(StreamReader sin)
        {
            var s = sin.ReadLine().Split(' ');
            var N = long.Parse(s[0]);
            var M = long.Parse(s[1]);

            var ticks = new List<Ticket>();

            for (int i = 0; i < M; i++)
            {
                s = sin.ReadLine().Split(' ');
                var t = new Ticket()
                    {
                        from = long.Parse(s[0]),
                        to = long.Parse(s[1]),
                        count = long.Parse(s[2]),
                    };
                ticks.Add(t);
            }

            long loss = 0;
            bool change = true;

            while (change)
            {
                change = false;
                
                // debug

                // take all pairs and compare if one can become longer
                for (int i = 0; i < ticks.Count-1; i++)
                {
                    var t1 = ticks[i];
                    if (t1.count == 0) continue;
                    for (int j = i+1; j < ticks.Count; j++)
                    {
                        var t2 = ticks[j];
                        if (t2.count == 0) continue;
                        if (Intersect1(t1, t2))
                        {
                            // t1 can be made longer
                            var cnt = Math.Min(t1.count, t2.count);
                            var t3 = new Ticket()
                                {
                                    from = t1.from,
                                    to = t2.to,
                                    count = cnt
                                };
                            var t4 = new Ticket()
                                {
                                    from = t2.from,
                                    to = t1.to,
                                    count = cnt
                                };
                            t1.count -= cnt;
                            t2.count -= cnt;
                            ticks.Add(t3);
                            ticks.Add(t4);
                            // calc sum
                            var l = t3.to - t3.from - (t1.to - t1.from);
                            var v = t2.from - t1.from;
                            loss += (l*v) * cnt;
                            change = true;
                        }
                        else if (Intersect2(t1, t2))
                        {
                            // t2 can be made longer
                            // t1 can be made longer
                            var cnt = Math.Min(t1.count, t2.count);
                            var t3 = new Ticket()
                            {
                                from = t1.from,
                                to = t2.to,
                                count = cnt
                            };
                            var t4 = new Ticket()
                            {
                                from = t2.from,
                                to = t1.to,
                                count = cnt
                            };
                            t1.count -= cnt;
                            t2.count -= cnt;
                            ticks.Add(t3);
                            ticks.Add(t4);
                            // calc sum
                            var l = t4.to - t4.from - (t2.to - t2.from);
                            var v = t1.from - t2.from;
                            loss += (l * v) * cnt;
                            change = true;
                        }
                    }
                }
                ticks = ticks.Where(t => t.count > 0).ToList();
            }

            return loss.ToString();
        }

        private static bool Intersect1(Ticket t1, Ticket t2)
        {
            if (t1.from < t2.from)
            {
                return t1.to >= t2.from && t2.to > t1.to;
            }
            return false;
        }
        private static bool Intersect2(Ticket t1, Ticket t2)
        {
            if (t2.from < t1.from)
            {
                return t2.to >= t1.from && t1.to > t2.to;
            }
            return false;
        }


    }
}
