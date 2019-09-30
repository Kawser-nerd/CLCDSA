using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = sS[0];
            if (sS[0] == sS[1]) { sOut = sS[2]; }
            if (sS[0] == sS[2]) { sOut = sS[1]; }

            // ??
            Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}