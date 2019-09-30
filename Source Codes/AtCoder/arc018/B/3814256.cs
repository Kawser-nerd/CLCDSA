using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
        private static int iN = 0;
        private static int iK = 3;

    static void Main(string[] args)
    {
            // ??
            string s2 = System.Console.ReadLine().Trim();
            iN = int.Parse(s2);
            List<ClsPos> lstPos = new List<ClsPos>();
            for (int i = 0; i < iN; i++)
            {
                string[] sS = System.Console.ReadLine().Trim().Split(' ');
                lstPos.Add(new ClsPos() { iX = long.Parse(sS[0]), iY = long.Parse(sS[1]) });
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            List<List<int>> lstCmp = new List<List<int>>();         // ????
            List<int> lstTmp = new List<int>();                     // ?????
            GetCom(lstCmp, lstTmp);                                 // ??????  ??Index???0???
            for (int i = 0; i < lstCmp.Count; i++)
            {
                long iTmp = 0L;
                long iX1 = (lstPos[lstCmp[i][0]].iX - lstPos[lstCmp[i][2]].iX);
                long iY1 = (lstPos[lstCmp[i][1]].iY - lstPos[lstCmp[i][2]].iY);
                long iX2 = (lstPos[lstCmp[i][1]].iX - lstPos[lstCmp[i][2]].iX);
                long iY2 = (lstPos[lstCmp[i][0]].iY - lstPos[lstCmp[i][2]].iY);
                iTmp = Math.Abs(iX1 * iY1 - iX2 * iY2);
                if (iTmp != 0 && iTmp % 2 == 0) { iOut += 1; }
            }

            // ??
            System.Console.WriteLine("{0}", iOut.ToString().Trim());

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

        // ?
        private class ClsPos
        {
            public long iX { get; set; } = 0;
            public long iY { get; set; } = 0;
        }

}