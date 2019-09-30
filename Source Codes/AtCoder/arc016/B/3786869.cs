using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = System.Console.ReadLine().Trim();
            int iN = int.Parse(sS);
            List<List<string>> lstGaf = new List<List<string>>();   // ??
            for (int i = 0; i < iN; i++)
            {
                List<string> lstRow = new List<string>();
                sS = System.Console.ReadLine().Trim();
                for (int j = 0; j < sS.Length; j++) { lstRow.Add(sS.Substring(j, 1)); }
                lstGaf.Add(lstRow);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iCtx = 0;
            int iCto = 0;
            for (int i = 0; i < lstGaf.Count; i++) { iCtx += lstGaf[i].Count(x => x == "x"); }      // x??
            for (int j = 0; j < lstGaf[0].Count; j++)
            {
                Boolean bIso = false;
                for (int i = 0; i < lstGaf.Count; i++)
                {
                    if (lstGaf[i][j] == "o" && !bIso) { iCto += 1; bIso = true; }                   // o?????o????? o?????
                    if (bIso && lstGaf[i][j] != "o") { bIso = false; }                              // o???????o??????
                }
            }

            // ??
            System.Console.WriteLine("{0}", (iCtx + iCto).ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}