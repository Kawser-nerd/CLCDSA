using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program
{
    static void Main(string[] args)
    {
            //??
            string sS = System.Console.ReadLine().Trim();
            int iN = int.Parse(sS);

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            string sOut = "";
            int iTtl = 0;
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 9; j++)
                {
                    sOut = (new string('*', i)).Replace("*", j.ToString());
                    iTtl += 1;
                    if (iTtl >= iN) { break; }
                }
                if (iTtl >= iN) { break; }
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