using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            int iN = int.Parse(Console.ReadLine().Trim());
            List<ClsTown> lstTown = new List<ClsTown>();
            int iPopS = 0;
            for (int i = 0; i < iN; i++)
            {
                string[] sS = Console.ReadLine().Trim().Split(' ');
                ClsTown oneUsr = new ClsTown();
                oneUsr.sName = sS[0];
                oneUsr.iPopu = int.Parse(sS[1]);
                lstTown.Add(oneUsr);
                iPopS += oneUsr.iPopu;
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            iPopS = (iPopS / 2) + 1;
            string sOut = "atcoder";
            for (int i = 0; i < lstTown.Count; i++)
            {
                if (lstTown[i].iPopu >= iPopS) { sOut = lstTown[i].sName; break; }
            }

            // ??
            Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

        private class ClsTown
        {
            public string sName { get; set; } = "";
            public int    iPopu { get; set; } = 0;
        }

}