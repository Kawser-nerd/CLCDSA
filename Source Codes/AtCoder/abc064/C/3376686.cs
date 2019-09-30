using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<ClsSmp> lstGrp = new List<ClsSmp>()
            {
                new ClsSmp() {iN = 0001, iX = 0399, iC = 0 },
                new ClsSmp() {iN = 0400, iX = 0799, iC = 0 },
                new ClsSmp() {iN = 0800, iX = 1199, iC = 0 },
                new ClsSmp() {iN = 1200, iX = 1599, iC = 0 },
                new ClsSmp() {iN = 1600, iX = 1999, iC = 0 },
                new ClsSmp() {iN = 2000, iX = 2399, iC = 0 },
                new ClsSmp() {iN = 2400, iX = 2799, iC = 0 },
                new ClsSmp() {iN = 2800, iX = 3199, iC = 0 },
                new ClsSmp() {iN = 3200, iX = 9999, iC = 0 },
            };

            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            sS = Console.ReadLine().Trim().Split(' ');
            List<int> lstInp = new List<int>();
            for (int i = 0; i < sS.Length; i++) { lstInp.Add(int.Parse(sS[i])); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            for (int i = 0; i < lstInp.Count; i++)
            {
                for (int j = 0; j < lstGrp.Count; j++)
                {
                    if (lstGrp[j].iN <= lstInp[i] && lstInp[i] <= lstGrp[j].iX) { lstGrp[j].iC += 1; break; }
                }
            }
            int iMin = 0;
            int iMax = 0;
            for (int j = 0; j < lstGrp.Count - 1; j++)
            {
                if (lstGrp[j].iC > 0) { iMin += 1; }
            }
            if (iMin == 0 && lstGrp[lstGrp.Count - 1].iC > 0) { iMin = 1; iMax = lstGrp[lstGrp.Count - 1].iC; }
            else
            {
                iMax = iMin + lstGrp[lstGrp.Count - 1].iC;
            }

            //??
            Console.WriteLine("{0}", iMin.ToString() + " " + iMax.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
        private class ClsSmp
        {
            public int iN { get; set; } = 0;
            public int iX { get; set; } = 0;
            public int iC { get; set; } = 0;
        }

}