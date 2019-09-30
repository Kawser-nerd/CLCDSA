using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJR2A {
    class Program {
        public Program() {
            int ncase = int.Parse(Console.ReadLine());
            for (int dd = 0; dd < ncase; ++dd) {
                int N = int.Parse(Console.ReadLine());
                long mx = 0;
                long[] d = new long[N], l = new long[N], reach=new long[N];
                for (int i = 0; i < N; ++i) {
                    long[] dl = Console.ReadLine().Split().Select(p => long.Parse(p)).ToArray();
                    d[i] = dl[0]; l[i] = dl[1];
                }
                long totdist = long.Parse(Console.ReadLine());
                // Reading done
                mx = 2 * d[0];
                for (int i = 0; i < N; ++i) {
                    if (mx<d[i]) break;
                    reach[i]=(i==0?2*d[0]:0);
                    for (int j=0; j<i; ++j) {
                        if (reach[j]<d[i]) continue;
                        long cand = d[i]+Math.Min(d[i]-d[j],l[i]);
                        if (cand > reach[i]) reach[i] = cand;
                    }
                    if (reach[i] > mx) mx = reach[i];
                }
                Console.WriteLine("Case #{0}: {1}", dd + 1, mx >= totdist ? "YES" : "NO");
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
