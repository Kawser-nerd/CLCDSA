using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = System.Console.ReadLine().Trim();
            int iN = int.Parse(sS);
            List<List<int>> lstInp = new List<List<int>>();
            for (int i = 0; i < iN; i++)
            {
                int[] iNum = System.Console.ReadLine().Trim().Split(' ').Select(x => int.Parse(x)).ToArray();
                lstInp.Add(iNum.ToList());
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<double> lstRet = new List<double>();
            for (int i = 0; i < lstInp.Count; i++)
            {
                double dOne = 0;
                int iJmx = lstInp[i].Count - 1;
                for (int j = 0; j < iJmx; j++) { dOne += lstInp[i][j]; }
                dOne += (double)lstInp[i][iJmx] * (110D / 900D);
                lstRet.Add(dOne);
            }

            // ??
            System.Console.WriteLine("{0}", lstRet.Max().ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}