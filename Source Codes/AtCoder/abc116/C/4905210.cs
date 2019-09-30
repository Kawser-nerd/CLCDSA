using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string s2 = System.Console.ReadLine().Trim();
            int iN = int.Parse(s2);
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            List<int> lstFlw = new List<int>();
            for (int i = 0; i < sS.Length; i++)
            {
                lstFlw.Add(int.Parse(sS[i]));                   // ?????
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iC = 0;                                         // ?????
            while (true)
            {
                Boolean bWat = false;                           // ????
                Boolean bOne = false;                           // 1???????????
                for (int i = 0; i < lstFlw.Count; i++)          // ????????
                {
                    if (lstFlw[i] == 0)                         // ?????????
                    {
                        bWat = false;                           // ?????
                    }
                    else                                        // ?????
                    {
                        lstFlw[i] -= 1;                         // ???
                        bOne = true;                            // 1????????
                        if (!bWat) { iC += 1; bWat = true; }    // ????? ????????????
                    }
                }
                if (!bOne) { break; }                           // 1????????????????????????
            }

            // ??
            System.Console.WriteLine("{0}", iC.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}