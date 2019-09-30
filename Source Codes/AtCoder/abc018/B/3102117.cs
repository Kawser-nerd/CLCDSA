using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            List<ClsSmp> lstSmp = new List<ClsSmp>();
            string sS = Console.ReadLine().Trim();
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sInp[0]);
            for (int j = 0; j < iN; j++)
            {
                sInp = Console.ReadLine().Trim().Split(' ');
                ClsSmp oneUsr = new ClsSmp();
                oneUsr.iL = int.Parse(sInp[0]);
                oneUsr.iR = int.Parse(sInp[1]);
                lstSmp.Add(oneUsr);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            for (int j = 0; j < lstSmp.Count; j++)
            {
                sS = ChangeRev(sS, lstSmp[j].iL, lstSmp[j].iR);
            }

            // ??
            Console.WriteLine("{0}", sS.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

        private static string ChangeRev(string sS, int iL, int iR)
        {
            string sFor = "";
            string sSrc = "";
            string sBak = "";
            if (iL - 1 > 0) { sFor = sS.Substring(0, iL - 1); }
           sSrc = sS.Substring(iL - 1, (iR - iL + 1));
            if (iR < sS.Length) { sBak = sS.Substring(iR); }
            char[] cSrc = sSrc.ToCharArray();
            Array.Reverse(cSrc);
            sSrc = new string(cSrc);
            return sFor + sSrc + sBak;
        }

        private class ClsSmp
        {
            public int iL { get; set; } = 0;
            public int iR { get; set; } = 0;
        }


}