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
            int iS = int.Parse(sS);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iC = 1;
            while (true)
            {
                if (iS == 1) { break; }
                iC += 1; 
                if (iS % 2 == 0) { iS /= 2; }
                else { iS = iS * 3 + 1; }
            }
            if (iC == 1 || iC == 2) { iC = 4; }
            else { iC += 1; }

            // ??
            System.Console.WriteLine("{0}", iC.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}