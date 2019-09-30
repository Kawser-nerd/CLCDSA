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

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "!";
            if (iA + iB == iC && iA - iB == iC) { sOut = "?"; }
            else if (iA + iB == iC) { sOut = "+"; }
            else if (iA - iB == iC) { sOut = "-"; }

            //??
            Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}