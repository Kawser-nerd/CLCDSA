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
            int iK = int.Parse(sS[1]);
            List<string> lstHet = new List<string>();
            sS = System.Console.ReadLine().Trim().Split(' ');
            for (int i = 0; i < sS.Length; i++) { lstHet.Add(sS[i]); }           // ?????

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = iN;
            while (true)
            {
                string sOut = iOut.ToString();
                Boolean bHet = false;
                for (int i = 0; i < sOut.Length; i++) { if (lstHet.Contains(sOut.Substring(i, 1))) { bHet = true; break; } }    // ???????
                if (!bHet && iOut >= iN) { break; }                                                                             // OK
                iOut += 1;                                                                                                      // ??
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

}