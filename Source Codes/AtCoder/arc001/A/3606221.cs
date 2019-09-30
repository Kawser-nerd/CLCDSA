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
            long iN = long.Parse(sS);
            sS = System.Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstR = new List<int>() { 0, 0, 0, 0 };
            for (int i = 0; i < sS.Length; i++)
            {
                lstR[int.Parse(sS.Substring(i, 1)) - 1] += 1;
            }
            lstR.Sort();

            // ??
            string sOut = lstR[3] + " " + lstR[0];
            System.Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}