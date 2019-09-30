using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            string[] s2 = System.Console.ReadLine().Trim().Split(' ');

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstInp = new List<int>();
            for (int i = 0; i < 7; i++)
            {
                int iD = int.Parse(sS[i]);
                int iJ = int.Parse(s2[i]);
                lstInp.Add(iD >= iJ ? iD: iJ);
            }

            // ??
            System.Console.WriteLine("{0}", lstInp.Sum().ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}