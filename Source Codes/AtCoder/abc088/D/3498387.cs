using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int iH = int.Parse(sS[0]);
            int iW = int.Parse(sS[1]);
            List<List<string>> lstS = new List<List<string>>();
            for (int i = 0; i < iH; i++)
            {
                string s2 = Console.ReadLine().Trim();
                List<string> lstT = new List<string>();
                for (int j = 0; j < iW; j++)
                {
                    lstT.Add(s2.Substring(j, 1));
                }
                lstS.Add(lstT);
            }
            lstS[0][0] = "00";
            lstS[iH - 1][iW - 1] = "G";

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            //debugDisp(lstS);
            int iOut = -1;
            GetDest(lstS, iH - 1, iW - 1, ref iOut);
            //debugDisp(lstS);
            if (iOut != -1)
            {
                Set1Route(lstS, iH - 1, iW - 1, iOut);
                //debugDisp(lstS);
                SetZanW(lstS, iH - 1, iW - 1, ref iOut);
                //debugDisp(lstS);
            }

            // ??
            Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // Debug??
        private static void debugDisp(List<List<string>> lstS)
        {
            Console.WriteLine();
            for (int i = 0; i < lstS.Count; i++)
            {
                string sOut = "";
                for (int j = 0; j < lstS[i].Count; j++)
                {
                    string s3 = (lstS[i][j] == "#" ? "##" : lstS[i][j]);
                    s3 = (s3 == "G" ? "GG" : s3);
                    s3 = (s3 == "B" ? "BB" : s3);
                    sOut += (s3 == "." ? ".." : s3);
                }
                Console.WriteLine("{0}", sOut.ToString().Trim());
            }
        }

        // ?????????
        private static void SetZanW(List<List<string>> lstS, int iH, int iW, ref int iOut)
        {
            iOut = 0;
            for (int i = 0; i < lstS.Count; i++)
            {
                for (int j = 0; j < lstS[i].Count; j++)
                {
                    if (lstS[i][j] == "G" || lstS[i][j] == "#") { }
                    else
                    {
                        lstS[i][j] = "B";           // ??
                        iOut += 1;                  // ????
                    }
                }
            }
        }

        // G??S???1??????
        private static void Set1Route(List<List<string>> lstS, int iH, int iW, int iG)
        {
            int D = iG;
            int M = lstS.Count * lstS[0].Count;
            while (true)
            {
                D -= 1; if (D < 0) { break; }
                Boolean bEx = false;
                for (int i = 0; i < lstS.Count; i++)
                {
                    for (int j = 0; j < lstS[i].Count; j++)
                    {
                        if (lstS[i][j].ToString() == D.ToString("00"))
                        {
                            if (j < iW && lstS[i + 0][j + 1] == "G") { lstS[i][j] = "G"; bEx = true; break; }
                            if (i < iH && lstS[i + 1][j + 0] == "G") { lstS[i][j] = "G"; bEx = true; break; }
                            if (j > 00 && lstS[i - 0][j - 1] == "G") { lstS[i][j] = "G"; bEx = true; break; }
                            if (i > 00 && lstS[i - 1][j - 0] == "G") { lstS[i][j] = "G"; bEx = true; break; }
                        }
                    }
                    if (bEx) { break; }
                }
                if (!bEx) { break; }        // ?????????????
            }
        }

        // S??G??????????G????????
        private static void GetDest(List<List<string>> lstS, int iH, int iW, ref int iG)
        {
            int D = -1;
            int M = lstS.Count * lstS[0].Count;
            while (true)
            {
                D += 1; if (D > M) { break; }
                Boolean bEx = false;
                for (int i = 0; i < lstS.Count; i++)
                {
                    for (int j = 0; j < lstS[i].Count; j++)
                    {
                        if (lstS[i][j].ToString() == D.ToString("00"))
                        {
                            if (j < iW && lstS[i + 0][j + 1] == ".") { lstS[i + 0][j + 1] = (D + 1).ToString("00"); }
                            if (i < iH && lstS[i + 1][j + 0] == ".") { lstS[i + 1][j + 0] = (D + 1).ToString("00"); }
                            if (j > 00 && lstS[i - 0][j - 1] == ".") { lstS[i - 0][j - 1] = (D + 1).ToString("00"); }
                            if (i > 00 && lstS[i - 1][j - 0] == ".") { lstS[i - 1][j - 0] = (D + 1).ToString("00"); }
                            if (j < iW && lstS[i + 0][j + 1] == "G") { iG = (D + 1); break; }
                            if (i < iH && lstS[i + 1][j + 0] == "G") { iG = (D + 1); break; }
                            if (j > 00 && lstS[i - 0][j - 1] == "G") { iG = (D + 1); break; }
                            if (i > 00 && lstS[i - 1][j - 0] == "G") { iG = (D + 1); break; }
                            bEx = true;
                        }
                    }
                    if (iG != -1) { break; }
                }
                if (!bEx) { break; }        // ?????????????
                if (iG != -1) { break; }    // Goal????
            }
        }

}