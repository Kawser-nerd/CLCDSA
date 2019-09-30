using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sInp[0]);
            int iT = int.Parse(sInp[1]);
            List<int> lstSmp = new List<int>();
            for (int j = 0; j < iN; j++)
            {
                lstSmp.Add(int.Parse(Console.ReadLine().Trim()));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int i = 0;
            int iSum = 0;
            while (true)
            {
                if (i >= lstSmp.Count) { break; }
                int iS = lstSmp[i];
                int iE = iS + iT;
                Boolean bE = false;
                while (true)
                {
                    i += 1;
                    if (i >= lstSmp.Count) { if (bE) { iSum += iE - iS; } else { iSum += iT; } break; }
                    int iC = lstSmp[i];
                    if (iE >= iC)               // ??????
                    {
                        iE = iC + iT;
                        bE = true;
                    }
                    else                        // ????
                    {
                        if (bE) { iSum += iE - iS; }
                        else { iSum += iT; }
                        bE = false;
                        break;
                    }
                }
            }

            // ??
            Console.WriteLine("{0}", iSum.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}