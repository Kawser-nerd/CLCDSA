using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace _20190307_03 {
    class Program {
        static void Main(string[] args) {
            var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var n = line[0];
            var m = line[1];
            var bridgeList = new int[m, 2];
            for (int i = 0; i < m; i++) {
                var bridge = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                bridgeList[m - i - 1, 0] = bridge[0];
                bridgeList[m - i - 1, 1] = bridge[1];
            }
            var uf = new UnionFindMethod(n);
            var answer = new long[m];
            var max = mC2(n);
            answer[m - 1] = max;
            for (int i = 0; i < m - 1; i++) {
                var i1 = bridgeList[i, 0] - 1;
                var i2 = bridgeList[i, 1] - 1;
                if (uf.IsSame(i1,i2)) {
                    answer[m - i - 2] = answer[m - i - 1];
                } else {
                    answer[m - i - 2] = answer[m - i - 1] - uf.GetSize(i1) * uf.GetSize(i2);
                    uf.Unite(i1, i2);
                }
            }
            foreach (var a in answer) {
                Console.WriteLine(a);
            }
        }

        static long mC2(long m) {
            return m * (m - 1) / 2;
        }
    }

    class UnionFindMethod {
        public int[] Parent { get; private set; }

        public UnionFindMethod(int n) {
            Parent = Enumerable.Repeat(-1, n).ToArray();
        }

        public int Root(int x) {
            return Parent[x] < 0 ? x : Parent[x] = Root(Parent[x]);
        }

        public void Unite(int x, int y) {
            var rx = Root(x);
            var ry = Root(y);
            if (rx == ry) return;
            Parent[rx] += Parent[ry];
            Parent[ry] = rx;
        }

        public int GetSize(int x) {
            return -Parent[Root(x)];
        }

        public bool IsSame(int x, int y) {
            return Root(x) == Root(y);
        }
    }
}