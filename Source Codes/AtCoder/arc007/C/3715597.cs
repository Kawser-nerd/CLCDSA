using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
        private static int iN = 0;

    static void Main(string[] args)
    {
            // ??
            string sS = System.Console.ReadLine().Trim();
            iN = sS.Length;

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            sS = sS.Replace("o", "1").Replace("x", "0");
            List<List<int>> lstVie = new List<List<int>>();
            List<int> lstTmp = new List<int>();
            for (int j = 0; j < sS.Length; j++) { lstTmp.Add(int.Parse(sS.Substring(j, 1))); }
            lstVie.Add(lstTmp);
            List<int> lstZan = new List<int>();
            Boolean bIsOK = false;
            while (!bIsOK)                                              // ??1?????????
            {
                int iZan = 0;
                bIsOK = chkAllOk(lstVie, lstZan, ref iZan);
                if (bIsOK) { break; }

                List<ClsZan> lstZmx = new List<ClsZan>();
                for (int iZ = 1; iZ < iN; iZ++)                         // ?????
                {
                    List<int> lstTp2 = new List<int>();
                    for (int j = 0; j < lstVie[0].Count; j++)           // ?????
                    {
                        int iJ = j + iZ;
                        if (iJ >= iN) { iJ -= iN; }                     // ??????????
                        lstTp2.Add(lstVie[0][iJ]);                      // ???????
                    }
                    lstVie.Add(lstTp2);
                    bIsOK = chkAllOk(lstVie, lstZan, ref iZan);         // ??1?
                    if (bIsOK) { break; }
                    lstZmx.Add(new ClsZan() { iZre = iZ, iZaC = iZan });
                    lstVie.RemoveAt(lstVie.Count - 1);
                }
                if (bIsOK) { break; }                                   // ??1????
                lstZmx.Sort(delegate (ClsZan mca1, ClsZan mca2) { return (int)(mca1.iZaC - mca2.iZaC); });  // iZaC???
                List<int> lstTp3 = new List<int>();
                for (int j = 0; j < lstVie[0].Count; j++)               // ?????
                {
                    int iJ = j + lstZmx[0].iZre;
                    if (iJ >= iN) { iJ -= iN; }                         // ??????????
                    lstTp3.Add(lstVie[0][iJ]);                          // ???????
                }
                lstVie.Add(lstTp3);
            }

            // ??
            System.Console.WriteLine("{0}", lstVie.Count.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // ??1?????
        private static Boolean chkAllOk(List<List<int>> lstVie, List<int> lstZan, ref int iZan)
        {
            Boolean bRt = true;
            iZan = 0;
            lstZan.Clear();
            for (int j = 0; j < iN; j++) { lstZan.Add(0); }     // ????? x
            for (int j = 0; j < lstZan.Count; j++)              // ?????
            {
                for (int i = 0; i < lstVie.Count; i++)          // TV?
                {
                    lstZan[j] += lstVie[i][j];                  // o??
                }
            }
            for (int j = 0; j < lstZan.Count; j++)              // ?????
            {
                if (lstZan[j] == 0) { bRt = false; iZan += 1; } // x????? x??
            }
            return bRt;
        }

        // ??Zan????
        private class ClsZan
        {
            public int iZre { get; set; } = 0;                  // ???
            public int iZaC { get; set; } = 0;                  // ?x?
        }

}