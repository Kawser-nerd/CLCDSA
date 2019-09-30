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
            List<List<string>> lstSS = new List<List<string>>();
            for (int i = 0; i < iH; i++)
            {
                string s2 = Console.ReadLine().Trim();
                List<string> oneUsr = new List<string>();
                for (int j = 0; j < s2.Length; j++)
                {
                    oneUsr.Add(s2.Substring(j, 1));
                }
                lstSS.Add(oneUsr);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            for (int i = 0; i < lstSS.Count; i++)
            {
                for (int j = 0; j < lstSS[i].Count; j++)
                {
                    if (lstSS[i][j] == ".") { lstSS[i][j] = GetBmbCnt(lstSS, i , j, iH, iW); }
                }
            }

            // ??
            for (int i = 0; i < lstSS.Count; i++)
            {
                string sOut = "";
                for (int j = 0; j < lstSS[i].Count; j++)
                {
                    sOut = string.Join("", lstSS[i]);
                }
                Console.WriteLine("{0}", sOut.ToString().Trim());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
        // #???
        private static string GetBmbCnt(List<List<string>> lstSS, int i, int j, int iH, int iW)
        {
            int iBmbCnt = 0;
            if (i - 0 >= 0 && j - 1 >= 0 && lstSS[i - 0][j - 1] == "#") { iBmbCnt += 1; }       // ?
            if (i - 1 >= 0 && j - 1 >= 0 && lstSS[i - 1][j - 1] == "#") { iBmbCnt += 1; }       // ?
            if (i - 1 >= 0 && j - 0 >= 0 && lstSS[i - 1][j - 0] == "#") { iBmbCnt += 1; }       // ?
            if (i - 1 >= 0 && j + 1 < iW && lstSS[i - 1][j + 1] == "#") { iBmbCnt += 1; }       // ?
            if (i + 0 < iH && j + 1 < iW && lstSS[i + 0][j + 1] == "#") { iBmbCnt += 1; }       // ?
            if (i + 1 < iH && j + 1 < iW && lstSS[i + 1][j + 1] == "#") { iBmbCnt += 1; }       // ?
            if (i + 1 < iH && j + 0 < iW && lstSS[i + 1][j + 0] == "#") { iBmbCnt += 1; }       // ?
            if (i + 1 < iH && j - 1 >= 0 && lstSS[i + 1][j - 1] == "#") { iBmbCnt += 1; }       // ?
            return iBmbCnt.ToString();
        }

}