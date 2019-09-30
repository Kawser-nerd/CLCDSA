import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.util.concurrent.atomic.AtomicInteger;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                public int n, m;
                public char[][] grid;

                public void read(InputReader in) {
                    n = in.nextInt();
                    m = in.nextInt();
                    grid = new char[n][m];
                    for (int i = 0; i < n; i++) {
                        grid[i] = in.next().toCharArray();
                    }
                }

                public String ans;
                public char[][] agrid;

                public int hort(int a, int b) {
                    return 4 * (a * m + b) + 0;
                }

                public int horf(int a, int b) {
                    return 4 * (a * m + b) + 1;
                }

                public int vert(int a, int b) {
                    return 4 * (a * m + b) + 2;
                }

                public int verf(int a, int b) {
                    return 4 * (a * m + b) + 3;
                }

                public int top(int a, int b) {
                    if (grid[a][b] == '/') {
                        return vert(a, b);
                    } else if (grid[a][b] == '\\') {
                        return hort(a, b);
                    } else {
                        return vert(a, b);
                    }
                }

                public int bottom(int a, int b) {
                    if (grid[a][b] == '/') {
                        return hort(a, b);
                    } else if (grid[a][b] == '\\') {
                        return vert(a, b);
                    } else {
                        return vert(a, b);
                    }
                }

                public int left(int a, int b) {
                    if (grid[a][b] == '/') {
                        return vert(a, b);
                    } else if (grid[a][b] == '\\') {
                        return vert(a, b);
                    } else {
                        return hort(a, b);
                    }
                }

                public int right(int a, int b) {
                    if (grid[a][b] == '/') {
                        return hort(a, b);
                    } else if (grid[a][b] == '\\') {
                        return hort(a, b);
                    } else {
                        return hort(a, b);
                    }
                }

                public int ci = -1, cj = -1;
                public boolean ch;
                public int[][] pss;
                public boolean[][] dd;
                public int[][] count;

                public boolean bad(int a, int b, int dir) {
                    if (a < 0 || a >= n || b < 0 || b >= m) return false;
                    if (grid[a][b] == '-' || grid[a][b] == '|') return true;
                    if (grid[a][b] == '#') return false;
                    if (grid[a][b] == '/') dir ^= 3;
                    if (grid[a][b] == '\\') dir ^= 1;
                    return bad(a + dx[dir], b + dy[dir], dir);
                }

                public void getNeigh(int a, int b, int dir) {
                    if (a < 0 || a >= n || b < 0 || b >= m) return;
                    if (grid[a][b] == '#') return;
                    if (pss[a][b] != -1) {
                        int p = pss[a][b] / m, q = pss[a][b] % m;
                        if (ch) {
                            graph[horf(ci, cj)].add(vert(p, q));
                            graph[verf(p, q)].add(hort(ci, cj));
                        } else {
                            graph[verf(ci, cj)].add(hort(p, q));
                            graph[horf(p, q)].add(vert(ci, cj));
                        }
                    }
                    pss[a][b] = ci * m + cj;
                    count[a][b]++;
                    dd[a][b] = ch;
                    if (grid[a][b] == '/') dir ^= 1;
                    if (grid[a][b] == '\\') dir ^= 3;
                    getNeigh(a + dx[dir], b + dy[dir], dir);
                }

                public List<Integer>[] graph;

                public int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};

                public void solve() {
                    int nnodes = 2 * n * m;
                    pss = new int[n][m];
                    count = new int[n][m];
                    dd = new boolean[n][m];
                    for (int[] x : pss) Arrays.fill(x, -1);
                    graph = LUtils.genArrayList(nnodes * 2);
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (grid[i][j] == '#') continue;
                            if (grid[i][j] == '-' || grid[i][j] == '|') {
                                graph[hort(i, j)].add(verf(i, j));
                                graph[horf(i, j)].add(vert(i, j));
                                graph[vert(i, j)].add(horf(i, j));
                                graph[verf(i, j)].add(hort(i, j));
                            }
//                        if (grid[i][j] == '.') {
//                            graph[horf(i,j)].add(vert(i,j));
//                            graph[verf(i,j)].add(hort(i,j));
//                        }
//                        if (i>0&&grid[i-1][j] != '#') graph[top(i,j)].add(bottom(i-1,j));
//                        if (j>0&&grid[i][j-1] != '#') graph[left(i,j)].add(right(i,j-1));
//                        if (i+1<n&&grid[i+1][j]!='#') graph[bottom(i,j)].add(top(i+1,j));
//                        if (j+1<m&&grid[i][j+1]!='#') graph[right(i,j)].add(left(i,j+1));
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (grid[i][j] == '-' || grid[i][j] == '|') {
                                ci = i;
                                cj = j;
                                ch = true;
                                if (bad(i, j + 1, 3) || bad(i, j - 1, 1)) graph[hort(i, j)].add(horf(i, j));
                                else {
                                    getNeigh(i, j + 1, 3);
                                    getNeigh(i, j - 1, 1);
                                }
                                ch = false;
                                if (bad(i + 1, j, 2) || bad(i - 1, j, 0)) graph[vert(i, j)].add(verf(i, j));
                                else {
                                    getNeigh(i + 1, j, 2);
                                    getNeigh(i - 1, j, 0);
                                }
                            }
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (grid[i][j] != '.') continue;
                            if (count[i][j] == 0) {
                                ans = "IMPOSSIBLE";
                                return;
                            } else if (count[i][j] == 1) {
                                int p = pss[i][j] / m, q = pss[i][j] % m;
                                if (dd[i][j]) graph[horf(p, q)].add(hort(p, q));
                                else graph[verf(p, q)].add(vert(p, q));
                            }
                        }
                    }
                    boolean[] x = Sat2.solve2Sat(graph);
                    if (x == null) {
                        ans = "IMPOSSIBLE";
                        return;
                    }
                    ans = "POSSIBLE";
                    agrid = new char[n][m];
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (grid[i][j] == '-' || grid[i][j] == '|') {
                                int v = 2 * (i * m + j);
                                if (x[v]) agrid[i][j] = '-';
                                else agrid[i][j] = '|';
                            } else {
                                agrid[i][j] = grid[i][j];
                            }
                        }
                    }
                }


                public void write(OutputWriter out, int testNumber) {
                    out.println("Case #" + testNumber + ": " + ans);
                    if (ans.equals("POSSIBLE")) {
                        for (char[] x : agrid) out.println(new String(x));
                    }
                }
            }, 16);
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static interface TaskFactory {
        public Task newTask();

    }

    static class Sat2 {
        static void dfs1(List<Integer>[] graph, boolean[] used, List<Integer> order, int u) {
            used[u] = true;
            for (int v : graph[u])
                if (!used[v])
                    dfs1(graph, used, order, v);
            order.add(u);
        }

        static void dfs2(List<Integer>[] reverseGraph, int[] comp, int u, int color) {
            comp[u] = color;
            for (int v : reverseGraph[u])
                if (comp[v] == -1)
                    dfs2(reverseGraph, comp, v, color);
        }

        public static boolean[] solve2Sat(List<Integer>[] graph) {
            int n = graph.length;
            boolean[] used = new boolean[n];
            List<Integer> order = new ArrayList<>();
            for (int i = 0; i < n; ++i)
                if (!used[i])
                    dfs1(graph, used, order, i);

            List<Integer>[] reverseGraph = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            for (int i = 0; i < n; i++)
                for (int j : graph[i])
                    reverseGraph[j].add(i);

            int[] comp = new int[n];
            Arrays.fill(comp, -1);
            for (int i = 0, color = 0; i < n; ++i) {
                int u = order.get(n - i - 1);
                if (comp[u] == -1)
                    dfs2(reverseGraph, comp, u, color++);
            }

            for (int i = 0; i < n; ++i)
                if (comp[i] == comp[i ^ 1])
                    return null;

            boolean[] res = new boolean[n / 2];
            for (int i = 0; i < n; i += 2)
                res[i / 2] = comp[i] > comp[i ^ 1];
            return res;
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

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class Scheduler {
        private final AtomicInteger testsRemaining;
        private final AtomicInteger threadsRemaining;

        public Scheduler(InputReader in, OutputWriter out, TaskFactory factory, int numParallel) {
            try {
                testsRemaining = new AtomicInteger(in.nextInt());
                threadsRemaining = new AtomicInteger(numParallel);
                Task[] tasks = new Task[testsRemaining.get()];
                for (int i = 0; i < tasks.length; i++) {
                    tasks[i] = factory.newTask();
                }
                for (Task task : tasks) {
                    task.read(in);
                    new Thread(() -> {
                        boolean freeThread = false;
                        synchronized (this) {
                            do {
                                try {
                                    wait(10);
                                } catch (InterruptedException ignored) {
                                }
                                if (threadsRemaining.get() != 0) {
                                    synchronized (threadsRemaining) {
                                        if (threadsRemaining.get() != 0) {
                                            threadsRemaining.decrementAndGet();
                                            freeThread = true;
                                        }
                                    }
                                }
                            } while (!freeThread);
                        }
                        task.solve();
                        System.err.println(testsRemaining.decrementAndGet());
                        threadsRemaining.incrementAndGet();
                    }).start();
                }
                synchronized (this) {
                    while (testsRemaining.get() > 0) {
                        wait(10);
                    }
                }
                for (int i = 0; i < tasks.length; i++) {
                    tasks[i].write(out, i + 1);
                }
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }

    static interface Task {
        public void read(InputReader in);

        public void solve();

        public void write(OutputWriter out, int testNumber);

    }
}

