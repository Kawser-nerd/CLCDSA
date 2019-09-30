using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = System.Console.ReadLine().Trim().PadLeft(4, '0');
            sS += "/" + System.Console.ReadLine().Trim().PadLeft(2, '0');
            sS += "/" + System.Console.ReadLine().Trim().PadLeft(2, '0');

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            DateTime dtA = DateTime.Parse(sS);
            DateTime dtB = DateTime.Parse("2014/05/17");
            TimeSpan tDf = dtB - dtA;

            // ??
            System.Console.WriteLine("{0}", tDf.Days.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}