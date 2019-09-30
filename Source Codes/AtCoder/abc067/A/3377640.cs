using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int iA = int.Parse(sS[0]);
            int iB = int.Parse(sS[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "Impossible";
            if (iA % 3 == 0) { sOut = "Possible"; }
            if (iB % 3 == 0) { sOut = "Possible"; }
            if ((iA + iB) % 3 == 0) { sOut = "Possible"; }

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