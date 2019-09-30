using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            List<double> lstInp = new List<double>();
            lstInp.Add(double.Parse(sS[0]));
            lstInp.Add(double.Parse(sS[1]));

            // ??
            int iOut = (int)Math.Ceiling(lstInp.Average());

            // ??
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