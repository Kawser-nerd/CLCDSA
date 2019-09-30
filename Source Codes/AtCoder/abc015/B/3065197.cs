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
            sInp = Console.ReadLine().Trim().Split(' ');
            int iSum = 0;
            int iDen = 0;
            for (int i = 0; i < iN; i++)
            {
                iSum += int.Parse(sInp[i]);
                iDen += sInp[i] == "0" ? 0 : 1;
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iAge = (int)Math.Ceiling((double)iSum / (double)iDen);

            //??
            Console.WriteLine("{0}", iAge.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}