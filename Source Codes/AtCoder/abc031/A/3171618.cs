using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sN = Console.ReadLine().Trim().Split(' ');
            int iA = int.Parse(sN[0]);
            int iD = int.Parse(sN[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iAml = (iA + 1) * iD;
            int iDml = iA * (iD + 1);
            int iRml = iAml;
            if (iAml < iDml) { iRml = iDml; }

            // ??
            Console.WriteLine("{0}", iRml.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}