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
            int iN = int.Parse(sS);
            List<string> lstInp = new List<string>();
            for (int i = 0; i < iN; i++)
            {
                lstInp.Add(System.Console.ReadLine().Trim());
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            for (int i = 0; i < lstInp.Count; i++)
            {
                char[] cSrc = lstInp[i].ToCharArray();                  // ?????
                Array.Reverse(cSrc);                                    // ?????
                lstInp[i] = new string(cSrc);                           // ?????
            }
            lstInp.Sort();
            for (int i = 0; i < lstInp.Count; i++)
            {
                char[] cSrc = lstInp[i].ToCharArray();                  // ?????
                Array.Reverse(cSrc);                                    // ?????
                lstInp[i] = new string(cSrc);                           // ?????
            }

            // ??
            for (int i = 0; i < lstInp.Count; i++)
            {
                System.Console.WriteLine("{0}", lstInp[i].ToString().Trim());
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