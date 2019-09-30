using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class DDDD : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                string ret = findSquare(s);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string findSquare(string s)
        {
            List<long> coef = new List<long>();
            long l = 0;
            long l1 = 1;
            for (int i = 0; i < s.Length; i++)
            {
                long pos = l1<<(s.Length - i-1);
                if (s[i] == '1')
                {
                    l += pos;
                }
                if (s[i] == '?')
                {
                    coef.Add(pos);
                }
            }

            int N = coef.Count;

            long MAX = l1 << coef.Count;
            for (long i = 0; i < MAX; i++)
            {
                    long ret = l;
                for (int j = 0; j < N; j++)
                {
                    if ((l1 << j & i) != 0)
                    {
                        ret += coef[j];
                    }
                }
                if (isSquare(ret))
                {
                    string sret = "";
                    while (ret > 0)
                    {
                        long d=ret%2;
                        ret/=2;
                        sret = (d>0 ? '1' : '0') + sret;
                    }
                    return sret;
                }
            }

            return "";
        }

        private bool isSquare(long l)
        {
            double d = Math.Sqrt(l);
            long l2 = (long)d;
            if (l2 * l2 == l) return true;
            return false;
        }

    }
}
