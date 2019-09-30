using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            Dictionary<string, string> dicPra = new Dictionary<string, string>()
            { { "R",  "01,00" },
              { "L",  "-1,00" },
              { "U",  "00,-1" },
              { "D",  "00,01" },
              { "RU", "01,-1" },
              { "RD", "01,01" },
              { "LU", "-1,-1" },
              { "LD", "-1,01" },
            };

            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            int iX = int.Parse(sS[0]) - 1;
            int iY = int.Parse(sS[1]) - 1;
            string sW = sS[2];
            List<List<int>> lstInp = new List<List<int>>();
            for (int i = 0; i < 9; i++) { lstInp.Add(new List<int>() { 0, 0, 0, 0, 0, 0, 0, 0, 0, }); }
            for (int i = 0; i < 9; i++)
            {
                string s2 = System.Console.ReadLine().Trim();
                for (int j = 0; j < 9; j++)
                {
                    lstInp[i][j] = int.Parse(s2.Substring(j ,1));
                }
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstOut = new List<int>();
            int iHW = 9;
            sS = dicPra[sW].Split(',');
            int iAx = int.Parse(sS[0]), iAy = int.Parse(sS[1]);
            for (int i = 0; i < 4; i++)
            {
                lstOut.Add(lstInp[iY][iX]);
                iX += iAx;
                iY += iAy;
                if (iX >= iHW) { iX -= 2; iAx = -1; }
                if (iX <= -01) { iX += 2; iAx = +1; }
                if (iY >= iHW) { iY -= 2; iAy = -1; }
                if (iY <= -01) { iY += 2; iAy = +1; }
            }

            // ??
            string sOut = "";
            for (int i = 0; i < lstOut.Count; i++) { sOut += lstOut[i].ToString(); }
            System.Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}