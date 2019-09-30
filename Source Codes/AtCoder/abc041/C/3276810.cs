using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sInp[0]);
            sInp = Console.ReadLine().Trim().Split(' ');
            List<ClsSmp> lstSmp = new List<ClsSmp>();
            for (int i = 0; i < iN; i++)
            {
                lstSmp.Add(new ClsSmp() {iD = i + 1, iT = int.Parse(sInp[i]) });
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstSmp.Sort(delegate (ClsSmp mca1, ClsSmp mca2) { return (int)(mca2.iT - mca1.iT); });      // ??

            // ??
            for (int i = 0; i < lstSmp.Count; i++)
            {
                Console.WriteLine("{0}", lstSmp[i].iD.ToString());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        private class ClsSmp
        {
            public int iD { get; set; } = 0;
            public int iT { get; set; } = 0;
        }

}