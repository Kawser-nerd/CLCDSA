// package atcoder.arc049;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by hama_du on 2016/03/19.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[][] a = new int[in.nextInt()][2];
        for (int i = 0; i < a.length ; i++) {
            for (int j = 0; j < 2 ; j++) {
                a[i][j] = in.nextInt()-1;
            }
        }
        int[][] b = new int[in.nextInt()][2];
        for (int i = 0; i < b.length ; i++) {
            for (int j = 0; j < 2 ; j++) {
                b[i][j] = in.nextInt()-1;
            }
        }

        int max = 0;
        int an = a.length;
        int bn = b.length;
        for (int ptn = 0; ptn < (1<<bn) ; ptn++) {
            List<Integer>[] graph = new List[n];
            for (int i = 0; i < n ; i++) {
                graph[i] = new ArrayList<>();
            }

            Set<Integer> ignoreVertex = new HashSet<>();
            for (int i = 0; i < bn ; i++) {
                if ((ptn & (1<<i)) >= 1) {
                    graph[b[i][0]].add(b[i][1]);
                } else {
                    ignoreVertex.add(b[i][0]);
                }
            }
            for (int i = 0; i < an ; i++) {
                graph[a[i][1]].add(a[i][0]);
            }
            max = Math.max(max, toposort(graph, ignoreVertex));
        }
        out.println(max);
        out.flush();
    }

    static int toposort(List<Integer>[] graph, Set<Integer> ignore) {
        int n = graph.length;
        int[] in = new int[n];
        for (int i = 0 ; i < n ; i++) {
            for (int t : graph[i]) {
                in[t]++;
            }
        }

        int[] res = new int[n];
        int idx = 0;
        for (int i = 0 ; i < n ; i++) {
            if (in[i] == 0) {
                res[idx++] = i;
            }
        }
        for (int i = 0 ; i < idx ; i++) {
            for (int t : graph[res[i]]) {
                in[t]--;
                if (in[t] == 0 && !ignore.contains(t)) {
                    res[idx++] = t;
                }
            }
        }
        return idx;
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
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
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.