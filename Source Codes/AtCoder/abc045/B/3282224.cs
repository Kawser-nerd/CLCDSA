using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            List<char> cA = Console.ReadLine().Trim().ToCharArray().ToList();
            List<char> cB = Console.ReadLine().Trim().ToCharArray().ToList();
            List<char> cC = Console.ReadLine().Trim().ToCharArray().ToList();

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "";
            char cNow = 'a';
            while (true)
            {
                switch (cNow)
                {
                    case 'a':
                        if (cA.Count <= 0) { sOut = "A"; break; }
                        cNow = cA[0];
                        cA.RemoveAt(0);
                        break;
                    case 'b':
                        if (cB.Count <= 0) { sOut = "B"; break; }
                        cNow = cB[0];
                        cB.RemoveAt(0);
                        break;
                    case 'c':
                        if (cC.Count <= 0) { sOut = "C"; break; }
                        cNow = cC[0];
                        cC.RemoveAt(0);
                        break;
                }
                if (sOut != "") { break; }
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