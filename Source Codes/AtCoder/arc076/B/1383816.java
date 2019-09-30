import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author toshif
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyReader in = new MyReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyReader in, PrintWriter out) {
            int N = in.nextInt();
            List<P> ps = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                long x = in.nextLong();
                long y = in.nextLong();
                P p = new P();
                p.x = x;
                p.y = y;
                p.idx = i;
                ps.add(p);
            }
            Collections.shuffle(ps);
            ps.sort((o1, o2) -> {
                if (Long.compare(o1.x, o2.x) != 0) return Long.compare(o1.x, o2.x);
                return Integer.compare(o1.idx, o2.idx);
            });
            List<Q> qs = new ArrayList<>();
            for (int i = 0; i < ps.size() - 1; i++) {
                Q q = new Q();
                q.d = ps.get(i + 1).x - ps.get(i).x;
                q.i1 = ps.get(i + 1).idx;
                q.i2 = ps.get(i).idx;
                qs.add(q);
            }

            Collections.shuffle(ps);
            ps.sort((o1, o2) -> {
                if (Long.compare(o1.y, o2.y) != 0) return Long.compare(o1.y, o2.y);
                return Integer.compare(o1.idx, o2.idx);
            });
            for (int i = 0; i < ps.size() - 1; i++) {
                Q q = new Q();
                q.d = ps.get(i + 1).y - ps.get(i).y;
                q.i1 = ps.get(i + 1).idx;
                q.i2 = ps.get(i).idx;
                qs.add(q);
            }

            Collections.shuffle(qs);
            qs.sort((o1, o2) -> {
                if (Long.compare(o1.d, o2.d) != 0) return Long.compare(o1.d, o2.d);
                if (Long.compare(o1.i1, o2.i1) != 0) return Long.compare(o1.i1, o2.i1);
                return Long.compare(o1.i2, o2.i2);
            });

            UnionFind uf = new UnionFind(N);
            int cnt = 0;
            long tot = 0;
            for (Q q : qs) {
                if (!uf.connected(q.i1, q.i2)) {
                    uf.union(q.i1, q.i2);
                    cnt++;
                    tot += q.d;
                }
                if (cnt == N - 1) break;
            }

            out.println(tot);
        }

        class P {
            long x;
            long y;
            int idx;

        }

        class Q {
            int i1;
            int i2;
            long d;

        }

    }

    static class UnionFind {
        private int[] id;
        private int[] rank;
        private int count;

        public UnionFind(int N) {
            count = N;
            id = new int[N];
            rank = new int[N];
            for (int i = 0; i < N; i++) {
                id[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int p) {
            while (p != id[p]) {
                id[p] = id[id[p]]; // path compression by halving
                p = id[p];
            }
            return p;
        }

        public void union(int p, int q) {
            int i = find(p);
            int j = find(q);
            if (i == j) return;

            // make root of smaller rank point to root of larger rank
            if (rank[i] < rank[j]) {
                id[i] = j;
            } else if (rank[i] > rank[j]) {
                id[j] = i;
            } else {
                id[j] = i;
                rank[i]++;
            }

            count--;
        }

        public boolean connected(int p, int q) {
            return find(p) == find(q);
        }

    }

    static class MyReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public MyReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}