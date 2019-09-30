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
            int iX = int.Parse(sS[0]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            List<int> lstBek = new List<int>() { 8, 16, 27, 32, 64, 81, 125, 128, 216, 243, 256, 343, 512, 625, 729, 1000, };
            int iOut = 0;
            for (int i = 0; i < iX; i++)
            {
                int iY = iX - i;
                if (Math.Sqrt(iY) % 1 == 0) { iOut = iY; break; }
                if (lstBek.Contains(iY)) { iOut = iY; break; }
                //string sOut = "";
                //sOut += "n=" + (iX - i).ToString("000") + " Sq=" + Math.Sqrt(iX - i).ToString() + " Rm" + (Math.Sqrt(iX - i) % 1).ToString() + ((Math.Sqrt(iX - i) % 1 == 0) ? " ?" : "");
                //Console.WriteLine("{0}", sOut.ToString().Trim());
            }

            // ??
            Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}