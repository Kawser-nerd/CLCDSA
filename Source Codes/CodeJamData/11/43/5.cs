using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Prime {
        public static bool[] lNotP;
        public static List<int> lPrimes;
        public static void Initialize(int range) {
            lNotP = new bool[range];
            lPrimes = new List<int>((int)(range / Math.Log(range)));
            lNotP[0] = true;
            lNotP[1] = true;
            for (int i = 2; i < range; i++) {
                if (!lNotP[i])
                    lPrimes.Add(i);
                for (int j = 0; j < lPrimes.Count && lPrimes[j] * i < range; j++) {
                    lNotP[i * lPrimes[j]] = true;
                    if (i % lPrimes[j] == 0)
                        break;
                }
            }
        }
    }
    class Round2C {
        public void gen(StreamWriter sw, StreamReader sr) {
            long N = Convert.ToInt64(sr.ReadLine());
            long res = 0;
            if (N != 1) {
                res++;
                Prime.Initialize((int)(Math.Sqrt(N) + 2));
                for (int i = 0; i < Prime.lPrimes.Count; i++) {
                    long p = Prime.lPrimes[i];
                    long c = 0, pp = p;
                    while (pp <= N / p) {
                        pp *= p;
                        c++;
                    }
                    res += c;
                }
            }
            sw.WriteLine(res);
        }
    }
}
