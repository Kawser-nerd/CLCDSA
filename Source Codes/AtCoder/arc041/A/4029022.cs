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
            int iX = int.Parse(sS[0]);
            int iY = int.Parse(sS[1]);
            sS = System.Console.ReadLine().Trim().Split(' ');
            int iK = int.Parse(sS[0]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iZZ = iY - iK;
            if (iZZ >= 0) { iX += iK; }
            else { iX += iY; iX += iZZ; }

            // ??
            System.Console.WriteLine("{0}", iX.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}