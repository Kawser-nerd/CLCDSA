using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<string> lstABC = new List<string>() { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", };

            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            List<string> lstFig = new List<string>();
            for (int i = 0; i < 10; i++) { lstFig.Add(sS[i]); }
            sS = System.Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            List<string> lstNum = new List<string>();
            for (int i = 0; i < iN; i++) { lstNum.Add(Console.ReadLine()); }
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstLng = new List<int>();
            for (int i = 0; i < lstNum.Count; i++) { lstLng.Add(lstNum[i].Length); }    // ????
            lstLng.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });  // ?????
            int iMxL = lstLng[0];                                                       // ?????
            for (int i = 0; i < lstNum.Count; i++)
            {
                for (int j = 0; j < lstFig.Count; j++)
                {
                    lstNum[i] = lstNum[i].Replace(lstFig[j], lstABC[j]).PadLeft(iMxL);  // ?????????????????????? 
                }
            }
            lstNum.Sort();                                                              // ??????
            for (int i = 0; i < lstNum.Count; i++)
            {
                for (int j = 0; j < lstFig.Count; j++)
                {
                    lstNum[i] = lstNum[i].Replace(lstABC[j], lstFig[j]);                // ????????
                }
            }

            // ??
            for (int i = 0; i < lstNum.Count; i++)
            {
                System.Console.WriteLine("{0}", lstNum[i].ToString().Trim());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}