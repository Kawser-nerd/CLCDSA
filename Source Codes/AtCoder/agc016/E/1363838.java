import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public int idx;
        public HashMap<TaskE.State, Integer> mp;
        public List<Integer>[] graph;
        public int[] vis;
        public int vidx;

        public int getIdx(int time, int node) {
            TaskE.State s = new TaskE.State(time, node);
            Integer x = mp.get(s);
            if (x != null) return x;
            mp.put(s, idx++);
            return idx - 1;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            mp = new HashMap<>();
            idx = 0;
            int n = in.nextInt(), m = in.nextInt();
            graph = LUtils.genArrayList((n + 2 * m + 1010) * 2);
            int[] lasttime = new int[n];
            for (int i = 0; i < n; i++) {
                getIdx(0, i);
            }
            // 0 -> alive, 1 -> dead
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                lasttime[a]++;
                lasttime[b]++;

                int a1 = getIdx(lasttime[a], a), a2 = getIdx(lasttime[a] - 1, a);
                int b1 = getIdx(lasttime[b], b), b2 = getIdx(lasttime[b] - 1, b);

                graph[2 * a1 + 0].add(2 * b2 + 0);
                graph[2 * a1 + 0].add(2 * b1 + 1);
                graph[2 * a1 + 0].add(2 * a2 + 0);
                graph[2 * a2 + 1].add(2 * a1 + 1);

                graph[2 * b1 + 0].add(2 * a2 + 0);
                graph[2 * b1 + 0].add(2 * a1 + 1);
                graph[2 * b1 + 0].add(2 * b2 + 0);
                graph[2 * b2 + 1].add(2 * b1 + 1);
            }

            vis = new int[graph.length];
            vidx = 0;

            boolean[] canalive = new boolean[n];
            int[][] firstd = new int[n][n];
            int[][] lasta = new int[n][n];
            for (int i = 0; i < n; i++) {
                vidx++;
                canalive[i] = dfs(2 * getIdx(lasttime[i], i) + 0);
                for (int j = 0; j < n; j++) {
                    {
                        int lo = 0, hi = lasttime[j] + 1;
                        while (lo < hi) {
                            int mid = (lo + hi) / 2;
                            if (vis[2 * getIdx(mid, j) + 1] == vidx) hi = mid;
                            else lo = mid + 1;
                        }
                        firstd[i][j] = lo;
                    }
                    {
                        int lo = 0, hi = lasttime[j];
                        while (lo < hi) {
                            int mid = (lo + hi + 1) / 2;
                            if (vis[2 * getIdx(mid, j) + 0] == vidx) lo = mid;
                            else hi = mid - 1;
                        }
                        lasta[i][j] = lo;
                    }
                }
            }
            int ret = 0;
            for (int i = 0; i < n; i++) {
                if (!canalive[i]) continue;
                for (int j = i + 1; j < n; j++) {
                    if (!canalive[j]) continue;
                    boolean ok = true;
                    for (int k = 0; ok && k < n; k++) {
                        if (Math.max(lasta[i][k], lasta[j][k]) >= Math.min(firstd[i][k], firstd[j][k])) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        ret++;
                    }
                }
            }
            out.println(ret);
        }

        public boolean dfs(int j) {
            if (vis[j ^ 1] == vidx) return false;
            vis[j] = vidx;
            for (int k : graph[j]) {
                if (vis[k] != vidx && !dfs(k)) return false;
            }
            return true;
        }

        static class State {
            public int time;
            public int node;

            public State(int time, int node) {
                this.time = time;
                this.node = node;
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                TaskE.State state = (TaskE.State) o;

                if (time != state.time) return false;
                return node == state.node;
            }


            public int hashCode() {
                int result = time;
                result = 31 * result + node;
                return result;
            }

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.