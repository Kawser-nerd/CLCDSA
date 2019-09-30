using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string sS = Console.ReadLine().Trim();
            int iA = int.Parse(sS);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstSmp = new List<int>();
            for (int i = 1; i <= iA / 2; i++)
            {
                lstSmp.Add(i * (iA - i));
            }
            lstSmp.Sort(delegate (int mca1, int mca2) { return mca2 - mca1; });     // ??

            // ??
            Console.WriteLine("{0}", lstSmp[0].ToString());


            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}