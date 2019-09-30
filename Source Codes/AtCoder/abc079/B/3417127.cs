using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            int iN = int.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<long> lstLuc = new List<long>();
            lstLuc.Add(2);
            lstLuc.Add(1);
            for (int i = 2; i <= iN; i++)
            {
                lstLuc.Add(lstLuc[i - 2] + lstLuc[i - 1]);
            }

            // ??
            Console.WriteLine("{0}", lstLuc[iN].ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}