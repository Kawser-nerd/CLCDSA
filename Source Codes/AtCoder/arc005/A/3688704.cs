using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string s2 = System.Console.ReadLine().Trim();
            int iN = int.Parse(s2);
            s2 = System.Console.ReadLine().Trim();
            s2 = s2.Substring(0, s2.Length - 1);                                // ???.??
            string[] sS = s2.Split(' ');
            List<string> lstInp = new List<string>();
            for (int i = 0; i < iN; i++)
            {
                lstInp.Add(sS[i]);
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            for (int i = 0; i < lstInp.Count; i++)
            {
                if (lstInp[i] == "TAKAHASHIKUN" || lstInp[i] == "Takahashikun" || lstInp[i] == "takahashikun")
                {
                    iOut += 1;
                }
            }

            // ??
            System.Console.WriteLine("{0}", iOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}