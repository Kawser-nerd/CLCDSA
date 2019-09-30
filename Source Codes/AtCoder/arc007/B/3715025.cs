using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Split(' ');
            int iN = int.Parse(sS[0]) + 1;
            int iM = int.Parse(sS[1]);
            List<int> lstLis = new List<int>();
            for (int i = 0; i < iM; i++) { lstLis.Add(int.Parse(System.Console.ReadLine())); }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<ClsCas> lstCas = new List<ClsCas>();           // Case?CD
            for (int i = 1; i < iN; i++) { lstCas.Add(new ClsCas() { iC = i, iD = i }); }
            int iInC = 0;                                       // Player?CD
            for (int i = 0; i < lstLis.Count; i++)              // ????
            {
                for (int j = 0; j < lstCas.Count; j++)          // CD?Case
                {
                    if (lstCas[j].iD == lstLis[i])              // ????CD
                    {
                        int itmp = iInC;
                        iInC = lstCas[j].iD;                    // Player?CD???
                        lstCas[j].iD = itmp;                    // ??Case?Player?????CD????
                        break;
                    }
                }
            }
            lstCas.Sort(delegate (ClsCas mca1, ClsCas mca2) { return (int)(mca1.iC - mca2.iC); });  // Case???

            // ??
            for (int i = 0; i < lstCas.Count; i++)              // CaseNo???CDNo
            {
                System.Console.WriteLine("{0}", lstCas[i].iD.ToString().Trim());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

        // Case?CD
        private class ClsCas
        {
            public int iC { get; set; } = 0;            // CaseIndex
            public int iD { get; set; } = 0;            // CD
        }

}