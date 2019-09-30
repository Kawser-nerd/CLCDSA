import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Objects;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DConnectivity solver = new DConnectivity();
        solver.solve(1, in, out);
        out.close();
    }

    static class DConnectivity {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int l = in.nextInt();

            DsuInteger road = new DsuInteger(n);

            for (int i = 0; i < n; i++) {
                road.createSet(i);
            }

            DsuInteger rail = new DsuInteger(n);

            for (int i = 0; i < n; i++) {
                rail.createSet(i);
            }

//        DsuInteger merge = new DsuInteger(n);
//
//        for (int i = 0; i < n; i++) {
//            merge.createSet(i);
//        }

            int[] ua = new int[l + k];
            int[] va = new int[l + k];

            for (int i = 0; i < k; i++) {
                int u = in.nextInt();
                int v = in.nextInt();

                u--;
                v--;

                ua[i] = u;
                ua[i] = v;

                road.mergeSets(u, v);
            }

            for (int i = 0; i < l; i++) {
                int u = in.nextInt();
                int v = in.nextInt();

                u--;
                v--;

                ua[i + k] = u;
                va[i + k] = v;

                rail.mergeSets(u, v);
            }

            Map<mark, Integer> map = new HashMap<>();

            for (int i = 0; i < n; i++) {
                int s1 = road.findSet(i);
                int s2 = rail.findSet(i);

                map.merge(new mark(s1, s2), 1, (x, y) -> x + y);
            }

//        for (int i = 0; i < l + k; i++) {
//            int u = ua[i];
//            int v = va[i];
//
//            int s1 = road.findSet(u);
//            int s2 = road.findSet(v);
//
//            int s3 = rail.findSet(u);
//            int s4 = rail.findSet(v);
//
//            if (s1 == s2 && s3 == s4) {
//                merge.mergeSets(u, v);
//            }
//        }

            for (int i = 0; i < n; i++) {
                int s1 = road.findSet(i);
                int s2 = rail.findSet(i);

                out.println(map.get(new mark(s1, s2)));
            }
        }

        class DsuInteger {
            int[] parent;
            int[] rank;
            int[] size;
            int n;

            public DsuInteger(int n) {
                this.n = n;
                this.parent = new int[n];
                this.rank = new int[n];
                this.size = new int[n];
            }

            int createSet(int x) {
                parent[x] = x;
                rank[x] = 0;
                size[x] = 1;
                return x;
            }

            int findSet(int x) {
                int par = parent[x];
                if (x != par) {
                    parent[x] = findSet(par);
                    return parent[x];
                }
                return par;
            }

            int mergeSets(int x, int y) {
                int rx = findSet(x);
                int ry = findSet(y);

                if (rx == ry) {
                    return rx;
                }

                int fp = -1;

                if (rank[rx] > rank[ry]) {
                    parent[ry] = rx;
                    fp = rx;
                } else {
                    parent[rx] = ry;
                    fp = ry;
                }

                size[fp] = size[rx] + size[ry];

                if (rank[rx] == rank[ry]) {
                    rank[ry] = rank[ry] + 1;
                }

                return fp;
            }

        }

        class mark {
            int s1;
            int s2;

            public mark(int s1, int s2) {
                this.s1 = s1;
                this.s2 = s2;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                mark mark = (mark) o;
                return s1 == mark.s1 &&
                        s2 == mark.s2;
            }

            public int hashCode() {
                return Objects.hash(s1, s2);
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
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
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}