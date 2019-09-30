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

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iJ = iN / 10;
            int iM = iN % 10;
            int iV = iJ * 100 + (iN - iJ * 10) * 15;
            if (iM == 0) { iV = iJ * 100; }
            if (iM > 6) { iV = (iJ + 1) * 100; }

            // ??
            System.Console.WriteLine("{0}", iV.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}