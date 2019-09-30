using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sTmp = "";
            for (int i = 1; i < sS.Length ; i++)
            {
                sTmp = sS.Substring(0, sS.Length - i);
                if (chkDup(sTmp)) { break; }
            }

            //??
            Console.WriteLine("{0}", sTmp.Length.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
        // ????
        private static Boolean chkDup(string sTmp)
        {
            Boolean bDup = false;
            if (sTmp.Length > 0 && sTmp.Length % 2 == 0)               // ??????????
            {
                int iHaf = sTmp.Length / 2;
                string sTm1 = sTmp.Substring(0, iHaf);
                string sTm2 = sTmp.Substring(iHaf, iHaf);
                if (sTm1 == sTm2) { bDup = true; }
            }
            return bDup;
        }

}