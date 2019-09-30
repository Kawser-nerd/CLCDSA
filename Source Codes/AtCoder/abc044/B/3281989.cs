using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOrg = sS.Length;
            string sOut = "Yes";
            for (int i = 0; i < sS.Length; i++)
            {
                string sOne = sS.Substring(i, 1);
                int iTmp = sS.Replace(sOne, "").Length;
                if ((iOrg - iTmp) % 2 == 1) { sOut = "No"; break; }
            }

            // ??
            Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}