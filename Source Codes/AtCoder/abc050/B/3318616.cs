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
            sS = Console.ReadLine().Trim().Split(' ');
            List<int> listT = new List<int>();
            for (int i = 0; i < iN; i++) { listT.Add(int.Parse(sS[i])); }
            sS = Console.ReadLine().Trim().Split(' ');
            int iM = int.Parse(sS[0]);
            List<ClsSmp> listM = new List<ClsSmp>();
            for (int i = 0; i < iM; i++)
            {
                sS = Console.ReadLine().Trim().Split(' ');
                ClsSmp oneUsr = new ClsSmp();
                oneUsr.iP = int.Parse(sS[0]) - 1;
                oneUsr.iX = int.Parse(sS[1]);
                listM.Add(oneUsr);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iSum = listT.Sum();
            for (int i = 0; i < listM.Count; i++)
            {
                listM[i].iS = iSum - listT[listM[i].iP] + listM[i].iX;
            }

            //??
            for (int i = 0; i < listM.Count; i++)
            {
                Console.WriteLine("{0}", listM[i].iS.ToString().Trim());
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
            public int iP { get; set; } = 0;
            public int iX { get; set; } = 0;
            public int iS { get; set; } = 0;
        }
}