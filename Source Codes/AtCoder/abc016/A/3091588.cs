using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iM = int.Parse(sInp[0]);
            int iD = int.Parse(sInp[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "NO";
            if (iM % iD == 0) { sOut = "YES"; }

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