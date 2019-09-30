using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            int[] iAryA = new int[] { 1, 3, 5, 7, 8, 10, 12, };
            int[] iAryB = new int[] { 4, 6, 9, 11, };

            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int ix = int.Parse(sS[0]);
            int iy = int.Parse(sS[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "No";
            if (ix == 2 || iy == 2) { sOut = "No"; }
            else if (iAryA.Contains(ix) && iAryA.Contains(iy)) { sOut = "Yes"; }
            else if (iAryB.Contains(ix) && iAryB.Contains(iy)) { sOut = "Yes"; }

            //??
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