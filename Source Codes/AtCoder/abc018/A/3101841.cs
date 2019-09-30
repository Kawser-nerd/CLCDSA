using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            List<ClsSmp> lstSmp = new List<ClsSmp>();
            for (int j = 0; j < 3; j++)
            {
                string sInp = Console.ReadLine().Trim();
                ClsSmp oneUsr = new ClsSmp();
                oneUsr.iD = j;
                oneUsr.iP = int.Parse(sInp);
                lstSmp.Add(oneUsr);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstSmp.Sort(delegate (ClsSmp mca1, ClsSmp mca2) { return mca2.iP - mca1.iP; });    	// ?? ???
            for (int j = 0; j < lstSmp.Count; j++) { lstSmp[j].iJ = j + 1; }					// ?? ???
            lstSmp.Sort(delegate (ClsSmp mca1, ClsSmp mca2) { return mca1.iD - mca2.iD; });    	// Index???

            // ??
            for (int j = 0; j < lstSmp.Count; j++)
            {
                Console.WriteLine("{0}", lstSmp[j].iJ.ToString());
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
            public int iD { get; set; } = 0;
            public int iP { get; set; } = 0;
            public int iJ { get; set; } = 0;
        }


}