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
            int iH = int.Parse(sS[0]);
            int iW = int.Parse(sS[1]);
            List<string> lstInp = new List<string>();
            for (int i = 0; i < iH; i++)
            {
                lstInp.Add(Console.ReadLine().Trim());
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            // ??
            for (int i = 0; i < lstInp.Count; i++)
            {
                Console.WriteLine("{0}", lstInp[i].ToString());
                Console.WriteLine("{0}", lstInp[i].ToString());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}