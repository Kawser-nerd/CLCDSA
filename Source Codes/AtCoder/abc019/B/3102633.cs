using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string sInp = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "";
            string sTmp = "";
            string sBak = "";
            int iCnt = 1;
            for (int j = 0; j < sInp.Length; j++)
            {
                sTmp = sInp.Substring(j, 1);
                if (sTmp == sBak)
                {
                    iCnt += 1;
                    if (j == sInp.Length - 1)
                    {
                        sOut += sTmp + iCnt.ToString();
                    }
                }
                else
                {
                    if (j != 0)
                    {
                        sOut += sBak + iCnt.ToString();
                        iCnt = 1;
                    }
                    if (j == sInp.Length - 1)
                    {
                        sOut += sTmp + 1.ToString();
                    }
                }
                sBak = sTmp;
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



}