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
            int iSt = int.Parse(sS[0]);
            int iEd = int.Parse(sS[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            for (int i = iSt; i <= iEd; i++)
            {
                string sSrc = i.ToString();
                char[] cSrc = sSrc.ToCharArray();                       // ?????
                Array.Reverse(cSrc);                                    // ?????
                string sRev = new string(cSrc);                         // ?????
                if (sSrc == sRev) { iOut += 1; }
            }

            // ??
            Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}