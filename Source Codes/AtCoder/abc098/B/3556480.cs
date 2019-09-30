using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = Console.ReadLine().Trim();
            int iN = int.Parse(sS);
            sS = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstRt = new List<int>();
            for (int i = 1; i < sS.Length - 1; i++)
            {
                string sF = sS.Substring(0, i);
                string sB = sS.Substring(i, sS.Length - i);
                sF = new string(sF.ToCharArray().Distinct().ToArray());                 // char??string???  // ????????????
                sB = new string(sB.ToCharArray().Distinct().ToArray());                 // char??string???  // ????????????
                int iCnt = 0;
                for (int j = 0; j < sF.Length; j++)
                {
                    string sO = sF.Substring(j, 1);
                    if (sB.Contains(sO)) { iCnt += 1; }
                }
                lstRt.Add(iCnt);
            }
            lstRt.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });  // ??
            if (lstRt.Count == 0) { lstRt.Add(0); }

            // ??
            Console.WriteLine("{0}", lstRt[0].ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}