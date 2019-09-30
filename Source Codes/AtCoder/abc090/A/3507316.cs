using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sOut = "";
            string sS = Console.ReadLine().Trim();
            sOut += sS.Substring(0, 1);
            sS = Console.ReadLine().Trim(); ;
            sOut += sS.Substring(1, 1);
            sS = Console.ReadLine().Trim(); ;
            sOut += sS.Substring(2, 1);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
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