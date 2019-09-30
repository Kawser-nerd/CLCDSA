using System;
using System.Collections.Generic;
using System.Text;

namespace GCJ10Q
{
    class Snapper : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int N = int.Parse(s.Split(' ')[0]);
                long K = long.Parse(s.Split(' ')[1]);
                string ret = lighton(N, K);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private string lighton(int N, long K)
        {
            long l1 = 1;
            long target = (l1<<N)-1;
            if ((K & target) == target) return "ON";
            return "OFF";
        }

    }
}
