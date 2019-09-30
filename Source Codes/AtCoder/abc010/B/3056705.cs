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
            List<int> lstSmp = new List<int>();
            for (int i = 0; i < iN; i++)
            {
                lstSmp.Add(int.Parse(sInp[i]));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            for (int i = 0; i < lstSmp.Count; i++)
            {
                while (true)
                {
                    if (lstSmp[i] % 2 == 0) { lstSmp[i] -= 1; iOut += 1; }      // ????
                    if (lstSmp[i] % 3 == 2) { lstSmp[i] -= 1; iOut += 1; }      // 3???+2 ??
                    if (lstSmp[i] % 2 == 1 && !(lstSmp[i] % 3 == 2)) { break; } // ?? ? 3???+2 ??? OK
                }
            }


            //??
            Console.WriteLine("{0}", iOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}