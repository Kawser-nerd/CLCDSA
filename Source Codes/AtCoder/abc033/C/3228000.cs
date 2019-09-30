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
            int iOut = 0;
            List<string> sPlus = sInp.Split('+').ToList();
            for (int i = 0; i < sPlus.Count; i++)
            {
                if (sPlus[i].Length == 1) { if (sPlus[i] != "0") { iOut += 1; } }
                else
                {
                    List<string> sMult = sPlus[i].Split('*').ToList();
                    Boolean bEx0 = false;
                    for (int j = 0; j < sMult.Count; j++)
                    {
                        if (sMult[j] == "0") { bEx0 = true; break; }                // 0 ????
                    }
                    if (!bEx0) { iOut += 1; }
                }
            }

            // ??
            Console.WriteLine("{0}", iOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }

}