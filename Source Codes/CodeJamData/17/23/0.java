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
                public int n, q;
                public int[] e, s;
                public long[][] d;
                public int[] u, v;

                public void read(InputReader in) {
                    n = in.nextInt();
                    q = in.nextInt();
                    e = new int[n];
                    s = new int[n];
                    for (int i = 0; i < n; i++) {
                        e[i] = in.nextInt();
                        s[i] = in.nextInt();
                    }
                    d = new long[n][n];
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            d[i][j] = in.nextInt();
                        }
                    }
                    u = new int[q];
                    v = new int[q];
                    for (int i = 0; i < q; i++) {
                        u[i] = in.nextInt() - 1;
                        v[i] = in.nextInt() - 1;
                    }
                }

                public double[] res;

                public void solve() {
                    res = new double[q];
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (i == j) d[i][j] = 0;
                            else if (d[i][j] == -1) d[i][j] = 1L << 50;
                        }
                    }
                    for (int k = 0; k < n; k++) {
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < n; j++) {
                                d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                            }
                        }
                    }
                    double[] dist = new double[n];
                    boolean[] vis = new boolean[n];
                    for (int iter = 0; iter < q; iter++) {
                        Arrays.fill(dist, 1L << 60);
                        Arrays.fill(vis, false);
                        dist[v[iter]] = 0;
                        while (true) {
                            int mn = -1;
                            for (int i = 0; i < n; i++) {
                                if (!vis[i] && (mn == -1 || dist[i] < dist[mn])) {
                                    mn = i;
                                }
                            }
                            if (mn == -1) break;
                            vis[mn] = true;
                            for (int j = 0; j < n; j++) {
                                if (!vis[j] && d[j][mn] <= e[j]) {
                                    dist[j] = Math.min(dist[j], dist[mn] + d[j][mn] / (double) s[j]);
                                }
                            }
                        }
                        res[iter] = dist[u[iter]];
                    }
                }


                public void write(OutputWriter out, int testNumber) {
                    out.print("Case #" + testNumber + ":");
                    for (int i = 0; i < q; i++) {
                        out.printf(" %.10f", res[i]);
                    }
                    out.println();
                }
            }, 16);
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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
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

        public void println() {
            writer.println();
        }

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }

    static interface Task {
        public void read(InputReader in);

        public void solve();

        public void write(OutputWriter out, int testNumber);

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
}

