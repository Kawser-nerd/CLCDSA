using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sS = Console.ReadLine().Trim();
            int iN = int.Parse(sS);
            List<int> lstsS = new List<int>();
            for (int i = 0; i < iN; i++)
            {
                lstsS.Add(int.Parse(Console.ReadLine().Trim()));
            }
            //// debug
            //int iN = 100000;                                  // 10?????
            //List<int> lstsS = new List<int>();
            //for (int i = 1; i <= iN; i++)
            //{
            //    lstsS.Add(i);
            //}

            // ??
            lstsS.Sort();                                       // ??
            int iOut = 0;                                       // ?????
            int iBak = lstsS[0];                                // ???
            int iDup = 0;                                       // ???
            for (int i = 1; i < lstsS.Count; i++)
            {
                if (lstsS[i] == iBak) { iDup += 1; }
                else
                {
                    if (iDup % 2 == 0) { iOut += 1; }           // ????????
                    iDup = 0;
                    iBak = lstsS[i];
                }
            }
            if (iDup % 2 == 0) { iOut += 1; }                   // ????????

            //??
            Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}