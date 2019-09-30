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
 *
 * @author Egor Kulikov (egor@egork.net)
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
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
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
        static TaskC.Angle add(TaskC.Angle a1, TaskC.Angle a2) {
            return new TaskC.Angle(a1.cos * a2.cos - a1.sin * a2.sin, a1.sin * a2.cos + a2.sin * a1.cos);
        }

        static TaskC.Angle subtract(TaskC.Angle a1, TaskC.Angle a2) {
            return new TaskC.Angle(a1.cos * a2.cos + a1.sin * a2.sin, a1.sin * a2.cos - a2.sin * a1.cos);
        }

        static int compare(TaskC.Angle a1, TaskC.Angle a2) {
            return Double.compare(a2.cos, a1.cos);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                int n;
                int r;


                public void read(InputReader in) {
                    n = in.readInt();
                    r = in.readInt();
                }

                long answer;
                TaskC.Angle[][] mi;
                TaskC.Angle[][] ma;
//            double[][] cmi;
//            double[][] cma;

                double cosmi(int r0, int c0) {
//                if (cmi[r0][c0] != 0) {
//                    return cmi[r0][c0];
//                }
//                return cmi[r0][c0] = cos(angleLeft(r0, c0)) / sin(angleLeft(r0, c0));
                    return mi[r0][c0].cos / mi[r0][c0].sin;
                }

                double cosma(int r0, int c0) {
//                if (cma[r0][c0] != 0) {
//                    return cma[r0][c0];
//                }
//                return cma[r0][c0] = cos(angleRight(r0, c0)) / sin(angleRight(r0, c0));
                    return ma[r0][c0].cos / ma[r0][c0].sin;
                }

                void solve(int r0, int c0, int r1, int c1, int h) {
                    if (h == n) {
                        return;
                    }
                    TaskC.Angle maxAngle = angleRight(r0, c0);
                    TaskC.Angle minAngle = angleLeft(r1, c1);
                    if (compare(maxAngle, minAngle) <= 0) {
                        return;
                    }
                    double from = cosma(r0, c0) * h;
                    double to = cosmi(r1, c1) * h;
                    int start = (int) from - 1;
                    start = Math.max(start, 0);
                    if (c0 == h) {
                        start = Math.max(start, r0 + 1);
                    }
                    int end = (int) to + 2;
                    end = Math.min(end, h - 1);
                    for (int i = start; i <= end; i++) {
                        TaskC.Angle cMax = angleRight(i, h);
                        TaskC.Angle cMin = angleLeft(i, h);
                        if (compare(cMin, minAngle) > 0 && compare(cMax, maxAngle) < 0) {
                            answer += 2;
                            solve(r0, c0, i, h, h + 1);
                            solve(i, h, r1, c1, h);
                            return;
                        }
                    }
                    solve(r0, c0, r1, c1, h + 1);
                }

                private TaskC.Angle angleRight(int r0, int c0) {
                    if (ma[r0][c0] != null) {
                        return ma[r0][c0];
                    }
                    return (ma[r0][c0] = subtract(angle(r0, c0), relativeAngle(r0, c0)));
                }

                private TaskC.Angle angle(int r0, int c0) {
                    return new TaskC.Angle((long) r0, (long) c0);
                }

                private TaskC.Angle angleLeft(int r0, int c0) {
                    if (mi[r0][c0] != null) {
                        return mi[r0][c0];
                    }
                    return (mi[r0][c0] = add(angle(r0, c0), relativeAngle(r0, c0)));
                }

                private TaskC.Angle relativeAngle(int r0, int c0) {
                    return new TaskC.Angle(r / 1e6 / Math.hypot(r0, c0));
                }


                public void solve() {
                    mi = new TaskC.Angle[n][n];
                    ma = new TaskC.Angle[n][n];
//                cmi = new double[n][n];
//                cma = new double[n][n];
                    answer = 3;
                    solve(0, 1, 1, 1, 2);
                }


                public void write(OutputWriter out, int testNumber) {
                    out.printLine("Case #" + testNumber + ":", answer);
                }
            }, 8);
        }

        static class Angle {
            double cos;
            double sin;

            Angle(long x, long y) {
//            long g = gcd(x, y);
//            x /= g;
//            y /= g;
                double dst = Math.hypot(x, y);
                cos = x / dst;
                sin = y / dst;
//            d = cos + sin;
//            cos = x / dst;
//            sin = y / dst;
            }

            Angle(double sin) {
//            long g = gcd(num, den);
//            num /= g;
//            den /= g;
                this.sin = sin;
//            d = den * den;
//            cos = d - sin;
                cos = Math.sqrt(1 - sin * sin);
            }

            public Angle(double cos, double sin) {
//            long g = gcd(cos, sin);
//            cos /= g;
//            sin /= g;
//            d /= g;
                this.cos = cos;
                this.sin = sin;
//            this.d = d;
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
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
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
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

        public int readInt() {
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

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class Scheduler {
        private final AtomicInteger testsRemaining;
        private final AtomicInteger threadsRemaining;

        public Scheduler(InputReader in, OutputWriter out, TaskFactory factory, int numParallel) {
            try {
                testsRemaining = new AtomicInteger(in.readInt());
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

