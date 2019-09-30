using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string sInp = Console.ReadLine().Trim();
            int iN = int.Parse(sInp);
            List<int> lstSmp = new List<int>();
            for (int i = 0; i < iN; i++)
            {
                int iP = int.Parse(Console.ReadLine().Trim());
                if (!lstSmp.Contains(iP))                                                       // ????
                {
                    lstSmp.Add(iP);
                }
            }
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstSmp.Sort();
            lstSmp.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });          // ??

            //??
            Console.WriteLine("{0}", lstSmp[1].ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}