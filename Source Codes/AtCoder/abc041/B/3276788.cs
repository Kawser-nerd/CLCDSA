using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            long lA = long.Parse(sInp[0]);
            long lB = long.Parse(sInp[1]);
            long lC = long.Parse(sInp[2]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            long lOut = 0L;
            lOut = (((lA * lB) % 1000000007L) * lC ) % 1000000007L;

            // ??
            Console.WriteLine("{0}", lOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}