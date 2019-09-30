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

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "Not Prime";
            switch (sS)
            {
                case "2":
                case "3":
                case "5":
                case "7":
                    sOut = "Prime";
                    break;
                case "1":
                    break;
                default:
                    int iN = int.Parse(sS);
                    if (iN % 2 == 0) { break; }
                    if (iN % 5 == 0) { break; }
                    int iSum = 0;
                    for (int i = 0; i < sS.Length; i++) { iSum += int.Parse(sS.Substring(i , 1)); }
                    if (iSum % 3 != 0) { sOut = "Prime"; }
                    break;
            }

            // ??
            System.Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}