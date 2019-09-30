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
            int iX1 = int.Parse(sS[0]);
            int iY1 = int.Parse(sS[1]);
            int iX2 = int.Parse(sS[2]);
            int iY2 = int.Parse(sS[3]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iX3 = iX2 - (iY2 - iY1);
            int iY3 = iY2 + (iX2 - iX1);
            int iX4 = iX1 - (iY2 - iY1);
            int iY4 = iY1 + (iX2 - iX1);

            // ??
            string sOut = iX3.ToString() + " " + iY3.ToString() + " " + iX4.ToString() + " " + iY4.ToString();
            System.Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}