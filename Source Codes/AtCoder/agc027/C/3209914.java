// package agc.agc027;

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
        int m = in.nextInt();
        char[] s = in.nextToken().toCharArray();
        int[] ab = new int[n];
        for (int i = 0; i < s.length; i++) {
            ab[i] = s[i] == 'A' ? 0 : 1;
        }

        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n ; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < m ; i++) {
            int a = in.nextInt()-1;
            int b = in.nextInt()-1;
            if (a != b) {
                graph[a].add(b);
                graph[b].add(a);
            } else {
                graph[a].add(a);
            }
        }

        List<Integer>[] dg2 = new List[2*n];
        for (int i = 0; i < dg2.length ; i++) {
            dg2[i] = new ArrayList<>();
        }
        for (int i = 0; i < n ; i++) {
            for (int j : graph[i]) {
                if (ab[i] == ab[j]) {
                    dg2[i].add(n+j);
                    dg2[j].add(n+i);
                } else {
                    dg2[n+i].add(j);
                    dg2[n+j].add(i);
                }
            }
        }

        out.println(toposort(dg2) == null ? "Yes" : "No");
        out.flush();
    }

    static int[] toposort(List<Integer>[] graph) {
        int n = graph.length;
        int[] in = new int[n];
        for (int i = 0 ; i < n ; i++) {
            for (int t : graph[i]) {
                in[t]++;
            }
        }

        Queue<Integer> q = new PriorityQueue<>();
        int[] res = new int[n];
        for (int i = 0 ; i < n ; i++) {
            if (in[i] == 0) {
                q.add(i);
            }
        }

        int idx = 0;
        while (q.size() >= 1) {
            int now = q.poll();
            res[idx++] = now;
            for (int t : graph[now]) {
                in[t]--;
                if (in[t] == 0) {
                    q.add(t);
                }
            }
        }
        for (int i = 0 ; i < n ; i++) {
            if (in[i] >= 1) {
                return null;
            }
        }
        return res;
    }




    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
    }

    private static void debug(Object... o) {
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