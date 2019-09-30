using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sInp[0]);
            int iX = int.Parse(sInp[1]);
            List<int> lstVal = new List<int>();
            sInp = Console.ReadLine().Trim().Split(' ');
            for (int i = 0; i < iN; i++)
            {
                lstVal.Add(int.Parse(sInp[i]));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iSm = 0;
            for (int i = 0; i < iN; i++)
            {
                if ((iX & (int)Math.Pow(2, i)) != 0) { iSm += lstVal[i]; }
            }

            //??
            Console.WriteLine("{0}", iSm.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}