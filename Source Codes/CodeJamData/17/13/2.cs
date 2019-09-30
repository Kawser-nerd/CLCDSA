using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Play_the_Dragon
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\C-small-attempt2.in";
            //const string filename = @"..\..\B-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static long GS(long Hd, long Ad, long Hk, long Ak)
        {
            return (((((Hd << 10) + Ad) << 10) + Hk) << 10) + Ak;
        }

        private static void GS(long move, out long Hd, out long Ad, out long Hk, out long Ak)
        {
            Ak = move & 1023;
            move >>= 10;
            Hk = move & 1023;
            move >>= 10;
            Ad = move & 1023;
            move >>= 10;
            Hd = move;
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');

            long Hd = int.Parse(ss[0]), Ad = int.Parse(ss[1]), Hk = int.Parse(ss[2]), Ak = int.Parse(ss[3]), B = int.Parse(ss[4]), D = int.Parse(ss[5]);
            long mhd = Hd;
            var set = new HashSet<long>();
            long move = GS(Hd, Ad, Hk, Ak);
            set.Add(move);
            var prev = new List<long>();
            prev.Add(move);


            int time = 0;
            bool win = false;
            while (prev.Count > 0)
            {
                var next = new List<long>();

                time++;
                win = false;
                foreach (long l in prev)
                {
                    GS(l, out Hd, out Ad, out Hk, out Ak);

                    if (Hk <= Ad)
                    {
                        win = true;
                        break;
                    }

                    if (mhd - Ak > 0)
                    {
                        move = GS(mhd - Ak, Ad, Hk, Ak);
                        if (!set.Contains(move))
                        {
                            set.Add(move);
                            next.Add(move);
                        }
                    }

                    if (Hd - Ak > 0)
                    {
                        move = GS(Hd - Ak, Ad + B, Hk, Ak);
                        if (!set.Contains(move))
                        {
                            set.Add(move);
                            next.Add(move);
                        }

                        

                        move = GS(Hd - Ak, Ad, Hk - Ad, Ak);
                        if (!set.Contains(move))
                        {
                            set.Add(move);
                            next.Add(move);
                        }
                    }

                    long atk = Math.Max(0, Ak - D);
                    if (Hd - atk > 0)
                    {
                        move = GS(Hd - atk, Ad, Hk, atk);
                        if (!set.Contains(move))
                        {
                            set.Add(move);
                            next.Add(move);
                        }
                    }
                }
                if (win)
                    break;

                prev = next;
            }

            if (win)
            {
                Console.WriteLine("Case #{0}: {1}", Case, time);
                writer.WriteLine("Case #{0}: {1}", Case, time);
            }
            else
            {
                Console.WriteLine("Case #{0}: IMPOSSIBLE", Case);
                writer.WriteLine("Case #{0}: IMPOSSIBLE", Case);
            }
        }
    }
}