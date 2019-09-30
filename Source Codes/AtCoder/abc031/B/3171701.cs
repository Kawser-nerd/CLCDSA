using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sN = Console.ReadLine().Trim().Split(' ');
            int iL = int.Parse(sN[0]);
            int iH = int.Parse(sN[1]);
            sN = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sN[0]);
            List<int> lstSmp = new List<int>();
            for (int i = 0; i < iN; i++)
            {
                lstSmp.Add(int.Parse(Console.ReadLine().Trim()));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstRet = new List<int>();
            for (int i = 0; i < lstSmp.Count; i++)
            {
                int iRet = -1;
                if (iL <= lstSmp[i] && lstSmp[i] <= iH) { iRet = 0; }
                else if (iL > lstSmp[i]) { iRet = iL - lstSmp[i]; }
                lstRet.Add(iRet);
            }

            // ??
            for (int i = 0; i < lstRet.Count; i++)
            {
                Console.WriteLine("{0}", lstRet[i].ToString());
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