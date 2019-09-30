using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{

        private static int iN = 3;
        private static int iK = 0;

    static void Main(string[] args)
    {

            // ??
            iK = int.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<List<int>> lstCmp = new List<List<int>>();             // ???
            List<int> lstTmp = new List<int>();                         // ?????
            GetCom(lstCmp, lstTmp);                                     // ?????

            // ??
            // ??
            for (int i = 0; i < lstCmp.Count; i++)
            {
                StringBuilder sS = new StringBuilder();
                for (int j = 0; j < lstCmp[i].Count; j++)
                {
                    sS.Append(((char)(lstCmp[i][j] + 97)).ToString());
                }
                Console.WriteLine("{0}", sS.ToString());
            }

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
                GetCo2(lstCmp, lstTm2, iKn);
            }
        }

        // ??
        private static void GetCo2(List<List<int>> lstCmp, List<int> lstTmp, int iKn)
        {
            if (iKn == iK) { lstCmp.Add(lstTmp); return; }
            for (int j = 0; j < iN; j++)
            {
                List<int> lstTm2 = new List<int>();
                lstTm2.AddRange(lstTmp);
                lstTm2.Add(j);
                GetCo2(lstCmp, lstTm2, iKn + 1);
            }
        }

}