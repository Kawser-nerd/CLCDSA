using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "yes";
            for (int i = 0; i < sS.Length; i++)             //    3
            {                                               // 0123456
                string sOne = sS.Substring(i, 1);           // abcdefg
                string sZan = sS.Substring(0, i) + ((i >= sS.Length - 1) ? "": sS.Substring(i + 1, sS.Length - (i + 1)));
                if (sZan.Contains(sOne)) { sOut = "no"; break; }
            }

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