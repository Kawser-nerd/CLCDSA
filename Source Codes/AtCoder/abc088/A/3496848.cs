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
            int iN = int.Parse(sS);
            sS = Console.ReadLine().Trim();
            int iA = int.Parse(sS);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "No";
            if (iN % 500 <= iA) { sOut = "Yes"; }

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