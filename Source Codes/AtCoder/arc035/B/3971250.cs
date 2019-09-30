using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            int iN = int.Parse(System.Console.ReadLine().Trim());
            List<int> lstT = new List<int>();
            for (int i = 0; i < iN; i++) { lstT.Add(int.Parse(System.Console.ReadLine().Trim())); }
            //// Debug??
            //int iN = 10000;
            //List<int> lstT = new List<int>();
            //for (int i = 0; i < iN; i++) { lstT.Add(10000); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstT.Sort();                                                // ??
            List<int> lstDup = new List<int>();                         // ??????????
            List<long> lstT2 = new List<long>();                        // ????
            long lT2 = 0L;                                              // ????
            int iNow = 0;                                               // ???????
            int iCnt = 1;                                               // ??????
            for (int i = 0; i < lstT.Count; i++)
            {
                lT2 += lstT[i];                                         // ????
                lstT2.Add(lT2);                                         // ??????
                if (iNow == lstT[i]) { iCnt += 1; }                     // ???????
                else { lstDup.Add(iCnt); iNow = lstT[i]; iCnt = 1; }    // ????????????
            }
            lstDup.Add(iCnt);
            long lOut = lstT2.Sum();
            long lDup = GetDupCnt(lstDup);

            // ??
            System.Console.WriteLine("{0}", lOut.ToString().Trim());
            System.Console.WriteLine("{0}", lDup.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // ???????????????
        private static long GetDupCnt(List<int> lstDup)
        {
            long lDup = 1L;
            for (int i = 0; i < lstDup.Count; i++)
            {
                if (lstDup[i] > 1)
                {
                    long lDu2 = 1L;
                    for (long j = (long)lstDup[i]; j > 1; j--)
                    {
                        lDu2 *= j;
                        lDu2 %= 1000000007L;
                    }
                    lDup *= lDu2;
                    lDup %= 1000000007L;
                }
            }
            return lDup;
        }

}