import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.AbstractCollection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.LinkedList;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScan in = new MyScan(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EMul solver = new EMul();
        solver.solve(1, in, out);
        out.close();
    }

    static class EMul {
        public void solve(int testNumber, MyScan in, PrintWriter out) {
            int n = in.nextInt();
            int[] data = in.na(n);

            long r0 = 0;
            MaxFlow maxFlow = new MaxFlow(n + 2);

            for (int s = 0; s < n; s++) {
                if (data[s] <= 0) {
                    maxFlow.add(0, s + 1, -data[s]);
                } else {
                    r0 += data[s];
                    maxFlow.add(s + 1, n + 1, data[s]);
                }
            }

            for (int i = 1; i <= n; i++) {
                for (int k = i + i; k <= n; k += i) {
                    maxFlow.add(i, k, Long.MAX_VALUE / 2);
                }
            }

            out.println(r0 - maxFlow.max(0, n + 1));


        }

    }

    static class MyScan {
        private final InputStream in;
        private byte[] inbuf = new byte[1024];
        public int lenbuf = 0;
        public int ptrbuf = 0;

        public MyScan(InputStream in) {
            this.in = in;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = in.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int[] na(int n) {
            int[] k = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = nextInt();
            }
            return k;
        }

        public int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }

    static class MaxFlow {
        List<MaxFlow.Edge>[] g;

        public MaxFlow(int n) {
            g = new List[n];
            Arrays.setAll(g, l -> new ArrayList<>());
        }

        public void add(int i, int j, long capacity) {
            MaxFlow.Edge e = new MaxFlow.Edge(), f = new MaxFlow.Edge();
            e.to = j;
            f.to = i;
            e.capacity = capacity;
            f.capacity = 0;
            g[i].add(e);
            g[j].add(f);
            g[i].get(g[i].size() - 1).rev = g[j].size() - 1;
            g[j].get(g[j].size() - 1).rev = g[i].size() - 1;
        }

        public long max(int s, int t) {
            int n = g.length;
            int[] level = new int[n];
            long total = 0;
            boolean update;
            do {
                update = false;
                Arrays.fill(level, -1);
                level[s] = 0;
                LinkedList<Integer> q = new LinkedList<>();
                q.push(s);
                for (int d = n; !q.isEmpty() && level[q.peekFirst()] < d; ) {
                    int u = q.poll();
                    if (u == t) d = level[u];
                    for (MaxFlow.Edge e : g[u]) {
                        if (e.capacity > 0 && level[e.to] == -1) {
                            q.add(e.to);
                            level[e.to] = level[u] + 1;
                        }
                    }
                }
                int[] iter = new int[n];
                for (int i = 0; i < n; i++) iter[i] = g[i].size() - 1;
                while (true) {
                    long f = augment(level, iter, s, t, Long.MAX_VALUE / 2);
                    if (f == 0) break;
                    total += f;
                    update = true;
                }
            } while (update);
            return total;
        }

        private long augment(int[] level, int[] iter, int u, int t, long f) {
            if (u == t || f == 0) return f;
            int lv = level[u];
            if (lv == -1) return 0;
            level[u] = -1;
            for (; iter[u] >= 0; --iter[u]) {
                MaxFlow.Edge e = g[u].get(iter[u]);
                if (level[e.to] <= lv) continue;
                long l = augment(level, iter, e.to, t, Math.min(f, e.capacity));
                if (l == 0) continue;
                e.capacity -= l;
                g[e.to].get(e.rev).capacity += l;
                level[u] = lv;
                return l;
            }
            return 0;
        }

        public static final class Edge {
            int rev;
            int to;
            long capacity;

        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.