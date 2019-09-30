using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();
            List<string> lstOrg = new List<string>() { "3", "5", "7" };
            List<string> lstAll = new List<string>() { "3", "5", "7" };
            List<int> lstAdd = new List<int>();
            for (int i = 0; i < lstAll.Count; i++) { lstAdd.Add(i); }
            while (true)
            {
                List<int> lstNew = new List<int>();
                int iCnt = lstAdd.Count;
                if (iCnt == 0) { break; }
                for (int j = 0; j < iCnt; j++)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        lstAll.Add(lstAll[lstAdd[j]] + lstOrg[i]);
                        lstNew.Add(lstAll.Count - 1);
                    }
                }
                lstAdd.Clear();
                lstAdd.AddRange(lstNew);
                if (lstAll[lstAll.Count - 1].Length == 9) { break; }
            }
            List<int> lstAl2 = new List<int>();
            for (int i = 0; i < lstAll.Count; i++)
            {
                if (lstAll[i].Length > 2)
                {
                    if (lstAll[i].Contains("3") && lstAll[i].Contains("5") && lstAll[i].Contains("7"))
                    {
                        lstAl2.Add(int.Parse(lstAll[i]));
                    }
                }
            }
            //DebugDisp(lstAl2);

            // ??
            int iN = int.Parse(System.Console.ReadLine().Trim());


            // ??
            int iOut = 0;
            for (int i = 0; i < lstAl2.Count; i++)
            {
                if (iN >= lstAl2[i]) { iOut += 1; }
                else { break; }
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

        // Debug??
        private static void DebugDisp(List<int> lstAl2)
        {
            Console.WriteLine();
            Console.WriteLine("{0}", lstAl2.Count.ToString().Trim());
            for (int i = 0; i < lstAl2.Count; i++)
            {
                Console.WriteLine("{0}", lstAl2[i].ToString().Trim());
                if (i > 20) { break; }
            }
        }

}