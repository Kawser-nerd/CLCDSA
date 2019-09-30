using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string sInp = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            Boolean bDef = false;
            char[] sS = sInp.ToArray();
            for (int i = 0; i < sS.Length - 1; i++)
            {
                if (sS[i] != sS[i + 1]) { bDef = true; break; }
            }
            string sOut = "SAME";
            if (bDef) { sOut = "DIFFERENT"; }

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