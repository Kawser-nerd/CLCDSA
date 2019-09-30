using System;
using System.Collections.Generic;
using System.Linq;
class Program
{

        private static int iN = 5;
        private static int iK = 3;

    static void Main(string[] args)
    {

            // ???
            List<List<int>> lstCmp = new List<List<int>>();     // ????
            List<int> lstTmp = new List<int>();                 // ?????
            GetCom(lstCmp, lstTmp);                             // ??????

            // ??
            List<int> lstSmp = new List<int>();                 // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            for (int i = 0; i < sS.Length; i++)
            {
                lstSmp.Add(int.Parse(sS[i]));
            }


            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstRet = new List<int>();                 // ??
            for (int i = 0; i < lstCmp.Count; i++)
            {
                int iSum = 0;
                for (int j = 0; j < lstCmp[i].Count; j++)
                {
                    iSum += lstSmp[lstCmp[i][j]];
                }
                lstRet.Add(iSum);
            }
            lstRet = lstRet.Distinct().ToList();
            lstRet.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });     // ??

            // ??
            Console.WriteLine("{0}", lstRet[2].ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

        private static void GetCom(List<List<int>> lstCmp, List<int> lstTmp)
        {
            for (int j = 0; j < iN; j++)
            {
                int iKn = 1;
                List<int> lstTm2 = new List<int>();
                lstTm2.AddRange(lstTmp);
                lstTm2.Add(j);
                GetCo2(lstCmp, lstTm2, j, iKn);
            }
        }

        private static void GetCo2(List<List<int>> lstCmp, List<int> lstTmp, int i, int iKn)
        {
            if (iKn == iK) { lstCmp.Add(lstTmp); return; }
            for (int j = i + 1; j < iN; j++)
            {
                List<int> lstTm2 = new List<int>();
                lstTm2.AddRange(lstTmp);
                lstTm2.Add(j);
                GetCo2(lstCmp, lstTm2, j, iKn + 1);
            }
        }

}