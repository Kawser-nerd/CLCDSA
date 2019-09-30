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
            final String regex = "B-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                public int n;
                public int[] freq;
                public char[] cc;

                public void read(InputReader in) {
                    n = in.nextInt();
                    freq = new int[8];
                    cc = new char[8];
                    freq[0b001] = in.nextInt();
                    freq[0b011] = in.nextInt();
                    freq[0b010] = in.nextInt();
                    freq[0b110] = in.nextInt();
                    freq[0b100] = in.nextInt();
                    freq[0b101] = in.nextInt();
                    cc[0b001] = 'R';
                    cc[0b011] = 'O';
                    cc[0b010] = 'Y';
                    cc[0b110] = 'G';
                    cc[0b100] = 'B';
                    cc[0b101] = 'V';
                }

                public String ans;

                public void solve() {
                    for (int bit = 0; bit < 3; bit++) {
                        int count = 0;
                        for (int i = 0; i < 8; i++) {
                            if (((i >> bit) & 1) == 1) {
                                count += freq[i];
                            }
                        }
                        if (count * 2 > n) {
                            ans = "IMPOSSIBLE";
                            return;
                        }
                    }

                    int[] ncount = new int[3];
                    for (int bit = 0; bit < 3; bit++) {
                        int x = 1 << bit;
                        int y = 7 ^ x;
                        if (freq[x] + freq[y] == n) {
                            if (freq[x] != freq[y]) {
                                ans = "IMPOSSIBLE";
                                return;
                            } else {
                                StringBuffer b = new StringBuffer();
                                for (int i = 0; i < n; i += 2) {
                                    b.append(cc[x]);
                                    b.append(cc[y]);
                                }
                                ans = b.toString();
                                return;
                            }
                        }
                        if (freq[x] == 0 && freq[y] == 0) continue;
                        if (freq[y] >= freq[x]) {
                            ans = "IMPOSSIBLE";
                            return;
                        }
                        ncount[bit] = freq[x] - freq[y];
                    }

                    int mx = 0, which = -1;
                    int s = ncount[0] + ncount[1] + ncount[2];
                    for (int i = 0; i < 3; i++) {
                        if (ncount[i] * 2 > s) {
                            ans = "IMPOSSIBLE";
                            return;
                        }
                        if (ncount[i] > mx) {
                            mx = ncount[i];
                            which = i;
                        }
                    }
                    int o1 = 0, o2 = 0;
                    while (o1 == which) o1++;
                    while (o2 == o1 || o2 == which) o2++;
                    StringBuffer b = new StringBuffer();
                    while (ncount[which] > 0) {
                        b.append(cc[1 << which]);
                        if (--ncount[which] == 0) break;
                        if (ncount[o1] > ncount[o2]) {
                            ncount[o1]--;
                            b.append(cc[1 << o1]);
                        } else {
                            ncount[o2]--;
                            b.append(cc[1 << o2]);
                        }
                    }
                    if (ncount[o1] + ncount[o2] == 0 || Math.abs(ncount[o1] - ncount[o2]) > 1) {
                        ans = "IMPOSSIBLE";
                        return;
                    }

                    while (ncount[o1] > 0 || ncount[o2] > 0) {
                        if (ncount[o1] > ncount[o2]) {
                            ncount[o1]--;
                            b.append(cc[1 << o1]);
                        } else {
                            ncount[o2]--;
                            b.append(cc[1 << o2]);
                        }
                    }
                    ans = b.toString();
                    for (int bit = 0; bit < 3; bit++) {
                        int x = 1 << bit;
                        int y = 7 ^ x;
                        if (freq[y] > 0) {
                            StringBuffer ss = new StringBuffer();
                            ss.append(cc[x]);
                            while (freq[y]-- > 0) {
                                ss.append(cc[y]);
                                ss.append(cc[x]);
                            }
                            ans = ans.replaceFirst("" + cc[x], ss.toString());
                        }
                    }
                }


                public void write(OutputWriter out, int testNumber) {
                    out.println("Case #" + testNumber + ": " + ans);
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

        public void println(Object... objects) {
            print(objects);
            writer.println();
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

