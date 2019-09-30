// package arc.arc090;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    static int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();

        graph = new List[n];
        for (int i = 0; i < n ; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < m ; i++) {
            int l = in.nextInt()-1;
            int r = in.nextInt()-1;
            int d = in.nextInt();
            graph[l].add(new int[]{r, d});
            graph[r].add(new int[]{l, -d});
        }
        weight = new int[n];
        Arrays.fill(weight, INF);

        for (int i = 0; i < n ; i++) {
            if (weight[i] == INF) {
                dfs(i, 0);
            }
        }

        boolean isOK = true;
        for (int f = 0; f < n ; f++) {
            for (int[] e : graph[f]) {
                int t = e[0];
                // w[f] + e[1] == w[t]
                isOK &= (weight[f] + e[1] == weight[t]);
            }
        }
        out.println(isOK ? "Yes" : "No");
        out.flush();
    }

    static List<int[]>[] graph;
    static int[] weight;

    static void dfs(int now, int v) {
        if (weight[now] != INF) {
            return;
        }
        weight[now] = v;
        for (int[] g : graph[now]) {
            int to = g[0];
            dfs(to, v + g[1]);
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.