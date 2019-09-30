using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sInp[0]);
            int iK = int.Parse(sInp[1]);
            List<long> lstInp = new List<long>();
            sInp = Console.ReadLine().Trim().Split(' ');
            for (int i = 0; i < sInp.Length; i++)
            {
                lstInp.Add(long.Parse(sInp[i]));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iA = iN - iK + 1;
            int iS = iK > iA ? iA : iK;
            long lOut = 0L;
            if (iK == 1 || iK == iN) { lOut = lstInp.Sum(); }
            else if (iS == 2) { lOut = lstInp[0] + lstInp[lstInp.Count - 1] + (lstInp.Sum() - lstInp[0] - lstInp[lstInp.Count - 1]) * 2; }
            else
            {
                lOut = lstInp[0] + lstInp[lstInp.Count - 1];
                lstInp.RemoveAt(lstInp.Count - 1);
                lstInp.RemoveAt(0);
                for (int i = 2; i <= iS; i++)
                {
                    if (i == iS) { lOut += lstInp.Sum() * i; }
                    else
                    {
                        lOut += (lstInp[0] + lstInp[lstInp.Count - 1]) * i;
                        lstInp.RemoveAt(lstInp.Count - 1);
                        lstInp.RemoveAt(0);
                    }
                }
            }

            // ??
            Console.WriteLine("{0}", lOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}