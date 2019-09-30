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
            int iT = 0;
            int iA = 0;
            for (int i = 0; i < lstInp.Count; i++)
            {
                for (int j = 0; j < lstInp[i].Length; j++)
                {
                    string sD = lstInp[i].Substring(j, 1);
                    switch (sD)
                    {
                        case "R":
                            iT += 1;
                            break;
                        case "B":
                            iA += 1;
                            break;
                    }
                }
            }
            string sOut = "DRAW";
            if (iT > iA) { sOut = "TAKAHASHI"; }
            if (iT < iA) { sOut = "AOKI"; }

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