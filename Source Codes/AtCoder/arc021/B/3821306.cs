using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = System.Console.ReadLine().Trim();
            int iL = int.Parse(sS);
            List<int> lstInp = new List<int>();
            for (int i = 0; i < iL; i++)
            {
                lstInp.Add(int.Parse(Console.ReadLine().Trim()));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iXor = 0;
            List<int> lstOut = new List<int>();
            for (int i = 0; i < lstInp.Count - 1; i++)
            {
                iXor ^= lstInp[i];
            }
            if (lstInp[lstInp.Count - 1] == iXor)
            {
                iXor = 0;
                lstOut.Add(iXor);
                for (int i = 0; i < lstInp.Count - 1; i++)
                {
                    iXor ^= lstInp[i];
                    lstOut.Add(iXor);
                }
            }
            else { lstOut.Add(-1); }

            // ??
            for (int i = 0; i < lstOut.Count; i++)
            {
                System.Console.WriteLine("{0}", lstOut[i].ToString().Trim());
            }

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}