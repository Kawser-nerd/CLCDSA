using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string s2 = System.Console.ReadLine();
            int iN = int.Parse(s2);
            List<int> lstBag = new List<int>();
            for (int i = 0; i < iN; i++) { lstBag.Add(int.Parse(System.Console.ReadLine())); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<List<int>> lstMon = new List<List<int>>();
            for (int i = 0; i < lstBag.Count; i++)                                      // ??
            {
                List<ClsCan> lstCan = new List<ClsCan>();                               // ??????
                for (int j = 0; j < lstMon.Count; j++)                                  // ????
                {
                    if (lstMon[j][lstMon[j].Count - 1] >= lstBag[i]) { lstCan.Add(new ClsCan() { iX = j, iD = lstMon[j][lstMon[j].Count - 1] - lstBag[i] }); }  // ???
                }
                if (lstCan.Count > 1) { lstCan.Sort(delegate (ClsCan mca1, ClsCan mca2) { return (int)(mca1.iD - mca2.iD); }); }                                // ?????????????????????
                if (lstCan.Count > 0) { lstMon[lstCan[0].iX].Add(lstBag[i]); }          // ???????????
                else { lstMon.Add(new List<int>() { lstBag[i] }); }                     // ????????
            }

            // ??
            System.Console.WriteLine("{0}", lstMon.Count.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // ???????
        private class ClsCan
        {
            public int iX { get; set; } = 0;            // ?Index
            public int iD { get; set; } = 0;            // Top??????
        }

}