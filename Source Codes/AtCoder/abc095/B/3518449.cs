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
            int iN = int.Parse(sS[0]);
            int iX = int.Parse(sS[1]);
            List<int> lstM = new List<int>();
            for (int i = 0; i < iN; i++) { lstM.Add(int.Parse(Console.ReadLine().Trim())); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstM.Sort();
            int iOut = lstM.Count + (iX - lstM.Sum()) / lstM[0];

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