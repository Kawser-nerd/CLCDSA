using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sInp[0]);
            int iM = int.Parse(sInp[1]);
            List<List<int>> lstSmp = new List<List<int>>();             // ??
            for (int i = 0; i < iN; i++)
            {
                lstSmp.Add(new List<int>());
            }
            for (int i = 0; i < iM; i++)
            {
                sInp = Console.ReadLine().Trim().Split(' ');
                int iA = int.Parse(sInp[0]) - 1;
                int iB = int.Parse(sInp[1]) - 1;
                lstSmp[iA].Add(iB);                                     // ????
                lstSmp[iB].Add(iA);                                     // ????(?????)
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<List<int>> lstRet = new List<List<int>>();                                                 // ???????
            for (int i = 0; i < iN; i++)
            {
                lstRet.Add(new List<int>());
            }
            for (int i = 0; i < lstSmp.Count; i++)                                                          // ????
            {
                for (int j = 0; j < lstSmp[i].Count; j++)                                                   // ???
                {
                    for (int k = 0; k < lstSmp[lstSmp[i][j]].Count; k++)                                    // ?????
                    {
                        if (lstSmp[lstSmp[i][j]][k] != i)                                                   // ?????
                        {
                            Boolean bEx = false;
                            for (int m = 0; m < lstSmp[i].Count; m++)
                            {
                                if (lstSmp[lstSmp[i][j]][k] == lstSmp[i][m]) { bEx = true;  break; }        // ?????
                            }
                            if (!bEx) { if (!lstRet[i].Contains(lstSmp[lstSmp[i][j]][k])) { lstRet[i].Add(lstSmp[lstSmp[i][j]][k]); } }     // ???????????????????
                        }
                    }
                }
            }

            //??
            for (int i = 0; i < lstRet.Count; i++)
            {
                Console.WriteLine("{0}", lstRet[i].Count.ToString());                                       // ???????
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            for (int i = 0; i < lstSmp.Count; i++)
            {
                string sOut2 = "";
                for (int j = 0; j < lstSmp[i].Count; j++)
                {
                    sOut2 += (lstSmp[i][j] + 1).ToString() + ",";
                }
                Console.WriteLine("{0}?{1}",( i + 1).ToString("00"), sOut2.ToString());
            }
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}