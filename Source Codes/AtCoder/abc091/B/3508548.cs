using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<string> lstN = new List<string>();
            List<string> lstM = new List<string>();
            int iN = int.Parse(Console.ReadLine().Trim());
            for (int i = 0; i < iN; i++) { lstN.Add(Console.ReadLine().Trim()); }
            int iM = int.Parse(Console.ReadLine().Trim());
            for (int i = 0; i < iM; i++) { lstM.Add(Console.ReadLine().Trim()); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            lstN.Sort();
            lstM.Sort();
            List<int> lstC = new List<int>();
            for (int i = 0; i < iN; i++)
            {
                lstC.Add(lstN.Count(x => x == lstN[i]) - lstM.Count(x => x == lstN[i]));          // Linq?List?????
            }
            lstC.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });              // ??
            iOut = lstC[0] < 0 ? 0 : lstC[0];

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