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
            List<int> lstInp = new List<int>();
            for (int i = 0; i < iN; i++)
            {
                sS = System.Console.ReadLine().Trim();
                lstInp.Add(int.Parse(sS));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iMax = lstInp.Sum();                                                        // ???????
            int iMin = 0;
            lstInp.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });      // ??
            int iZan = iMax - lstInp[0];                                                    // ????????
            switch (iN)
            {
                case 1:
                    iMin = lstInp[0];
                    break;
                case 2:
                    iMin = Math.Abs(lstInp[1] - lstInp[0]);
                    break;
                default:                                                                    // ?3???
                    if (lstInp[0] > iZan) { iMin = Math.Abs(lstInp[0] - iZan); }            // ???????????
                    else { iMin = 0; }
                    break;
            }

            // ??
            System.Console.WriteLine("{0}", iMax.ToString().Trim());
            System.Console.WriteLine("{0}", iMin.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}