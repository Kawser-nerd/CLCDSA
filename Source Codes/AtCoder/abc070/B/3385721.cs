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
            int iOut = 0;                                                           // ????6????
            if (iB <= iC) { }                                                       // ?????
            if (iA <= iC && iC <= iB && iB <= iD)             { iOut = iB - iC; }   // ?????
            if (iA <= iC && iC <= iB && iA <= iD && iD <= iB) { iOut = iD - iC; }   // ??
            if (iD <= iA) { }                                                       // ?????
            if (iC <= iA && iA <= iD && iD <= iB)             { iOut = iD - iA; }   // ?????
            if (iC <= iA && iA <= iD && iC <= iB && iB <= iD) { iOut = iB - iA; }   // ??

            //??
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