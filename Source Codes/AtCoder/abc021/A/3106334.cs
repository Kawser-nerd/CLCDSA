using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string sInp = Console.ReadLine().Trim();
            int iN = int.Parse(sInp);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstSmp = GetDouble(iN);
            List<int> lstRet = new List<int>();
            for (int i = lstSmp.Count - 1; i >= 0; i--)
            {
                Boolean bEnd = false;
                while (true)
                {
                    if (iN == 0) { bEnd = true; break; }
                    if (iN >= lstSmp[i]) { lstRet.Add(lstSmp[i]); iN -= lstSmp[i]; }
                    else { break; }
                }
                if (bEnd) { break; }
            }


            // ??
            Console.WriteLine("{0}", lstRet.Count.ToString());
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

        // 2????
        private static List<int> GetDouble(int iM)
        {
            List<int> lstSmp = new List<int>();
            int iP = 0;
            while (true)
            {
                int iR = (int)Math.Pow(2, iP);
                if (iR > iM) { break; }
                lstSmp.Add(iR);
                iP += 1;
            }
            return lstSmp;
        }

}