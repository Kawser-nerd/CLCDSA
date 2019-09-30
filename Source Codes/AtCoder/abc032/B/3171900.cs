using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string sS =Console.ReadLine().Trim();
            int iK = int.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<string> lstSmp = new List<string>();
            for (int i = 0; i < sS.Length - iK + 1; i++)
            {
                lstSmp.Add(sS.Substring(i, iK));
            }
            lstSmp = lstSmp.Distinct().ToList();

            // ??
            Console.WriteLine("{0}", lstSmp.Count.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}