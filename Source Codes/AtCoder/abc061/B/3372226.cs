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
            List<ClsAtoB> lstD = new List<ClsAtoB>();
            for (int i = 0; i < iM; i++)
            {
                sS = Console.ReadLine().Trim().Split(' ');
                int ia = int.Parse(sS[0]) - 1;                          // 0??????
                int ib = int.Parse(sS[1]) - 1;                          // 0??????
                lstD.Add(new ClsAtoB() { iA = ia, iB = ib, });          // ?????
                lstD.Add(new ClsAtoB() { iA = ib, iB = ia, });          // ?????
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<ClsAtoB> lstN = new List<ClsAtoB>();
            for (int i = 0; i < iN; i++) { lstN.Add(new ClsAtoB() { iA = i, iB = 0, }); }
            for (int i = 0; i < lstD.Count; i++)
            {
                lstN[lstD[i].iA].iB += 1;
            }

            //??
            for (int i = 0; i < lstN.Count; i++)
            {
                Console.WriteLine("{0}", lstN[i].iB.ToString().Trim());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
        private class ClsAtoB                   // ???
        {
            public int iA { get; set; } = 0;
            public int iB { get; set; } = 0;
        }

}