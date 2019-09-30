using System;
using System.Collections.Generic;
using System.Linq;
class Program
{

    private static int iN = 0;
    private static int iK = 0;

    static void Main(string[] args)
    {

            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            iN = int.Parse(sInp[0]);
            iK = int.Parse(sInp[1]);
            List<List<int>> lstSmp = new List<List<int>>();
            for (int i = 0; i < iN; i++)
            {
                sInp = Console.ReadLine().Trim().Split(' ');
                List<int> oneUsr = new List<int>();
                for (int j = 0; j < iK; j++)
                {
                    oneUsr.Add(int.Parse(sInp[j]));
                }
                lstSmp.Add(oneUsr);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<List<int>> lstCmp = new List<List<int>>();     // ????
            List<int> lstTmp = new List<int>();
            int iNn = iN;
            GetCom(lstCmp, lstTmp, iNn);                        // ??????
            string sOut = "Nothing";

            for (int i = 0; i < lstCmp.Count; i++)
            {
                int iR = 0;
                for (int j = 0; j < lstCmp[i].Count; j++)
                {
                    iR = iR ^ lstSmp[j][lstCmp[i][j]];          // ?????XOR
                }
                if (iR == 0) { sOut = "Found"; break; }
            }

            //??
            Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            for (int i = 0; i < lstCmp.Count; i++)
            {
                string sOut2 = "";
                for (int j = 0; j < lstCmp[i].Count; j++)
                {
                    sOut2 += lstCmp[i][j].ToString() + ",";
                }
                Console.WriteLine("{0}", sOut2.ToString());
            }

            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

        private static void GetCom(List<List<int>> lstCmp, List<int> lstTmp, int iNn)
        {
            iNn -= 1;
            if (iNn <= 0)
            {
                for (int i = 0; i < iK; i++)
                {
                    List<int> lstTm2 = new List<int>();
                    lstTm2.AddRange(lstTmp);
                    lstTm2.Add(i);
                    lstCmp.Add(lstTm2);
                }
            }
            else
            {
                for (int i = 0; i < iK; i++)
                {
                    List<int> lstTm2 = new List<int>();
                    lstTm2.AddRange(lstTmp);
                    lstTm2.Add(i);
                    GetCom(lstCmp, lstTm2, iNn);
                }
            }
        }

}