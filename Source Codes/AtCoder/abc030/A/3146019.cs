using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sN = Console.ReadLine().Trim().Split(' ');
            double dA = double.Parse(sN[0]);
            double dB = double.Parse(sN[1]);
            double dC = double.Parse(sN[2]);
            double dD = double.Parse(sN[3]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            double dTk = dB / dA;
            double dAo = dD / dC;
            string sOut = "AOKI";
            if (dTk == dAo) { sOut = "DRAW"; }
            else if (dTk > dAo) { sOut = "TAKAHASHI"; }

            // ??
            Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}