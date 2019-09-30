using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            int iL = int.Parse(sS[1]);
            List<List<string>> lstAmd = new List<List<string>>();
            for (int i = 0; i <= iL; i++)
            {
                List<string> lstTmp = new List<string>();
                string s2 = System.Console.ReadLine();
                for (int j = 0; j < s2.Length; j++) { lstTmp.Add(s2.Substring(j, 1)); }
                lstAmd.Add(lstTmp);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstAmd.Reverse();                                                                               // ?????
            int iOut = 0;
            for (int j = 0; j < lstAmd[0].Count; j++) { if (lstAmd[0][j] == "o") { iOut = j; break; } }     // Start??(o??)
            int iW = lstAmd[0].Count;                                                                       // ????
            for (int i = 1; i < lstAmd.Count; i++)
            {
                if (iOut + 1 < iW && lstAmd[i][iOut + 1] == "-") { iOut += 2; continue; }
                if (iOut - 1 > -1 && lstAmd[i][iOut - 1] == "-") { iOut -= 2; continue; }
            }
            iOut = (iOut / 2) + 1;

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

}