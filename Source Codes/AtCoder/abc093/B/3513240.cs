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
            int iA1 = int.Parse(sS[0]);
            int iB2 = int.Parse(sS[1]);
            int iKK = int.Parse(sS[2]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iA2 = iA1 + iKK - 1 > iB2 ? iB2 : iA1 + iKK - 1;
            int iB1 = iB2 - iKK + 1 < iA1 ? iA1 : iB2 - iKK + 1;
            List<int> lstC = new List<int>();
            for (int i = iA1; i <= iA2; i++) { lstC.Add(i); }
            for (int i = iB1; i <= iB2; i++) { lstC.Add(i); }
            lstC = lstC.Distinct().ToList();

            // ??
            for (int i = 0; i < lstC.Count; i++) { Console.WriteLine("{0}", lstC[i].ToString().Trim()); }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}