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
            List<string> lstInp = new List<string>();
            for (int i = 0; i < iN; i++) { lstInp.Add(System.Console.ReadLine().Trim()); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "DRAW";
            string sBak = lstInp[0];
            Boolean bOri = true;                        // true ??  false ??
            List<string> lstYta = new List<string>();   // ????????
            lstYta.Add(lstInp[0]);                      // ?????????????????
            for (int i = 1; i < lstInp.Count; i++)
            {
                bOri = !bOri;                           // ????
                if (lstYta.Contains(lstInp[i])) { if (bOri) { sOut = "LOSE"; } else { sOut = "WIN"; } break; }                                      // ???????Out
                if (sBak.Substring(sBak.Length - 1, 1) != lstInp[i].Substring(0, 1)) { if (bOri) { sOut = "LOSE"; } else { sOut = "WIN"; } break; } // ???????Out
                lstYta.Add(lstInp[i]);                  // ???????????
                sBak = lstInp[i];                       // ??
            }

            // ??
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