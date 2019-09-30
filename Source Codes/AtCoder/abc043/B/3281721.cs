using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            string sS = Console.ReadLine().Trim();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "";
            for (int i = 0; i < sS.Length; i++)
            {
                string sO = sS.Substring(i, 1);
                switch (sO)
                {
                    case "0":
                    case "1":
                        sOut += sO;
                        break;
                    case "B":
                        if (sOut.Length > 0) { sOut = sOut.Substring(0, sOut.Length - 1); }
                        break;
                }
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