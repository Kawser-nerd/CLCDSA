using System;
using System.Collections.Generic;
using System.Text;

namespace GCJ09R1A {
    class C : Z {
        public override void Solve() {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++) {

                string[] s = Console.ReadLine().Split(' ');
                int C = int.Parse(s[0]);
                int N = int.Parse(s[1]);
                double ret = exPacks(C, N);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);


                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private double exPacks(int C, int N) {
            long[,] choose = new long[41, 41];
            for (int i = 0; i < 41; i++) {
                choose[0, i] = 1;
                choose[i, i] = 1;
                for (int j = 1; j < i; j++) {
                    choose[j, i] = choose[j - 1, i - 1] + choose[j, i - 1];
                }
            }

            long decks = choose[N, C];

            double[] dEx = new double[41];
            dEx[0] = 0;
            for (int i = 1; i <= C; i++) {
                for (int g = N; g >=0; g--) {
                    if (g > i) continue;
                    if (N - g > C - i) continue;
                    long thesedecks = choose[g, i] * choose[N - g, C - i];
                    if (g > 0) {
                        dEx[i] += (dEx[i - g]+1) * thesedecks / decks;
                    } else {
                        double p = thesedecks;
                        p /= decks;
                        dEx[i] += p;
                        dEx[i] /= 1 - p;
                    }
                }
            }

            return dEx[C];
        }

    }
}
