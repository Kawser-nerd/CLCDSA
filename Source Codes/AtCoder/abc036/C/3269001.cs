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
            List<int> lstInp = new List<int>();
            for (int i = 0; i < iN; i++)
            {
                lstInp.Add(int.Parse(Console.ReadLine().Trim()));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstCmp = new List<int>();
            lstCmp = lstInp.Distinct().ToList();
            lstCmp.Sort();
            Dictionary<int, int> DicCmp = new Dictionary<int, int>();
            for (int i = 0; i < lstCmp.Count; i++)
            {
                DicCmp.Add(lstCmp[i], i);
            }
            for (int i = 0; i < lstInp.Count; i++)
            {
                lstInp[i] = DicCmp[lstInp[i]];
            }

            // ??
            for (int i = 0; i < lstInp.Count; i++)
            {
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