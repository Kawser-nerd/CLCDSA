using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            ClsPos oneSta = new ClsPos();
            ClsPos oneEnd = new ClsPos();
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            oneSta.iX = int.Parse(sInp[0]);
            oneSta.iY = int.Parse(sInp[1]);
            oneEnd.iX = int.Parse(sInp[2]);
            oneEnd.iY = int.Parse(sInp[3]);
            int iT = int.Parse(sInp[4]);
            int iV = int.Parse(sInp[5]);
            sInp = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sInp[0]);
            List<ClsPos> lstSmp = new List<ClsPos>();
            for (int i = 0; i < iN; i++)
            {
                sInp = Console.ReadLine().Trim().Split(' ');
                ClsPos oneUsr = new ClsPos();
                oneUsr.iX = int.Parse(sInp[0]);
                oneUsr.iY = int.Parse(sInp[1]);
                lstSmp.Add(oneUsr);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "NO";
            int iCanM = iT * iV;                                // ??????
            double dMovL = 0;
            for (int i = 0; i < lstSmp.Count; i++)
            {
                dMovL = 0;
                dMovL += Math.Sqrt(Math.Pow(lstSmp[i].iX - oneSta.iX, 2) + Math.Pow(lstSmp[i].iY - oneSta.iY, 2));
                dMovL += Math.Sqrt(Math.Pow(lstSmp[i].iX - oneEnd.iX, 2) + Math.Pow(lstSmp[i].iY - oneEnd.iY, 2));
                if (iCanM >= dMovL) { sOut = "YES"; break; }
            }

            //??
            Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

        public class ClsPos
        {
            public int iX { get; set; } = 0;
            public int iY { get; set; } = 0;
        }

}