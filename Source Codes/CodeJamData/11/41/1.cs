using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G2_A
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
                        sw.WriteLine("Case #{0}: {1}", tc, ls(sr));
                    }
                }
            }
        }

        private static double ls(StreamReader sr)
        {
            string[] ss;
            ss = sr.ReadLine().Split(' ');
            int x = int.Parse(ss[0]);
            int s = int.Parse(ss[1]);
            int r = int.Parse(ss[2]);
            int t0 = int.Parse(ss[3]);
            int n = int.Parse(ss[4]);
            int[] b = new int[n];
            int[] e = new int[n];
            int[] w = new int[n];
            double[] sp = new double[n + 1];
            double[] len = new double[n + 1];
            int slen = x;
            for(int i=0; i<n; i++)
            {                
                ss = sr.ReadLine().Split(' ');
                b[i] = int.Parse(ss[0]);
                e[i] = int.Parse(ss[1]);
                w[i] = int.Parse(ss[2]);
                slen -= e[i] - b[i];
                sp[i] = w[i] + s;
                len[i] = e[i] - b[i];
            }
            sp[n] = s;
            len[n] = slen;
            Array.Sort(sp, len);
            double t = t0;
            double ts = 0;
            for (int i = 0; i <= n; i++)
            {
                double bs = sp[i] + (r - s);
                double bt = len[i] / bs;
                if (t > bt)
                {
                    ts += bt;
                    t -= bt;
                }
                else
                {
                    double nt = t + (len[i] - bs * t) / sp[i];
                    ts += nt;
                    t = 0;
                }
            }
            return ts;
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
