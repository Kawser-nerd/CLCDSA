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
            int iM = int.Parse(sInp[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();
            
            // ??
            int iC2 = -1;
            int iC3 = -1;
            int iC4 = -1;
            Boolean bOK = false;
            if (iN * 2 > iM || iN * 4 < iM) { }
            else
            {
                for (int i = 0; i <= iN; i++)
                {
                    for (int j = 0; j <= iN; j++)
                    {
                        if (i + j > iN) { break; }
                        if (2 * (iN - i - j) + 3 * (i) + 4 * (j) == iM)
                        //if (2 * (i) + 3 * (j) + 4 * (iN - i - j) == iM)
                        {
                            bOK = true;
                            iC2 = iN - i - j;
                            iC3 = i;
                            iC4 = j;
                            break;
                        }
                    }
                    if (bOK) { break; }
                }
            }

            //??
            Console.WriteLine("{0} {1} {2}", iC2.ToString(), iC3.ToString(), iC4.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());

            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}