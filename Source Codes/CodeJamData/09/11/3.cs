using System;
using System.Collections.Generic;
using System.Text;

namespace GCJ09R1A {
    class A : Z {
        int MAX = 5000;
        int[,] happy;
        // 0 unknown
        // 1 happy
        // 2 unhappy

        private void FillHappy() {
            happy = new int[11, MAX];
            for (int b = 2; b <= 10; b++) {
                happy[b, 1] = 1;
                for (int n = 2; n < MAX; n++) {
                    Dictionary<int, bool> mem = new Dictionary<int, bool>();
                    int v = n;
                    while (happy[b, v] == 0 && !mem.ContainsKey(v)) {
                        mem.Add(v, false);
                        v = nextSQVal(v, b);
                    }
                    if (happy[b, v] == 0) happy[b, v] = 2;
                    foreach (int i in mem.Keys) {
                        happy[b, i] = happy[b, v];
                    }
                }
            }
        }

        private int nextSQVal(int n, int b) {
            int ret = 0;
            while (n > 0) {
                int d = n % b;
                ret += d * d;
                n /= b;
            }
            return ret;
        }

        public override void Solve() {
            FillHappy();

            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++) {

                string[] s = Console.ReadLine().Split(' ');
                int ret = lowestHappy(s);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int lowestHappy(string[] s) {
            int[] bases = new int[s.Length];
            for (int i = 0; i < s.Length; i++) {
                bases[i] = int.Parse(s[i]);
            }
            for (int j = 2; true; j++) {
                bool good = true;
                for (int i = 0; i < bases.Length && good; i++) {
                    if (happy[bases[i], nextSQVal( j,bases[i])]!=1) good = false;
                }
                if (good) return j;
            }
            Console.WriteLine("ERROR > MAX.  {0}", s);
            System.Diagnostics.Debugger.Break();
            return -1;
        }

    }
}
