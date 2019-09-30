import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public int n;
        public List<TaskD.Edge>[] graph;
        public int[] size;
        public long ans;
        public long[] ss;
        public ArrayList<Integer> centroids;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, c = in.nextInt();
                graph[a].add(new TaskD.Edge(b, c));
                graph[b].add(new TaskD.Edge(a, c));
            }

            size = new int[n];
            calcSizes(0, -1);
            centroids = new ArrayList<>();
            findTreeCentroid(0, -1, n);
            long ans = 0;
            for (int x : centroids) ans = Math.max(ans, solve(x));
            out.println(ans);
        }

        public long solve(int cent) {
            ans = 0;
            ss = new long[n];
            dfs3(cent, -1, 0);
            AUtils.sort(ss);
            ans *= 2;
            if (n % 2 == 0) {
                boolean found = false;
                for (TaskD.Edge e : graph[cent]) {
                    int v = e.to;
                    if (size[v] == n / 2) {
                        ans -= e.weight;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ans -= ss[1];
                }
            } else {
                ans -= ss[1];
            }
            return ans;
        }

        void dfs3(int u, int p, long weight) {
            ans += weight;
            ss[u] = weight;
            for (TaskD.Edge e : graph[u]) {
                int v = e.to;
                if (v == p) continue;
                dfs3(v, u, weight + e.weight);
            }
        }

        void calcSizes(int u, int p) {
            size[u] = 1;
            for (TaskD.Edge e : graph[u]) {
                int v = e.to;
                if (v == p) continue;
                calcSizes(v, u);
                size[u] += size[v];
            }
        }

        int findTreeCentroid(int u, int p, int vertices) {
            for (TaskD.Edge e : graph[u]) {
                int v = e.to;
                if (v == p) continue;
                if (size[v] > vertices / 2) {
                    return findTreeCentroid(v, u, vertices);
                }
            }
            centroids.add(u);
            return u;
        }

        static class Edge {
            public int to;
            public int weight;

            public Edge(int to, int weight) {
                this.to = to;
                this.weight = weight;
            }

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

        public void println(long i) {
            writer.println(i);
        }

    }

    static class AUtils {
        public static void sort(long[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    long t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            Arrays.sort(arr);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.