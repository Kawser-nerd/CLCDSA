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
            int iA = int.Parse(sS[0]);
            int iB = int.Parse(sS[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            Boolean bAPls = iA > 0 ? true : false;
            Boolean bBPls = iB > 0 ? true : false;
            int iOut = 0;
            if (bAPls == bBPls) { iOut = iB - iA; }
            else { iOut = iB - iA - 1; }

            // ??
            System.Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}