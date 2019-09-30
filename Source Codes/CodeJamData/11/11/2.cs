using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G1_A
    {
        public static void Main(String[] args)
        {
            string input = @"../../A.in";
            string output = @"../../A.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    long tn = long.Parse(sr.ReadLine());
                    for (long tc = 1; tc <= tn; tc++)
                    {
                        string res = ls(sr.ReadLine());
                        sw.WriteLine("Case #{0}: {1}", tc, res);
                    }
                }
            }
        }

        private static string ls(string line)
        {
            string[] s = line.Split(' ');
            long n = long.Parse(s[0]);
            long pd = long.Parse(s[1]);
            long pg = long.Parse(s[2]);
            bool ok = false;
            if (pg == 100 || pg == 0)
            {
                ok = (pd == pg);
            }
            else
            {
                n = Math.Min(n, 100);
                for (long d = 1; d <= n; d++)
                {
                    long v = d * pd;
                    if (v % 100 == 0)
                    {
                        ok = true;
                    }
                    if (ok)
                        break;
                }
            }
            return ok ? "Possible" : "Broken";
        }

        static void assert(bool v)
        {
            if (false)
            {
                throw new Exception();
            }
        }
    }
}
