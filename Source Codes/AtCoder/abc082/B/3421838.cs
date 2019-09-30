using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<char> lstS = new List<char>();
            List<char> lstT = new List<char>();
            string sInp = Console.ReadLine().Trim();
            lstS = sInp.ToList();
            sInp = Console.ReadLine().Trim();
            lstT = sInp.ToList();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "No";
            lstS.Sort();                                                                    // ??
            lstT.Sort(delegate (char mca1, char mca2) { return (int)(mca2 - mca1); });      // ??
            string sS = new string(lstS.ToArray());
            string sT = new string(lstT.ToArray());
            if (sS.CompareTo(sT) < 0) { sOut = "Yes"; }

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