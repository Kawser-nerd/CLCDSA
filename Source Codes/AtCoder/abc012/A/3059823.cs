using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {

            // ??
            string[] sInp = Console.ReadLine().Trim().Split(' ');

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??

            //??
            Console.WriteLine("{0} {1}", sInp[1].ToString(), sInp[0].ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif

    }


}