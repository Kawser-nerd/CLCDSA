using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = System.Console.ReadLine().Trim();
            int iN = int.Parse(sS);
            List<int> lstInp = new List<int>();
            for (int i = 0; i < iN; i++) { lstInp.Add(int.Parse(System.Console.ReadLine().Trim())); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstCnt = new List<int>();
            int iCnt = 1;                                                   // ?????
            int iMax = lstInp.Count - 1;                                    // ?????????
            Boolean bUp = true;                                             // ???????????
            for (int i = 1; i < lstInp.Count; i++)
            {
                if (lstInp[i - 1] < lstInp[i])                              // ??
                {
                    if (bUp) { iCnt += 1; }                                 // ?????????????
                    else { lstCnt.Add(iCnt); bUp = true; iCnt = 2; }        // ??????????????????????????????????
                }
                else if (lstInp[i - 1] > lstInp[i])
                {
                    if (bUp) { bUp = false; }                               // ????????????
                    iCnt += 1;
                }
            }
            lstCnt.Add(iCnt);                                                               // ????
            lstCnt.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });      // ??

            // ??
            System.Console.WriteLine("{0}", lstCnt[0].ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}