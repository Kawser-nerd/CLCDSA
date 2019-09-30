using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sA = Console.ReadLine().Trim();
            string sB = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "LESS";
            int iA = sA.Length;
            int iB = sB.Length;
            int iK = iA > iB ? iA : iB;                 // ?????
            sA = sA.PadLeft(iK, '0');                   // ??????????0?????
            sB = sB.PadLeft(iK, '0');                   // ??????????0?????
            int iCmp = sA.CompareTo(sB);
            if (iCmp == 0) { sOut = "EQUAL"; }
            if (iCmp > 00) { sOut = "GREATER"; }

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