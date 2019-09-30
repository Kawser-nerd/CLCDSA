using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            int iM = int.Parse(sS[1]);
            List<ClsSmp> lstMem = new List<ClsSmp>();           // ?
            List<ClsSmp> lstChk = new List<ClsSmp>();           // CK
            for (int i = 0; i < iN; i++) { sS = Console.ReadLine().Trim().Split(' '); lstMem.Add(new ClsSmp() { iX = int.Parse(sS[0]), iY = int.Parse(sS[1]) }); }
            for (int i = 0; i < iM; i++) { sS = Console.ReadLine().Trim().Split(' '); lstChk.Add(new ClsSmp() { iX = int.Parse(sS[0]), iY = int.Parse(sS[1]) }); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            for (int i = 0; i < lstMem.Count; i++)
            {
                List<ClsDif> lstDif = new List<ClsDif>();           // ??
                for (int j = 0; j < lstChk.Count; j++)
                {
                    int iDid = Math.Abs(lstMem[i].iX - lstChk[j].iX) + Math.Abs(lstMem[i].iY - lstChk[j].iY);
                    lstDif.Add(new ClsDif() { iC = j , iD = iDid });
                }
                if (lstDif.Count > 1) { lstDif.Sort(delegate (ClsDif mca1, ClsDif mca2) { return (int)(mca1.iD - mca2.iD) == 0 ? (mca1.iC - mca2.iC) : (mca1.iD - mca2.iD); }); }     // iD??? ? iC???
                lstMem[i].iC = lstDif[0].iC + 1;
            }

            //??
            for (int i = 0; i < lstMem.Count; i++)
            {
                Console.WriteLine("{0}", lstMem[i].iC.ToString().Trim());
            }

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
            public int iX { get; set; } = 0;
            public int iY { get; set; } = 0;
            public int iC { get; set; } = 0;            // ??CK No.
        }

        private class ClsDif
        {
            public int iC { get; set; } = 0;            // CK No.
            public int iD { get; set; } = 0;            // ??
        }
}