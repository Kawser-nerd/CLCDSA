using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string[] sS = System.Console.ReadLine().Trim().Split(' ');
            int iN = int.Parse(sS[0]);
            int iL = int.Parse(sS[1]);
            string s2 = System.Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iCsh = 0;
            int iTab = 1;
            for (int i = 0; i < s2.Length; i++)
            {
                string sOne = s2.Substring(i, 1);
                switch (sOne)
                {
                    case "+":
                        iTab += 1;
                        if (iTab > iL) { iCsh += 1; iTab = 1; }
                        break;
                    case "-":
                        iTab -= 1;
                        if (iTab < 1) { iTab = 1; }
                        break;
                }
            }

            // ??
            System.Console.WriteLine("{0}", iCsh.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}