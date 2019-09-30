using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string sS = Console.ReadLine().Trim();
            int iN = int.Parse(sS);
            List<double> lstSmp = new List<double>();
            for (int i = 0; i < iN; i++)
            {
                lstSmp.Add(double.Parse(Console.ReadLine().Trim()));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            double dSum = 0d;
            lstSmp.Sort(delegate (double mca1, double mca2) { return (int)(mca2 - mca1); });     // ??
            for (int i = 0; i < lstSmp.Count; i++)
            {
                dSum += (i % 2 == 0 ? 1 : -1 ) * Math.Pow(lstSmp[i], 2);
            }
            dSum *= Math.PI;

            // ??
            Console.WriteLine("{0}", dSum.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}