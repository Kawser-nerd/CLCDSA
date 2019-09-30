using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ?????
            List<int> lstCnt = new List<int>() { 0, 0, 0, 0, 0, 0, };
            for (int i = 0; i < iN; i++)
            {
                sS = System.Console.ReadLine().Trim().Split(' ');
                int iMx = (int)(double.Parse(sS[0]) * 10D);
                int iMi = (int)(double.Parse(sS[1]) * 10D);
                if (iMx >= 350)               { lstCnt[0] += 1; }             // ???
                if (iMx < 0350 && iMx >= 300) { lstCnt[1] += 1; }             // ???
                if (iMx < 0300 && iMx >= 250) { lstCnt[2] += 1; }             // ??
                if (iMi >= 250)               { lstCnt[3] += 1; }             // ???
                if (iMi < 0000 && iMx >= 000) { lstCnt[4] += 1; }             // ??
                if (iMx < 0000)               { lstCnt[5] += 1; }             // ???
            }

            // ??
            string sOut = "";
            for (int i = 0; i < lstCnt.Count; i++)
            {
                sOut += lstCnt[i].ToString() + " ";
            }
            System.Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}