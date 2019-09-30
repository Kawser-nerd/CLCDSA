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
            int iQ = int.Parse(sInp[1]);
            List<ClsSmp> lstSmp = new List<ClsSmp>();
            for (int i = 0; i < iQ; i++)
            {
                sInp = Console.ReadLine().Trim().Split(' ');
                ClsSmp oneUsr = new ClsSmp();
                oneUsr.iL = int.Parse(sInp[0]) - 1;
                oneUsr.iR = int.Parse(sInp[1]) - 1;
                oneUsr.iT = int.Parse(sInp[2]);
                lstSmp.Add(oneUsr);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstOut = new List<int>();
            for (int i = 0; i < iN; i++) { lstOut.Add(0); }
            for (int i = 0; i < lstSmp.Count; i++)
            {
                for (int j = lstSmp[i].iL; j <= lstSmp[i].iR; j++) { lstOut[j] = lstSmp[i].iT; }
            }

            // ??
            for (int i = 0; i < lstOut.Count; i++)
            {
                Console.WriteLine("{0}", lstOut[i].ToString());
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
            public int iL { get; set; }
            public int iR { get; set; }
            public int iT { get; set; }
        }
}