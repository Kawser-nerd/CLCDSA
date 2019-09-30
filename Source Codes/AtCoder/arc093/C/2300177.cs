using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC093E {
    class Program {
        static void Main(string[] args) {
            int[] NMinput = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = NMinput[0];
            int M = NMinput[1];
            long X = long.Parse(Console.ReadLine());
            Edge[] graph = new Edge[M];
            for (int i = 0; i < M; i++) {
                long[] input = Console.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
                Edge edge = new Edge();
                edge.from = (int)input[0] - 1;
                edge.to = (int)input[1] - 1;
                edge.cost = input[2];
                graph[i] = edge;
            }
            Array.Sort(graph, (a, b) => (int)((a.cost - b.cost) / Math.Max(Math.Abs(a.cost - b.cost), 1)));
            long[] mins = new long[M];
            for (int i = 0; i < M; i++) {
                UnionFind u = new UnionFind(N);
                long allcost = 0;
                u.unite(graph[i].from, graph[i].to);
                allcost += graph[i].cost;
                for (int j = 0; j < M; j++) {
                    Edge e = graph[j];
                    if (!u.same(e.from, e.to)) {
                        u.unite(e.from, e.to);
                        allcost += e.cost;
                    }
                }
                mins[i] = allcost;
            }
            long less = 0;
            long equal = 0;
            long more = 0;
            for (int i = 0; i < M; i++) {
                if (mins[i] < X) {
                    less++;
                } else if (mins[i] == X) {
                    equal++;
                } else {
                    more++;
                }
            }
            long ans = 0;
            if (less == 0) {
                ans = multiply(Math.Max(power(2, equal) - 2, 0), power(2, more));
            } else {
                ans = multiply(multiply(2, power(2, equal) - 1), power(2, more));
            }
            Console.WriteLine(ans);
        }

        //????
        const long mod = 1000000007;

        //mod???x×y??
        private static long multiply(long x, long y) {
            return (x % mod) * (y % mod) % mod;
        }

        //mod???x?y???
        private static long power(long x, long y) {
            if (y == 0) {
                return 1;
            } else if (y == 1) {
                return x % mod;
            } else if (y % 2 == 0) {
                long p = power(x, y / 2);
                return p * p % mod;
            } else {
                long p = power(x, y / 2);
                return (p * p) % mod * (x % mod) % mod;
            }
        }

        //????????????
        class Edge {
            public int from;
            public int to;
            public long cost;
        }

        //UnionFind???
        public class UnionFind {
            private int[] par;
            private int[] rank;
            private int[] samenum;

            //????????
            public UnionFind(int n) {
                par = new int[n];
                rank = new int[n];
                samenum = Enumerable.Repeat(1, n).ToArray();
                for (int i = 0; i < n; i++) {
                    par[i] = i;
                }
            }

            //x???????
            public int find(int x) {
                if (par[x] == x) {
                    return x;
                } else {
                    par[x] = find(par[x]);
                    return par[x];
                }
            }

            //x?y??????
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

            //x?y???????????????????
            public bool same(int x, int y) {
                return find(x) == find(y);
            }

            //x???????????????(x???)?????
            public int numfind(int x) {
                x = find(x);
                return samenum[x];
            }
        }
    }
}