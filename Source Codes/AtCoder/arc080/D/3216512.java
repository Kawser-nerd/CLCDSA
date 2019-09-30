import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static long __startTime = System.currentTimeMillis();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();

        int[] x = new int[n];
        for (int i = 0; i < n ; i++) {
            x[i] = in.nextInt();
        }

        Set<Integer> set = new TreeSet<>();
        for (int i = 0; i < n ; i++) {
            for (int a = x[i] ; a <= x[i]+1; a++) {
                if (set.contains(a)) {
                    set.remove(a);
                } else {
                    set.add(a);
                }
            }
        }

        List<Integer> r = new ArrayList<>(set);
        int nodes = r.size();
        MaxFlowDinic maxFlow = new MaxFlowDinic();
        maxFlow.init(nodes+2);

        int src = nodes;
        int dst = nodes+1;

        int odd = 0;
        int even = 0;
        for (int i = 0; i < nodes ; i++) {
            if (r.get(i) % 2 == 0) {
                even++;
                maxFlow.edge(src, i, 1);
            } else {
                odd++;
                maxFlow.edge(i, dst, 1);
            }
        }
        for (int i = 0; i < nodes ; i++) {
            for (int j = 0 ; j < nodes ; j++) {
                if (r.get(i) % 2 == 0 && r.get(j) % 2 == 1) {
                    int d = Math.abs(r.get(i) - r.get(j));
                    if (isPrime(d)) {
                        maxFlow.edge(i, j, 1);
                    }
                }
            }
        }

        int F = maxFlow.max_flow(src, dst);
        odd -= F;
        even -= F;

        int total = F + (odd / 2) * 2 + (even / 2) * 2;
        if (odd % 2 == 1 && even % 2 == 1) {
            total += 3;
        }
        out.println(total);
        out.flush();
    }

    static boolean isPrime(int x) {
        if (x == 1) {
            return false;
        }
        for (int i = 2 ; i * i <= x ; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static class MaxFlowDinic {
        public List<int[]>[] graph;
        public int[] deg;

        public int[] level;
        public int[] itr;

        public int[] que;

        @SuppressWarnings("unchecked")
        public void init(int size) {
            graph = new List[size];
            for (int i = 0; i < size ; i++) {
                graph[i] = new ArrayList<int[]>();
            }
            deg = new int[size];
            level = new int[size];
            itr = new int[size];
            que = new int[size+10];
        }
        public void edge(int from, int to, int cap) {
            int fdeg = deg[from];
            int tdeg = deg[to];
            graph[from].add(new int[]{to, cap, tdeg});
            graph[to].add(new int[]{from, 0, fdeg});
            deg[from]++;
            deg[to]++;
        }

        public int dfs(int v, int t, int f) {
            if (v == t) return f;
            for (int i = itr[v] ; i < graph[v].size() ; i++) {
                itr[v] = i;
                int[] e = graph[v].get(i);
                if (e[1] > 0 && level[v] < level[e[0]]) {
                    int d = dfs(e[0], t, Math.min(f, e[1]));
                    if (d > 0) {
                        e[1] -= d;
                        graph[e[0]].get(e[2])[1] += d;
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
                    int[] e = graph[v].get(i);
                    if (e[1] > 0 && level[e[0]] < 0) {
                        level[e[0]] = level[v] + 1;
                        que[qh++] = e[0];
                    }
                }
            }
        }

        public int max_flow(int s, int t) {
            int flow = 0;
            while (true) {
                bfs(s);
                if (level[t] < 0) {
                    return flow;
                }
                Arrays.fill(itr, 0);
                while (true) {
                    int f = dfs(s, t, Integer.MAX_VALUE);
                    if (f <= 0) {
                        break;
                    }
                    flow += f;
                }
            }
        }
    }

    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
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