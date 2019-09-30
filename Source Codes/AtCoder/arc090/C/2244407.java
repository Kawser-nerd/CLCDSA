// package arc.arc090;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();

        int s = in.nextInt()-1;
        int t = in.nextInt()-1;

        graph = new List[n];
        for (int i = 0; i < n ; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < m ; i++) {
//            int l = 0;
//            int r = 0;
//            int d = (int)(Math.random() * 1) + 1;
//            while (l == r) {
//                l = (int)(Math.random() * n);
//                r = (int)(Math.random() * n);
//            }

            int l = in.nextInt()-1;
            int r = in.nextInt()-1;
            int d = in.nextInt();
            graph[l].add(new int[]{r, d});
            graph[r].add(new int[]{l, d});
        }

        long[] fromSDistance, fromSPtn;
        long[] fromTDistance, fromTPtn;

        {
            long[][] fromS = doit(s);
            fromSDistance = fromS[0];
            fromSPtn = fromS[1];

            long[][] fromT = doit(t);
            fromTDistance = fromT[0];
            fromTPtn = fromT[1];
        }

        if (fromSPtn[t] != fromTPtn[s]) {
            throw new RuntimeException("unk");
        }

        long all = fromSPtn[t] * fromTPtn[s] % MOD;
        long D = fromSDistance[t];

        long removePath = 0;
        long removeVec = 0;
        for (int i = 0; i < n ; i++) {
            for (int[] e : graph[i]) {
                int from = i;
                int to = e[0];
                long d = e[1];

                if (fromSDistance[from] + d + fromTDistance[to] == D) {
                    if (fromSDistance[from] + d == fromSDistance[to]) {
                        if (fromTDistance[to] + d == fromTDistance[from]) {
                            long abs = Math.abs(fromSDistance[from] - fromTDistance[to]);
                            if (abs < d) {
                                long way = fromSPtn[from] * fromTPtn[to] % MOD;
                                removePath += way * way % MOD;
                            }
                        }
                    }
                }

                if (fromSDistance[to] + d + fromTDistance[from] == D) {
                    if (fromSDistance[to] + d == fromSDistance[from]) {
                        if (fromTDistance[from] + d == fromTDistance[to]) {
                            long abs = Math.abs(fromSDistance[to] - fromTDistance[from]);
                            if (abs < d) {
                                long way = fromSPtn[to] * fromTPtn[from] % MOD;
                                removePath += way * way % MOD;
                            }
                        }
                    }
                }
                removePath %= MOD;
            }

            if (fromSDistance[i] == fromTDistance[i] && fromSDistance[i] + fromTDistance[i] == D) {
                long way = fromSPtn[i] * fromTPtn[i] % MOD;
                removeVec += way * way % MOD;
                removeVec %= MOD;
            }
        }


//        debug(fromSDistance, fromSPtn);
//        debug(fromTDistance, fromTPtn);
//        debug(all, removePath, removeVec);

        all += MOD - removePath*inv(2)%MOD;
        all += MOD - removeVec;

        out.println(all%MOD);
        out.flush();
    }

    static long pow(long a, long x) {
        long res = 1;
        while (x > 0) {
            if (x % 2 != 0) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            x /= 2;
        }
        return res;
    }

    static long inv(long a) {
        return pow(a, MOD - 2) % MOD;
    }

    static long[][] doit(int start) {
        int n = graph.length;
        long[] distance = new long[n];
        long[] ptn = new long[n];
        Arrays.fill(distance, INF);

        distance[start] = 0;
        ptn[start] = 1;

        Queue<State> que = new PriorityQueue<>();
        que.add(new State(start, 0));
        while (que.size() >= 1) {
            State st = que.poll();
            if (distance[st.now] < st.time) {
                continue;
            }
            for (int[] t : graph[st.now]) {
                int to = t[0];
                long d = st.time + t[1];
                if (distance[to] > d) {
                    distance[to] = d;
                    ptn[to] = ptn[st.now];
                    que.add(new State(to, d));
                } else if (distance[to] == d) {
                    ptn[to] += ptn[st.now];
                    ptn[to] %= MOD;
                }
            }
        }
        return new long[][]{distance, ptn};
    }

    static class State implements Comparable<State> {
        int now;
        long time;

        public State(int n, long t) {
            now = n;
            time = t;
        }

        @Override
        public int compareTo(State o) {
            return Long.compare(time, o.time);
        }
    }

    static List<int[]>[] graph;
    static long INF = Long.MAX_VALUE;

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.