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
            int iA = int.Parse(sS[0]);
            int iB = int.Parse(sS[1]);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iOut = 0;
            int iD = Math.Abs(iA - iB);             // ?
            int iR = Math.Abs(iA - iB) % 10;        // ??10??????
            switch (iR)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    iOut = iD / 10 + iD % 10;
                    break;
                case 5:
                    iOut = iD / 10 + 1;
                    break;
                case 4:
                case 6:
                    iOut = iD / 10 + 2;
                    break;
                case 7:
                    iOut = iD / 10 + 3;
                    break;
                case 8:
                case 9:
                    iOut = iD / 10 + (11 - iD % 10);
                    break;
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