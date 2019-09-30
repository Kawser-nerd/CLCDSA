using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            long iA = long.Parse(sS[0]);
            long iK = long.Parse(sS[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            long iCnt = 0;
            long iMax = 2000000000000;
            if (iA < iMax)
            {
                if (iK == 0)
                {
                    iCnt = iMax - iA;
                } 
                else
                {
                    while (true)
                    {
                        iA += iA * iK + 1;
                        iCnt += 1;
                        if (iA >= iMax) { break; }
                    }
                }
            }

            // ??
            System.Console.WriteLine("{0}", iCnt.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}