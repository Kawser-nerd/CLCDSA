using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{

        private static int iN = 5;
        private static int iK = 3;

    static void Main(string[] args)
    {
            // ??
            string sS = Console.ReadLine().Trim();
            int iNN = int.Parse(sS);
            List<string> lstS = new List<string>();
            for (int i = 0; i < iNN; i++) { lstS.Add(Console.ReadLine().Trim().Substring(0, 1)); }   // ??1???????
            // debug??
            //int iNN = 100000;
            //List<string> lstS = new List<string>();
            //Random rD = new Random(1000);
            //for (int i = 0; i < iNN; i++)
            //{
            //    char rN = (char)('A' + rD.Next(25));
            //    lstS.Add(new String(new char[] { rN }));
            //}

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            Decimal dOut = 0;
            //lstS.Sort();
            List<int> lstC = new List<int>();
            lstC.Add(lstS.Count(x => x == "M"));
            lstC.Add(lstS.Count(x => x == "A"));
            lstC.Add(lstS.Count(x => x == "R"));
            lstC.Add(lstS.Count(x => x == "C"));
            lstC.Add(lstS.Count(x => x == "H"));
            if (lstC.Count > 2)             // 3?????????
            {
                // ???
                iN = lstC.Count;
                List<List<int>> lstCmp = new List<List<int>>();     // ????
                List<int> lstTmp = new List<int>();                 // ?????
                GetCom(lstCmp, lstTmp);                             // ??????
                for (int i = 0; i < lstCmp.Count; i++)
                {
                    dOut += (Decimal)lstC[lstCmp[i][0]] * (Decimal)lstC[lstCmp[i][1]] * (Decimal)lstC[lstCmp[i][2]];
                }
            }

            // ??
            Console.WriteLine("{0}", dOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // ?????
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

        // ????????
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