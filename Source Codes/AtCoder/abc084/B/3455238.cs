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
            sS = Console.ReadLine().Trim().Split('-');

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "Yes";
            int iTmp = 0;
            if (sS.Length != 2) { sOut = "No"; }
            if (sOut == "Yes" && sS[0].Length != iA) { sOut = "No"; }
            if (sOut == "Yes" && sS[1].Length != iB) { sOut = "No"; }
            if (sOut == "Yes" && !int.TryParse(sS[0], out iTmp)) { sOut = "No"; }
            if (sOut == "Yes" && !int.TryParse(sS[1], out iTmp)) { sOut = "No"; }

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