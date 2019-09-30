using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            List<string> lstSmp = new List<string>();
            for (int j = 0; j < 12; j++)
            {
                lstSmp.Add(Console.ReadLine().Trim());
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            for (int j = 0; j < lstSmp.Count; j++)
            {
                if (lstSmp[j].Contains("r")) { iOut += 1; }
            }

            // ??
            Console.WriteLine("{0}", iOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}