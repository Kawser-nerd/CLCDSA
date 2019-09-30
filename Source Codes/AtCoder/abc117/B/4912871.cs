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
            int iN = int.Parse(sS[0]);
            sS = System.Console.ReadLine().Trim().Split(' ');
            List<int> lstSid = new List<int>();
            for (int i = 0; i < sS.Length; i++)
            {
                lstSid.Add(int.Parse(sS[i]));
            }

            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            // ??
            lstSid.Sort(delegate (int mca1, int mca2) { return mca2 - mca1; });         // ??
            int iM = lstSid[0];                                                         // ???
            lstSid.RemoveAt(0);                                                         // ????
            string sOut = "Yes";
            if (iM >= lstSid.Sum()) { sOut = "No"; }

            // ??
            System.Console.WriteLine("{0}", sOut.ToString());

            sw.Stop();
#if DEBUG
            Console.WriteLine();
            Console.WriteLine("{0}", sw.Elapsed.ToString());
            Console.WriteLine("?????????????????????");
            Console.ReadKey();
#endif
    }

}