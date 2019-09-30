import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Locale;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "A-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                public int n;
                public int p;
                public int[] arr;

                public void read(InputReader in) {
                    n = in.nextInt();
                    p = in.nextInt();
                    arr = in.readIntArray(n);
                }

                public int ans;

                public void solve() {
                    int[] freq = new int[p];
                    for (int i = 0; i < n; i++) {
                        freq[arr[i] % p]++;
                    }
                    if (p == 2) {
                        ans = freq[0] + (freq[1] + 1) / 2;
                    } else if (p == 3) {
                        dp2 = new int[n + 1][n + 1][3];
                        for (int[][] x : dp2) for (int[] y : x) Arrays.fill(y, -1);
                        ans = freq[0] + dfs2(freq[1], freq[2], 0);
                    } else {
                        dp = new int[n + 1][n + 1][n + 1][4];
                        for (int[][][] x : dp) for (int[][] y : x) for (int[] z : y) Arrays.fill(z, -1);
                        ans = freq[0] + dfs(freq[1], freq[2], freq[3], 0);
                    }
                }

                public int[][][] dp2;

                public int dfs2(int a, int b, int leftover) {
                    if (a == 0 && b == 0) return 0;
                    if (dp2[a][b][leftover] != -1) {
                        return dp2[a][b][leftover];
                    }
                    int add = leftover == 0 ? 1 : 0;
                    int ret = 0;
                    if (a > 0) ret = Math.max(ret, add + dfs2(a - 1, b, (leftover + 1) % 3));
                    if (b > 0) ret = Math.max(ret, add + dfs2(a, b - 1, (leftover + 2) % 3));
                    return dp2[a][b][leftover] = ret;
                }

                public int[][][][] dp;

                public int dfs(int a, int b, int c, int leftover) {
                    if (a == 0 && b == 0 && c == 0) return 0;
                    if (dp[a][b][c][leftover] != -1) {
                        return dp[a][b][c][leftover];
                    }
                    int add = leftover == 0 ? 1 : 0;
                    int ret = 0;
                    if (a > 0) ret = Math.max(ret, add + dfs(a - 1, b, c, (leftover + 1) % 4));
                    if (b > 0) ret = Math.max(ret, add + dfs(a, b - 1, c, (leftover + 2) % 4));
                    if (c > 0) ret = Math.max(ret, add + dfs(a, b, c - 1, (leftover + 3) % 4));
                    return dp[a][b][c][leftover] = ret;

                }


                public void write(OutputWriter out, int testNumber) {
                    out.println("Case #" + testNumber + ": " + ans);
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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
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
}

