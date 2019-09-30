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
            sInp = sInp.ToLower();
            string sOut = "";
            if (sInp.Length > 1) { sOut = sInp.Substring(0, 1).ToUpper() + sInp.Substring(1); }
            else { sOut = sInp.ToUpper(); }
            
            //??
            Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}