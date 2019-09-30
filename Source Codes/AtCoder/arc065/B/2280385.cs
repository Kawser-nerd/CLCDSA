using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC065D {
    class Program {

        static void Main(string[] args) {
            int[] NKLinput = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = NKLinput[0];
            int K = NKLinput[1];
            int L = NKLinput[2];
            UnionFind u = new UnionFind(N);
            UnionFind v = new UnionFind(N);
            for (int i = 0; i < K; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                u.unite(input[0] - 1, input[1] - 1);
            }
            for (int i = 0; i < L; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                v.unite(input[0] - 1, input[1] - 1);
            }
            int[][] jag = new int[N][];
            for (int i = 0; i < N; i++) {
                jag[i] = new int[3];
                jag[i][0] = u.find(i);
                jag[i][1] = v.find(i);
                jag[i][2] = i;
            }
            Array.Sort(jag, (a, b) => a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
            int[] ans = new int[N];
            int unum = -100000;
            int vnum = -100000;
            int num = 0;
            List<int> list = new List<int>();
            for (int i = 0; i < N; i++) {
                if (jag[i][0] == unum && jag[i][1] == vnum) {
                    num++;
                    list.Add(jag[i][2]);
                } else {
                    int count = list.Count();
                    for (int j = 0; j < count; j++) {
                        ans[list[j]] = num;
                    }
                    list.Clear();
                    list.Add(jag[i][2]);
                    num = 1;
                    unum = jag[i][0];
                    vnum = jag[i][1];
                }
            }
            int lastcount = list.Count();
            for (int j = 0; j < lastcount; j++) {
                ans[list[j]] = num;
            }
            Console.WriteLine(string.Join(" ", ans));
        }

        //UnionFind???
        public class UnionFind {
            private int[] par;
            private int[] rank;
            private int[] samenum;

            public UnionFind(int n) {
                par = new int[n];
                rank = new int[n];
                samenum = Enumerable.Repeat(1, n).ToArray();
                for (int i = 0; i < n; i++) {
                    par[i] = i;
                }
            }

            public int find(int x) {
                if (par[x] == x) {
                    return x;
                } else {
                    par[x] = find(par[x]);
                    return par[x];
                }
            }

            public void unite(int x, int y) {
                x = find(x);
                y = find(y);
                if (x == y) {
                    return;
                } else {
                    if (rank[x] < rank[y]) {
                        par[x] = y;
                        samenum[y] += samenum[x];
                    } else {
                        par[y] = x;
                        samenum[x] += samenum[y];
                        if (rank[x] == rank[y]) {
                            rank[x]++;
                        }
                    }
                }
            }

            public bool same(int x, int y) {
                return find(x) == find(y);
            }

            public int numfind(int x) {
                x = find(x);
                return samenum[x];
            }
        }
    }
}