using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            // ??
            int iN = int.Parse(Console.ReadLine().Trim());

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            int iSum = 0;
            int iTmp = iN;
            while (iTmp > 0)
            {
                iSum += iTmp % 10;
                iTmp /= 10;
            }
            string sOut = "No";
            if (iN % iSum == 0) { sOut = "Yes"; }
            
            // ??
            Console.WriteLine("{0}", sOut.ToString().Trim());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }
}