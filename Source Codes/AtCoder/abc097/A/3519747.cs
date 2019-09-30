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
            int iC = int.Parse(sS[2]);
            int iD = int.Parse(sS[3]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "No";
            if (Math.Abs(iA - iC) <= iD) { sOut = "Yes"; }
            else
            {
                int iOk = 0;
                if (Math.Abs(iA - iB) <= iD) { iOk += 1; }
                if (Math.Abs(iB - iC) <= iD) { iOk += 1; }
                if (iOk >= 2) { sOut = "Yes"; }
            }

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