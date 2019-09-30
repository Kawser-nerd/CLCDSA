using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = Console.ReadLine().Split(' ');
            int iN = int.Parse(sS[0]);
            int iM = int.Parse(sS[1]);
            int iX = int.Parse(sS[2]);
            sS = Console.ReadLine().Split(' ');
            List<int> lstM = new List<int>();
            for (int i = 0; i < sS.Length; i++) { lstM.Add(int.Parse(sS[i])); }


            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstC = new List<int>() { 0, 0 };
            for (int i = 000001; i < iX; i++) { if (lstM.Contains(i)) { lstC[0] += 1; } }       // ????X??
            for (int i = iX + 1; i < iN; i++) { if (lstM.Contains(i)) { lstC[1] += 1; } }       // X??????
            lstC.Sort();                                                                        // ????

            // ??
            Console.WriteLine("{0}", lstC[0].ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}