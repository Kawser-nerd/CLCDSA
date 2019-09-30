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
            int iC = int.Parse(sS[0]);
            List<List<int>> lstHok = new List<List<int>>();
            for (int i = 0; i < iC; i++)
            {
                sS = System.Console.ReadLine().Trim().Split(' ');
                List<int> oneNow = new List<int>();
                for (int j = 0; j < 3; j++) { oneNow.Add(int.Parse(sS[j])); }
                oneNow.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });  // ??
                lstHok.Add(oneNow);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            List<int> rowOne = new List<int>();
            List<int> rowTwo = new List<int>();
            List<int> rowThr = new List<int>();
            for (int i = 0; i < lstHok.Count; i++) { rowOne.Add(lstHok[i][0]); rowTwo.Add(lstHok[i][1]); rowThr.Add(lstHok[i][2]); }
            List<int> oneMax = new List<int>() { rowOne.Max(), rowTwo.Max(), rowThr.Max(), };
            iOut = oneMax[0] * oneMax[1] * oneMax[2];

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