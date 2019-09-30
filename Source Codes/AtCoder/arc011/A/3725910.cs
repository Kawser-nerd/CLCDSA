using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            int iM = int.Parse(sS[0]);      // ????????
            int iN = int.Parse(sS[1]);      // ?????????
            int iS = int.Parse(sS[2]);      // ?????

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = iS;                  // ??
            int iZan = 0;                   // ???????
            while (true)
            {
                int iKai = iS + iZan;       // ??
                iS = 0;                     // ??????
                while (true)
                {
                    if (iKai - iM >= 0)     // ????????
                    {
                        iKai -= iM;         // ???????????
                        iOut += iN;         // ??????????
                        iS += iN;           // ???????????
                    }
                    else { break; }         // ???????
                }
                iZan = iKai;                // ???????
                if (iS == 0) { break; }     // ???0???
            }

            // ??
            System.Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}