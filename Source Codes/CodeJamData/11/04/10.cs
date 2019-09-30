using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ11Q
{
    class GoroSort : GCJBase
    {
        public override void Solve()
        {
            mem = new long[1001];
            for (int i = 0; i < 1001; i++)
            {
                mem[i] = -1;
            }
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                Console.ReadLine();
                string s = Console.ReadLine();
                long ret = expec(s);

                Console.WriteLine("Case #{0}: {1}", iCase, ret.ToString() + ".000000");

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int expec(string s)
        {
            string[] vals = s.Split(' ');
            int ret = 0;
            for (int i = 0; i < vals.Length; i++)
            {
                if (vals[i] != (i + 1).ToString()) ret++;
            }
            return ret;
        }

        private double expec(int mismatched)
        {
            return 0;
            double[] ex = new double[1001];
            ex[0] = 0;
            ex[1] = double.NaN;
            ex[2] = 2;
            ex[3] = 3;
            ex[4] = 4;
            long[,] ways = new long[101, 101];

            for (int i = 0; i < 100; i++)
            {
                ways[0, i] = 1;
                ways[i, i] = 1;
                for (int j = 1; j < i; j++)
                {
                    ways[j, i] = ways[j - 1, i] + ways[j, i];
                }
            }

            for (int i = 5; i <=100; i++)
            {
                long[] arrways = new long[101];
                arrways[0] = 1;
                arrways[1] = 0;
                for (int j = 2; j <=i; j++)
                {
                    //arrways[j]=
                }
            }
        }

        private long[] mem;
        private long NoMatchWays(long n)
        {
            return 0;
            if (n == 1) return 0;
            if (n == 0) return 1;
            if (mem[n] != -1)
            {
                return mem[n];
            }
            long ret = 0;

            for (int cylen = 2; cylen <= n; cylen++)
            {
                
            }

            mem[n] = ret;
        }
    }
}
