using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
            // ???
            List<ClsSrc> lstSrc = new List<ClsSrc>();
            List<ClsSrc> lstS10 = new List<ClsSrc>();
            GetSrc(lstSrc, lstS10);

            // ??
            string sN = Console.ReadLine().Trim();
            long lN = long.Parse(sN);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            long lRet = 0;
            // ??????????????
            for (int j = 0; j < lstSrc.Count; j++) { if (lstSrc[j].lD == lN) { lRet = lstSrc[j].lC; break; } }
            if (lRet == 0)
            {
                long lM = sN.Length;                                        // ????
                for (int i = 1; i <= lM; i++)                               // ??????
                {
                    long lK = lM - i + 1;                                   // ????
                    long lI = long.Parse(sN.Substring(i - 1, 1));           // ?????
                    long lJ = lI * (long)Math.Pow(10, lK - 1);              // ????? * 10 ^ (???? - 1)
                    long lD = 01 * (long)Math.Pow(10, lK - 1);              //          1 * 10 ^ (???? - 1)
                    long lC = 0; for (int j = 0; j < lstSrc.Count; j++) { if (lstSrc[j].lD == lD) { lC = lstSrc[j].lC; break; } }   // ????1?????
                    switch (lI)
                    {
                        case 0L:
                            break;
                        case 1L:
                            lRet += lD == 1 ? 1: (lN % lD) + (lC - 1) + 1;  // ???1????? +1
                            break;
                        default:
                            lRet += lD + (lC - 1) * lI;
                            break;
                    }
                }
            }

            // ??
            Console.WriteLine("{0}", lRet.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

        // ????????
        private static void GetSrc(List<ClsSrc> lstSrc, List<ClsSrc> lstS10)
        {
            for (int i = 0; i < 10; i++)
            {
                ClsSrc oneUsr = new ClsSrc();
                oneUsr.lD = (long)Math.Pow(10,i);
                oneUsr.lC = i * oneUsr.lD /10 + 1;
                lstSrc.Add(oneUsr);
            }
        }

        // ??????
        private class ClsSrc
        {
            public long lD { get; set; } = 0;
            public long lC { get; set; } = 0;
        }

}