using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string sS = Console.ReadLine().Trim();
            int iN = int.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<string> lstSmp = new List<string>();
            for (int i = 0; i < sS.Length; i++)
            {
                for (int j = 0; j < sS.Length; j++)
                {
                    lstSmp.Add(sS.Substring(i, 1) + sS.Substring(j, 1));
                }
            }

            // ??
            Console.WriteLine("{0}", lstSmp[iN - 1].ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}