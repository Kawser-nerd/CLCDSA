using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<string> lstG = new List<string>() { "I", "C", "T"};
            
            // ??
            string sS = System.Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "NO";
            int j = 0;
            sS = sS.ToUpper();
            for (int i = 0; i < sS.Length; i++)
            {
                if (sS.Substring(i, 1) == lstG[j]) { j += 1; if (j == 3) { sOut = "YES"; break; } }
            }

            // ??
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