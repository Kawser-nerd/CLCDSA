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
            int iN = int.Parse(sS[0]);
            sS = Console.ReadLine().Trim().Split(' ');
            int iK = int.Parse(sS[0]);
            sS = Console.ReadLine().Trim().Split(' ');
            List<int> lstInp = new List<int>();
            for (int i = 0; i < sS.Length; i++) { lstInp.Add(int.Parse(sS[i])); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            for (int i = 0; i < lstInp.Count; i++)
            {
                List<int> lstBuf = new List<int>();
                lstBuf.Add(lstInp[i]);
                lstBuf.Add(iK - lstInp[i]);
                iOut += lstBuf.Min() * 2;
            }

            // ??
            Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}