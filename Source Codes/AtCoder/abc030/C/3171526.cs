using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sN = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sN[0]);
            int iM = int.Parse(sN[1]);
            sN = Console.ReadLine().Trim().Split(' ');
            int iX = int.Parse(sN[0]);
            int iY = int.Parse(sN[1]);
            List<int> lstA = new List<int>();
            List<int> lstB = new List<int>();
            sN = Console.ReadLine().Trim().Split(' ');
            for (int i = 0; i < iN; i++) { lstA.Add(int.Parse(sN[i])); }
            sN = Console.ReadLine().Trim().Split(' ');
            for (int i = 0; i < iM; i++) { lstB.Add(int.Parse(sN[i])); }

            //int iN = 100000;
            //int iM = 100000;
            //int iX = 2;
            //int iY = 2;
            //List<int> lstA = new List<int>();
            //List<int> lstB = new List<int>();
            //for (int i = 0; i < iN; i++) { lstA.Add(i * 2); }
            //for (int i = 0; i < iM; i++) { lstB.Add(i * 2); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iTim = 0;
            int iDuo = 0;
            int iAi = 0;                // ????IndexNo
            int iBi = 0;                // ????IndexNo
            while (true)
            {
                // A?B
                Boolean bA = false;
                for (int i = iAi; i < lstA.Count; i++)
                {
                    if (lstA[i] >= iTim) { iAi = i + 1; bA = true; iTim = lstA[i]; break; }
                }
                iTim += iX;
                // B?A
                Boolean bB = false;
                for (int i = iBi; i < lstB.Count; i++)
                {
                    if (lstB[i] >= iTim) { iBi = i + 1; bB = true; iTim = lstB[i]; break; }
                }
                iTim += iY;
                // ???
                if (bA && bB) { iDuo += 1; }
                else { break; }                
            }

            // ??
            Console.WriteLine("{0}", iDuo.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}