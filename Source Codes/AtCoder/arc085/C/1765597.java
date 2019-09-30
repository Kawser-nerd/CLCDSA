// package arc.arc085;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long[] a = new long[101];
        for (int i = 1 ; i <= n ; i++) {
            a[i] = in.nextLong();
        }

        MaxFlowDinic di = new MaxFlowDinic();
        di.init(n+2);
        for (int i = 1 ; i <= n ; i++) {
            di.edge(0, i, a[i] < 0 ? -a[i] : 0);
            di.edge(i, n+1, a[i] > 0 ? a[i] : 0);
        }

        for (int i = 1 ; i <= n ; i++) {
            for (int j = i*2 ; j <= n; j += i) {
                di.edge(i, j, INF);
            }
        }

        long total = -di.max_flow(0, n+1);
        for (int i = 1 ; i <= n; i++) {
            if (a[i] >= 0) {
                total += a[i];
            }
        }

        out.println(total);
        out.flush();
    }

    public static final long INF = (long)1e12;

    public static class MaxFlowDinic {
        public List<long[]>[] graph;
        public int[] deg;

        public int[] level;
        public int[] itr;

        public int[] que;

        @SuppressWarnings("unchecked")
        public void init(int size) {
            graph = new List[size];
            for (int i = 0; i < size ; i++) {
                graph[i] = new ArrayList<long[]>();
            }
            deg = new int[size];
            level = new int[size];
            itr = new int[size];
            que = new int[size+10];
        }
        public void edge(int from, int to, long cap) {
            int fdeg = deg[from];
            int tdeg = deg[to];
            graph[from].add(new long[]{to, cap, tdeg});
            graph[to].add(new long[]{from, 0, fdeg});
            deg[from]++;
            deg[to]++;
        }

        public long dfs(int v, int t, long f) {
            if (v == t) return f;
            for (int i = itr[v] ; i < graph[v].size() ; i++) {
                itr[v] = i;
                long[] e = graph[v].get(i);
                if (e[1] > 0 && level[v] < level[(int)e[0]]) {
                    long d = dfs((int)e[0], t, Math.min(f, e[1]));
                    if (d > 0) {
                        e[1] -= d;
                        graph[(int)e[0]].get((int)e[2])[1] += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        public void bfs(int s) {
            Arrays.fill(level, -1);
            int qh = 0;
            int qt = 0;
            level[s] = 0;
            que[qh++] = s;
            while (qt < qh) {
                int v = que[qt++];
                for (int i = 0; i < graph[v].size() ; i++) {
                    long[] e = graph[v].get(i);
                    if (e[1] > 0 && level[(int)e[0]] < 0) {
                        level[(int)e[0]] = level[v] + 1;
                        que[qh++] = (int)e[0];
                    }
                }
            }
        }

        public long max_flow(int s, int t) {
            long flow = 0;
            while (true) {
                bfs(s);
                if (level[t] < 0) {
                    return flow;
                }
                Arrays.fill(itr, 0);
                while (true) {
                    long f = dfs(s, t, INF*10);
                    if (f <= 0) {
                        break;
                    }
                    flow += f;
                }
            }
        }
    }


    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}