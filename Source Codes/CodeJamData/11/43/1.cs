using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G2_C
    {
        static List<long> ps = new List<long>();
        public static void Main(String[] args)
        {
            string input = @"../../C.in";
            string output = @"../../C.out";
            ps.Add(2);
            for (long i = 3; i <= 1000000; i += 2)
            {
                bool isP = true;
                for (int j = 0; j < ps.Count && ps[j] * ps[j] <= i; j++)
                {
                    if (i % ps[j] == 0)
                    {
                        isP = false;
                        break;
                    }
                }
                if (isP)
                {
                    //Console.WriteLine(i);
                    ps.Add(i);
                }
            }
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    long tn = long.Parse(sr.ReadLine());
                    for (long tc = 1; tc <= tn; tc++)
                    {
                        sw.WriteLine("Case #{0}: {1}", tc, ls(long.Parse(sr.ReadLine())));
                    }
                }
            }
        }

        private static long ls(long n)
        {
            checked
            {
                if (n == 1)
                    return 0;
                long s = 1;
                for (int i = 0; i < ps.Count && ps[i] * ps[i] <= n; i++)
                {
                    long t = 1;
                    long cnt = 0;
                    while (t <= n)
                    {
                        t *= ps[i];
                        if (t <= n)
                        {
                            cnt++;
                        }
                    }
                    //Console.WriteLine(t + " " + ps[i] + " " + cnt);
                    s += cnt - 1;
                }
                //Console.WriteLine(n + " " + s);
                return s;
            }
        }

        static void assert(bool v)
        {
            if (!v)
            {
                throw new Exception();
            }
        }
    }
}
