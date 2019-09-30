using System;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Threading;

namespace Roller_Coaster_Scheduling
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\B-small-attempt0.in";
            const string filename = @"..\..\B-large.in";

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

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');

            int n = int.Parse(ss[0]);
            int c = int.Parse(ss[1]);
            int m = int.Parse(ss[2]);

            var cc = new int[c];
            var mm = new int[n];

            for (int i = 0; i < m; i++)
            {
                ss = reader.ReadLine().Split(' ');

                int p = int.Parse(ss[0]) - 1;
                int b = int.Parse(ss[1]) - 1;

                cc[b]++;
                mm[p]++;
            }

            int l = cc.Max(), r = m;
            while (l < r)
            {
                int mid = (l + r)/2;

                int free = 0;
                bool f = true;
                for (int i = 0; i < mm.Length; i++)
                {
                    if (mm[i] > mid)
                    {
                        int over = mm[i] - mid;
                        if (over > free)
                        {
                            f = false;
                            break;
                        }
                        free -= over;
                    }
                    else
                    {
                        free += mid - mm[i];
                    }
                }
                if (f)
                    r = mid;
                else l = mid + 1;
            }

            int y = l;
            int z = 0;

            {
                for (int i = 0; i < mm.Length; i++)
                {
                    if (mm[i] > y)
                    {
                        int over = mm[i] - y;

                        z += over;
                    }
                }
            }

            Console.WriteLine("Case #{0}: {1} {2}", Case, y, z);
            writer.WriteLine("Case #{0}: {1} {2}", Case, y, z);
        }
    }
}