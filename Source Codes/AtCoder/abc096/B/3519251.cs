using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<int> lstS = new List<int>();
            string[] sS = Console.ReadLine().Trim().Split(' ');
            lstS.Add(int.Parse(sS[0]));
            lstS.Add(int.Parse(sS[1]));
            lstS.Add(int.Parse(sS[2]));
            sS = Console.ReadLine().Trim().Split(' ');
            int iK =  int.Parse(sS[0]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstS.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });  // ??
            for (int i = 0; i < iK; i++) { lstS[0] *= 2; }

            // ??
            Console.WriteLine("{0}", lstS.Sum().ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}