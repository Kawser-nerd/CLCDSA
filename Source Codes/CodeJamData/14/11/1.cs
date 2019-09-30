using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class ChargingChaos : GCJBase
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
                int L = int.Parse(s.Split(' ')[1]);
                string[] devices = new string[N];
                string[] currents = new string[N];
                currents = Console.ReadLine().Split(' ');
                devices = Console.ReadLine().Split(' ');
                long ret = MinSwitches(N, L, currents, devices);
                string sret = ret.ToString();
                if (ret == int.MaxValue) sret = "NOT POSSIBLE";

                Console.WriteLine("Case #{0}: {1}", iCase, sret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, sret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int MinSwitches(int N, int L, string[] currents, string[] devices)
        {
            int ret = int.MaxValue;
            HashSet<string> devHash = new HashSet<string>(devices);
            for (int i = 0; i < N; i++)
            {
                // Device 0 charges from current i
                bool[] switches = new bool[L];
                int switchcount = 0;
                for (int j = 0; j < L; j++)
                {
                    if (devices[0][j] != currents[i][j])
                    {
                        switches[j] = true;
                        switchcount++;
                    }
                }

                bool allGood = true;
                for (int j = 0; j < N; j++)
                {
                    char[] c = currents[j].ToCharArray();
                    for (int k = 0; k < L; k++)
                    {
                        if (switches[k])
                        {
                            if (c[k] == '0')
                            {
                                c[k] = '1';
                            }
                            else
                            {
                                c[k] = '0';
                            }
                        }
                    }
                    if (!devHash.Contains(new string(c)))
                    {
                        allGood = false;
                        break;
                    }
                }

                if (allGood)
                {
                    ret = Math.Min(ret, switchcount);
                }
            }

            return ret;
        }

    }
}
