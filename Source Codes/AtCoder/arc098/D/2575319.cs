using System;
using System.Collections.Generic;

namespace ARC98_F {
    class Program {

        static long[] A;
        static long[] B;
        static long[] AmB;
        static List<Con> lcon = new List<Con>();


        static void Main(string[] args) {
            String line;
            line = Console.ReadLine();
            String[] var = line.Split(new char[] { ' ' });
            var N = int.Parse(var[0]);
            var M = int.Parse(var[1]);

            A = new long[N];
            B = new long[N];
            AmB = new long[N];
            group = new int[N];
            for (int i = 0; i < N; i++) {
                line = Console.ReadLine();
                var = line.Split(new char[] { ' ' });
                A[i] = long.Parse(var[0]);
                B[i] = long.Parse(var[1]);
                AmB[i] = A[i] - B[i];
                if (AmB[i] < 0) { AmB[i] = 0; }
                MakeSet(i);
            }

            for (int i = 0; i < M; i++) {
                line = Console.ReadLine();
                var = line.Split(new char[] { ' ' });
                var U = int.Parse(var[0]) - 1;
                var V = int.Parse(var[1]) - 1;
                if (U > V) { int k = U; U = V; V = k; }

                lcon.Add(new Con(U, V, AmB[U], AmB[V]));
            }

            lcon.Sort((a, b) => Math.Sign(a.C - b.C));

            var tree = new List<int>[N];
            for (int i = 0; i < N; i++) { tree[i] = new List<int>(); }

            var ss = new List<KeyValuePair<int, int>>();
            for (int i = 0; i < N; i++) { ss.Add(new KeyValuePair<int, int>(-1, i)); }

            var sumB = new long[N];
            for (int i = 0; i < N; i++) { sumB[i] = B[i]; }

            for (int i = 0; i < M; i++) {
                var u = lcon[i].U;
                var v = lcon[i].V;
                var gu = Find(u);
                var gv = Find(v);
                if (gu == gv) continue;
                tree[gu].Add(gv);
                sumB[gu] += sumB[gv];
                Union(u, v);
                ss[gu] = new KeyValuePair<int, int>(i, gu);
            }

            ss.Sort((a, b) => a.Key - b.Key);

            var ans = new long[N];
            for (int i = 0; i < N; i++) { ans[i] = AmB[i] + B[i]; }

            long mq = 0;
            for (int i = 0; i < N; i++) {
                var l = ss[i].Value;
                mq = AmB[l] + sumB[l];
                for (int j = 0; j < tree[l].Count; j++) {
                    var k = tree[l][j];
                    var q = (ans[k] > AmB[l]) ? ans[k] : AmB[l];
                    q = q + sumB[l] - sumB[k];
                    if (q < mq) { mq = q; }
                }
                ans[l] = mq;
            }

            Console.WriteLine(mq.ToString());
        }

        static int[] group;
        static int Find(int x) {
            if (group[x] == x) return x;
            group[x] = Find(group[x]);
            return group[x];
        }
        static void Union(int x, int y) {
            x = Find(x);
            y = Find(y);
            group[y] = x;
        }
        static void MakeSet(int x) {
            group[x] = x;
        }

    }

    class Con {
        public int U;
        public int V;
        public long C;

        public Con(int u, int v, long uc, long vc) {
            if (uc > vc) {
                U = u;
                V = v;
                C = uc;
            } else {
                U = v;
                V = u;
                C = vc;
            }
        }
    }

}