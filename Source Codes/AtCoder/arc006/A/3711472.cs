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
            List<int> lstTo = new List<int>();
            for (int i = 0; i < sS.Length; i++) { lstTo.Add(int.Parse(sS[i])); }
            sS = System.Console.ReadLine().Trim().Split(' ');
            int iB = int.Parse(sS[0]);
            sS = System.Console.ReadLine().Trim().Split(' ');
            List<int> lstMy = new List<int>();
            for (int i = 0; i < sS.Length; i++) { lstMy.Add(int.Parse(sS[i])); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            int iCnt = 0;
            for (int i = 0; i < lstMy.Count; i++) { if (lstTo.Contains(lstMy[i])) { iCnt += 1; } }
            switch (iCnt)
            {
                case 6:
                    iOut = 1;
                    break;
                case 5:
                    if (lstMy.Contains(iB)) { iOut = 2; }
                    else { iOut = 3; }
                    break;
                case 4:
                    iOut = 4;
                    break;
                case 3:
                    iOut = 5;
                    break;
                default:
                    iOut = 0;
                    break;
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