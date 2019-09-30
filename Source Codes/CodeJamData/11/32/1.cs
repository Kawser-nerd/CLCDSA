using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Space_Emergency {
        public void gen(StreamWriter sw, StreamReader sr) {
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            int L = Convert.ToInt32(lines[0]);
            long t = Convert.ToInt64(lines[1]);
            int N = Convert.ToInt32(lines[2]);
            int C = Convert.ToInt32(lines[3]);
            long[] a = new long[N];
            for (int i = 0; i < C; i++)
                a[i] = Convert.ToInt64(lines[4 + i]);
            for (int i = C; i < N; i++)
                a[i] = a[i % C];
            long sum = 0;
            int id = 0;
            for (; id < N; id++) {
                if (sum + a[id] * 2 > t)
                    break;
                sum += a[id] * 2;
            }
            if (id >= N)
                sw.WriteLine(sum);
            else {
                long res = t;
                a[id] = a[id] - (t - sum) / 2;
                if (N - id <= L) {
                    for (int i = id; i < N; i++)
                        res += a[i];
                } else {
                    Array.Sort(a, id, N - id);
                    for (int i = id; i < N - L; i++)
                        res += a[i] * 2;
                    for (int i = N - L; i < N; i++)
                        res += a[i];
                }
                sw.WriteLine(res);
            }
        }
    }
}
