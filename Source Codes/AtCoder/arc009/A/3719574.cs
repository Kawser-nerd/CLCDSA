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
            int iN = int.Parse(sS[0]);
            int iSum = 0;
            for (int i = 0; i < iN; i++)
            {
                sS = System.Console.ReadLine().Trim().Split(' ');
                iSum += int.Parse(sS[0]) * int.Parse(sS[1]);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            iSum = (int)((double)iSum * 1.05D);

            // ??
            System.Console.WriteLine("{0}", iSum.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}