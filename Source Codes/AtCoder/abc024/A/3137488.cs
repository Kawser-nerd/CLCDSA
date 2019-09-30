using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iA = int.Parse(sInp[0]);
            int iB = int.Parse(sInp[1]);
            int iC = int.Parse(sInp[2]);
            int iK = int.Parse(sInp[3]);
            sInp = Console.ReadLine().Trim().Split(' ');
            int iS = int.Parse(sInp[0]);
            int iT = int.Parse(sInp[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iSum = iA * iS + iB * iT;
            if (iS + iT >= iK) { iSum -= (iS + iT) * iC; }
            
            // ??
            Console.WriteLine("{0}", iSum.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}