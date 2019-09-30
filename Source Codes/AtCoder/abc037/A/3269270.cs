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
            int iA = int.Parse(sInp[0]);
            int iB = int.Parse(sInp[1]);
            int iC = int.Parse(sInp[2]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iS = iA > iB ? iB : iA;
            int iO = iC / iS;

            // ??
            Console.WriteLine("{0}", iO.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}