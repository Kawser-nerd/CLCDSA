using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = System.Console.ReadLine().Trim();
            double iN = double.Parse(sS);
            sS = System.Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            sS = sS.Replace("F", "E");                          // E????
            double dOut = 0D;
            double dSum = 0D;
            for (int i = 0; i < sS.Length; i++)
            {
                dSum += 4 - (sS.Substring(i, 1)[0] - 'A');
            }
            dOut = dSum / iN;

            // ??
            System.Console.WriteLine("{0}", dOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}