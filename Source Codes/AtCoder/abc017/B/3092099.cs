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
            string sOut = "YES";
            int iX = 0;
            int iW = 1;
            while (true)
            {
                if (sOut == "NO") { break; }
                if (iX >= sInp.Length) { break; }
                string sS = sInp.Substring(iX, iW);
                switch (sS)
                {
                    case "c":
                        iX += 1;
                        if (iX >= sInp.Length) { sOut = "NO"; break; }
                        sS = sInp.Substring(iX, iW);
                        if (sS != "h") { sOut = "NO"; break; }
                        iX += 1;
                        break;
                    case "o":
                    case "k":
                    case "u":
                        iX += 1;
                        break;
                    default:
                        sOut = "NO";
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