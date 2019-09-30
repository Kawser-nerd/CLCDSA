using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<int> lstA = new List<int>();
            List<int> lstB = new List<int>();
            lstA.Add(int.Parse(Console.ReadLine().Trim()));
            lstA.Add(int.Parse(Console.ReadLine().Trim()));
            lstB.Add(int.Parse(Console.ReadLine().Trim()));
            lstB.Add(int.Parse(Console.ReadLine().Trim()));

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstA.Sort();
            lstB.Sort();
            int iOut = lstA[0] + lstB[0];

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