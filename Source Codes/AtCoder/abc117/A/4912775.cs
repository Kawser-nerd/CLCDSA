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
            decimal iT = decimal.Parse(sS[0]);
            decimal iX = decimal.Parse(sS[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            decimal iA = iT / iX;

            // ??
            System.Console.WriteLine("{0}", iA.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}