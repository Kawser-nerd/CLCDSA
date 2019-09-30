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
            final String regex = "D-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("d.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                public int r, c, m;
                public char[][] grid;

                public void read(InputReader in) {
                    c = in.nextInt();
                    r = in.nextInt();
                    m = in.nextInt();
                    grid = new char[r][c];
                    for (int i = 0; i < r; i++) {
                        grid[i] = in.next().toCharArray();
                    }
                }

                public int[] dx = new int[]{-1, 0, 1, 0}, dy = new int[]{0, 1, 0, -1};
                public int[][] sidx, tidx;
                public int[][] ps, pt;

                public void solve() {
                    int sf = 0, tf = 0;
                    ps = new int[r * c][];
                    pt = new int[r * c][];
                    sidx = new int[r][c];
                    tidx = new int[r][c];
                    for (int i = 0; i < r; i++) {
                        Arrays.fill(sidx[i], -1);
                        Arrays.fill(tidx[i], -1);
                    }
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            if (grid[i][j] == 'S') {
                                sidx[i][j] = sf;
                                ps[sf] = new int[]{i, j};
                                sf++;
                            }
                            if (grid[i][j] == 'T') {
                                tidx[i][j] = tf;
                                pt[tf] = new int[]{i, j};
                                tf++;
                            }
                        }
                    }
                    boolean[][][] c1 = new boolean[tf][r][c];
                    for (int turret = 0; turret < tf; turret++) {
                        for (int k = 0; k < 4; k++) {
                            int x = pt[turret][0] + dx[k], y = pt[turret][1] + dy[k];
                            while (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != '#') {
                                c1[turret][x][y] = true;
                                x += dx[k];
                                y += dy[k];
                            }
                        }
                    }
                    boolean[][][] can = new boolean[1 << tf][sf][tf];
                    int[] queue = new int[r * c];
                    int[][] dist = new int[r][c];
                    int front, back;
                    for (int active = 0; active < 1 << tf; active++) {
                        for (int soldier = 0; soldier < sf; soldier++) {
                            front = 0;
                            back = 0;
                            for (int[] x : dist) Arrays.fill(x, 1 << 29);
                            queue[back++] = ps[soldier][0] * c + ps[soldier][1];
                            dist[ps[soldier][0]][ps[soldier][1]] = 0;
                            while (front < back) {
                                int cx = queue[front] / c, cy = queue[front] % c;
                                front++;
                                boolean ok = dist[cx][cy] < m;
                                for (int turret = 0; turret < tf; turret++) {
                                    if ((active & (1 << turret)) != 0 && c1[turret][cx][cy]) {
                                        can[active][soldier][turret] = true;
                                        ok = false;
                                    }
                                }
                                if (ok) {
                                    for (int k = 0; k < 4; k++) {
                                        int nx = cx + dx[k], ny = cy + dy[k];
                                        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                                            if (grid[nx][ny] == '#') continue;
                                            if (grid[nx][ny] == 'T') {
                                                if (((active & (1 << tidx[nx][ny]))) != 0)
                                                    continue;
                                            }
                                            if (dist[nx][ny] > dist[cx][cy] + 1) {
                                                dist[nx][ny] = dist[cx][cy] + 1;
                                                queue[back++] = nx * c + ny;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    best = -1;
                    res = null;
                    if (tf >= sf) {
                        int[] perm = new int[tf];
                        for (int i = 0; i < tf; i++) perm[i] = i;
                        do {
                            int active = (1 << tf) - 1;
                            ArrayList<Pair<Integer, Integer>> ps = new ArrayList<>();
                            boolean[] used = new boolean[sf];
                            for (int rounds = 0; rounds < sf; rounds++) {
                                for (int x = 0; x < sf; x++) {
                                    if (!used[x]) {
                                        if (can[active][x][perm[x]]) {
                                            ps.add(new Pair(x, perm[x]));
                                            active ^= 1 << perm[x];
                                            used[x] = true;
                                        }
                                    }
                                }
                            }
                            if (ps.size() > best) {
                                best = ps.size();
                                res = ps;
                            }

                        } while (Permutations.nextPermutation(perm));
                    } else {
                        int[] perm = new int[sf];
                        for (int i = 0; i < sf; i++) perm[i] = i;
                        do {
                            int active = (1 << tf) - 1;
                            ArrayList<Pair<Integer, Integer>> ps = new ArrayList<>();
                            for (int rounds = 0; rounds < tf; rounds++) {
                                for (int x = 0; x < tf; x++) {
                                    if ((active & (1 << x)) != 0) {
                                        if (can[active][perm[x]][x]) {
                                            ps.add(new Pair(perm[x], x));
                                            active ^= 1 << x;
                                        }
                                    }
                                }
                            }
                            if (ps.size() > best) {
                                best = ps.size();
                                res = ps;
                            }
                        } while (Permutations.nextPermutation(perm));
                    }
                }

                public int best;
                public ArrayList<Pair<Integer, Integer>> res;

                public void write(OutputWriter out, int testNumber) {
                    out.println("Case #" + testNumber + ": " + best);
                    for (Pair<Integer, Integer> x : res) {
                        out.println((x.u + 1) + " " + (x.v + 1));
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

    static interface Task {
        public void read(InputReader in);

        public void solve();

        public void write(OutputWriter out, int testNumber);

    }

    static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<Pair<U, V>> {
        public final U u;
        public final V v;

        public Pair(U u, V v) {
            this.u = u;
            this.v = v;
        }

        public int hashCode() {
            return (u == null ? 0 : u.hashCode() * 31) + (v == null ? 0 : v.hashCode());
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<U, V> p = (Pair<U, V>) o;
            return (u == null ? p.u == null : u.equals(p.u)) && (v == null ? p.v == null : v.equals(p.v));
        }

        public int compareTo(Pair<U, V> b) {
            int cmpU = u.compareTo(b.u);
            return cmpU != 0 ? cmpU : v.compareTo(b.v);
        }

    }

    static class Permutations {
        public static boolean nextPermutation(int[] p) {
            for (int a = p.length - 2; a >= 0; --a)
                if (p[a] < p[a + 1])
                    for (int b = p.length - 1; ; --b)
                        if (p[b] > p[a]) {
                            int t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                            for (++a, b = p.length - 1; a < b; ++a, --b) {
                                t = p[a];
                                p[a] = p[b];
                                p[b] = t;
                            }
                            return true;
                        }
            return false;
        }

    }
}

