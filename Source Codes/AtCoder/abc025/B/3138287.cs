using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sS = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            int iA = int.Parse(sS[1]);
            int iB = int.Parse(sS[2]);
            List<ClsSmp> lstSmp = new List<ClsSmp>();
            for (int i = 0; i < iN; i++)
            {
                ClsSmp oneUsr = new ClsSmp();
                sS = Console.ReadLine().Trim().Split(' ');
                oneUsr.sS = sS[0];
                oneUsr.iD = int.Parse(sS[1]);
                lstSmp.Add(oneUsr);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iNow = 0;
            for (int i = 0; i < lstSmp.Count; i++)
            {
                int iMov = 0;
                if (lstSmp[i].iD < iA) { iMov = iA; }
                if (lstSmp[i].iD >= iA && lstSmp[i].iD <= iB) { iMov = lstSmp[i].iD; }
                if (lstSmp[i].iD > iB) { iMov = iB; }
                iNow += (lstSmp[i].sS == "West" ? -1 : 1) * iMov;
            }

            // ??
            string sOut = "";
            if (iNow == 0) { }
            else if (iNow > 0) { sOut = "East "; }
            else { sOut = "West "; }
            sOut += Math.Abs(iNow).ToString();
            Console.WriteLine("{0}", sOut.ToString());

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
            public string sS { get; set; } = "";
            public int    iD { get; set; } = 0;
        }

}