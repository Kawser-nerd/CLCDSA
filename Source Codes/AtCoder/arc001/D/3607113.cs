using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
        private static int iN = 0;
        private static int iK = 0;

    static void Main(string[] args)
    {
            // ??
            List<List<string>> lstQ = new List<List<string>>();
            for (int i = 0; i < 8; i++)
            {
                string sS = System.Console.ReadLine().Trim();
                List<string> lstT = new List<string>();
                for (int j = 0; j < 8; j++) { lstT.Add(sS.Substring(j, 1)); }
                lstQ.Add(lstT);                                     // ?????
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<List<string>> lstN = new List<List<string>>();         // ????
            List<ClsPos> lstC = new List<ClsPos>();                     // ?????
            //lstN.AddRange(lstQ);                                      // ? ??????????Copy????
            lstCopy(lstQ, lstN);                                        // ??1???Copy
            Boolean bOK = false;                                        // ??Q??OK???
            if (ExistOKQ(lstN))                                         // ???Q??OK??
            {
                ExaminQ(lstN, lstC);                                    // ????
                iN = lstC.Count;
                iK = 5;
                List<List<int>> lstCmp = new List<List<int>>();         // ????
                List<int> lstTmp = new List<int>();                     // ?????
                GetCom(lstCmp, lstTmp);                                 // ??????  ??Index???0???
                for (int i = 0; i < lstCmp.Count; i++)
                {
                    lstN.Clear();
                    lstCopy(lstQ, lstN);                                // ??1???Copy
                    bOK = true;                                         // ??Q??OK???
                    for (int j = 0; j < lstCmp[i].Count; j++)
                    {
                        if (!ExistsQ(lstN, lstC[lstCmp[i][j]].iI, lstC[lstCmp[i][j]].iJ)) { lstN[lstC[lstCmp[i][j]].iI][lstC[lstCmp[i][j]].iJ] = "Q"; }
                        else { bOK = false; break; }
                    }
                    if (bOK) { break; }
                }
            }

            // ??
            if (bOK) { RowDisp(lstN); }
            else { System.Console.WriteLine("{0}", "No Answer".ToString().Trim()); }
            // Debug ??
            //RowDisp(lstN);
            //RowDisp(lstQ);
            //for (int i = 0; i < lstC.Count; i++)
            //{
            //    string sOut = (lstC[i].iI + 1).ToString() + " " + (lstC[i].iJ + 1).ToString();
            //    System.Console.WriteLine("{0}", sOut.ToString().Trim());
            //}
            //for (int i = 0; i < lstCmp.Count; i++)
            //{
            //    string sOut = string.Join(" ", lstCmp[i].ToArray());
            //    System.Console.WriteLine("{0}", sOut.ToString().Trim());
            //    if (i > 20) { break; }
            //}

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // Q???
        private static void SetQ(List<List<string>> lstN)
        {
            for (int i = 0; i < lstN.Count; i++)
            {
                for (int j = 0; j < lstN[i].Count; j++)
                {
                    if (lstN[i][j] == ".")
                    {
                        if (!ExistsQ(lstN, i, j)) { lstN[i][j] = "Q"; }
                    }
                }
            }
        }

        // ???Q??OK??
        private static Boolean ExistOKQ(List<List<string>> lstN)
        {
            // ???Q
            for (int i = 0; i < lstN.Count; i++)
            {
                for (int j = 0; j < lstN[i].Count; j++)
                {
                    if (lstN[i][j] == "Q")
                    {
                        lstN[i][j] = ".";                                               // ??Q?.?????????????
                        if (ExistsQ(lstN, i, j)) { lstN[i][j] = "Q"; return false; }    // ?????????Q????
                        lstN[i][j] = "Q";                                               // Q????
                    }
                }
            }
            return true;
        }

        // Q????
        private static void ExaminQ(List<List<string>> lstN, List<ClsPos> lstC)
        {
            // ???????
            for (int i = 0; i < lstN.Count; i++)
            {
                for (int j = 0; j < lstN[i].Count; j++)
                {
                    if (lstN[i][j] == ".")
                    {
                        if (!ExistsQ(lstN, i, j)) { lstN[i][j] = "x"; lstC.Add(new ClsPos() { iI = i, iJ = j }); }
                    }
                }
            }
        }

        // Q????
        private static Boolean ExistsQ(List<List<string>> lstN, int i, int j)
        {
            Boolean bEx = false;
            if (lstN[i].Contains("Q")) { bEx = true; return bEx; }                                          // ???
            for (int k = 0; k < lstN.Count; k++) { if (lstN[k][j] == "Q") { bEx = true; return bEx; } }     // ???
            for (int k = 0; k < 8; k++)
            {                                                                                               // ???
                if (i + k < 08 && j + k < 08 && lstN[i + k][j + k] == "Q") { bEx = true; return bEx; }      // ??
                if (i + k < 08 && j - k > -1 && lstN[i + k][j - k] == "Q") { bEx = true; return bEx; }      // ??
                if (i - k > -1 && j - k > -1 && lstN[i - k][j - k] == "Q") { bEx = true; return bEx; }      // ??
                if (i - k > -1 && j + k < 08 && lstN[i - k][j + k] == "Q") { bEx = true; return bEx; }      // ??
            }
            return bEx;
        }

        // Disp
        private static void RowDisp(List<List<string>> lstS)
        {
            for (int i = 0; i < lstS.Count; i++)
            {
                string sOut = string.Join("", lstS[i].ToArray());
                System.Console.WriteLine("{0}", sOut.ToString().Trim());
            }
        }

        // ListCopy
        private static void lstCopy(List<List<string>> lstS, List<List<string>> lstD)
        {
            for (int i = 0; i < lstS.Count; i++)
            {
                List<string> lstT = new List<string>();
                lstT.AddRange(lstS[i]);                     // 1???????Copy?????
                lstD.Add(lstT);
            }
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

        // ??
        private class ClsPos
        {
            public int iI { get; set; } = 0;
            public int iJ { get; set; } = 0;
            public int iS { get; set; } = 0;
        }

}