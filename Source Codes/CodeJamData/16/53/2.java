import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.util.AbstractCollection;
import java.util.concurrent.atomic.AtomicInteger;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.Writer;
import java.util.Queue;
import java.util.ArrayDeque;
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                int n;
                int s;
                int[] x;
                int[] y;
                int[] z;
                int[] vx;
                int[] vy;
                int[] vz;


                public void read(InputReader in) {
                    n = in.readInt();
                    s = in.readInt();
                    x = new int[n];
                    y = new int[n];
                    z = new int[n];
                    vx = new int[n];
                    vy = new int[n];
                    vz = new int[n];
                    IOUtils.readIntArrays(in, x, y, z, vx, vy, vz);
                }

                double answer;


                public void solve() {
                    double[][] baseDist = new double[n][n];
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            baseDist[i][j] = Math.hypot(x[i] - x[j], Math.hypot(y[i] - y[j], z[i] - z[j]));
                        }
                    }
                    double left = 0;
                    double right = 2000;
                    double[] lastConnect = new double[n];
                    int[] connected = new int[(n + 31) >> 5];
                    int[][] edges = new int[n][(n + 31) >> 5];
                    int[] degree = new int[n];
                    for (int i = 0; i < 30; i++) {
                        double middle = (left + right) / 2;
                        PriorityQueue<TaskC.Event> events = new PriorityQueue<>();
                        for (int j = 0; j < n; j++) {
                            for (int k = 0; k < j; k++) {
                                int dx = vx[j] - vx[k];
                                int dy = vy[j] - vy[k];
                                int dz = vz[j] - vz[k];
                                if (dx == 0 && dy == 0 && dz == 0) {
                                    if (baseDist[j][k] <= middle) {
                                        events.add(new TaskC.Event(TaskC.EventType.CONNECT, 0, j, k));
                                    }
                                } else {
                                    int xx = x[j] - x[k];
                                    int yy = y[j] - y[k];
                                    int zz = z[j] - z[k];
                                    double a = dx * dx + dy * dy + dz * dz;
                                    double b = 2 * (xx * dx + yy * dy + zz * dz);
                                    double c = xx * xx + yy * yy + zz * zz - middle * middle;
                                    double d = b * b - 4 * a * c;
                                    if (d > 0) {
                                        double t1 = (-b - Math.sqrt(d)) / (2 * a);
                                        double t2 = (-b + Math.sqrt(d)) / (2 * a);
                                        if (t2 > 0) {
                                            events.add(new TaskC.Event(TaskC.EventType.CONNECT, Math.max(t1, 0), j, k));
                                            events.add(new TaskC.Event(TaskC.EventType.DISCONNECT, t2, j, k));
                                        }
                                    }
                                }
                            }
                        }
                        events.add(new TaskC.Event(TaskC.EventType.KILL, s, 0, 0));
                        Arrays.fill(connected, 0);
                        connected[0] = 1;
                        ArrayUtils.fill(edges, 0);
                        Arrays.fill(degree, 0);
                        boolean good = false;
                        Queue<Integer> toAdd = new ArrayDeque<>();
                        lastConnect[0] = s;
                        while (!events.isEmpty()) {
                            if ((connected[0] & 2) == 2) {
                                good = true;
                                break;
                            }
                            TaskC.Event event = events.poll();
                            if (event.type == TaskC.EventType.CONNECT) {
                                degree[event.first]++;
                                degree[event.second]++;
                                edges[event.first][event.second >> 5] += 1 << (event.second & 31);
                                edges[event.second][event.first >> 5] += 1 << (event.first & 31);
                                if ((connected[event.first >> 5] >> (event.first & 31) & 1) == 1 &&
                                        (connected[event.second >> 5] >> (event.second & 31) & 1) == 0) {
                                    toAdd.add(event.second);
                                } else if ((connected[event.first >> 5] >> (event.first & 31) & 1) == 0 &&
                                        (connected[event.second >> 5] >> (event.second & 31) & 1) == 1) {
                                    toAdd.add(event.first);
                                }
                            } else if (event.type == TaskC.EventType.DISCONNECT) {
                                degree[event.first]--;
                                degree[event.second]--;
                                edges[event.first][event.second >> 5] -= 1 << (event.second & 31);
                                edges[event.second][event.first >> 5] -= 1 << (event.first & 31);
                                if ((connected[event.first >> 5] >> (event.first & 31) & 1) == 1 &&
                                        degree[event.first] ==
                                                0) {
                                    lastConnect[event.first] = s + event.time;
                                    events.add(new TaskC.Event(TaskC.EventType.KILL, s + event.time, event.first,
                                            event.first));
                                }
                                if ((connected[event.second >> 5] >> (event.second & 31) & 1) == 1 &&
                                        degree[event.second]
                                                == 0) {
                                    lastConnect[event.second] = s + event.time;
                                    events.add(new TaskC.Event(TaskC.EventType.KILL, s + event.time, event.second,
                                            event.second));
                                }
                            } else {
                                if (degree[event.first] == 0 && event.time == lastConnect[event.first]) {
                                    connected[event.first >> 5] &= ~(1 << (event.first & 31));
                                }
                            }
                            while (!toAdd.isEmpty()) {
                                int current = toAdd.poll();
                                connected[current >> 5] |= 1 << (current & 31);
                                for (int j = 0; j < edges[current].length; j++) {
                                    if (edges[current][j] != (edges[current][j] & connected[j])) {
                                        for (int k = 0; k < 32; k++) {
                                            if ((edges[current][j] >> k & 1) == 1 && (connected[j] >> k & 1) == 0) {
                                                toAdd.add(j * 32 + k);
                                                connected[j] |= 1 << k;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (good) {
                            right = middle;
                        } else {
                            left = middle;
                        }
                    }
                    answer = (left + right) / 2;
                }


                public void write(OutputWriter out, int testNumber) {
                    out.printLine("Case #" + testNumber + ":", answer);
                }
            }, 4);
        }

        static enum EventType {
            CONNECT,
            DISCONNECT,
            KILL,;
        }

        static class Event implements Comparable<TaskC.Event> {
            TaskC.EventType type;
            double time;
            int first;
            int second;

            public Event(TaskC.EventType type, double time, int first, int second) {
                this.type = type;
                this.time = time;
                this.first = first;
                this.second = second;
            }


            public int compareTo(TaskC.Event o) {
                return Double.compare(time, o.time);
            }

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

    static class ArrayUtils {
        public static void fill(int[][] array, int value) {
            for (int[] row : array) {
                Arrays.fill(row, value);
            }
        }

    }

    static interface TaskFactory {
        public Task newTask();

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

    static interface Task {
        public void read(InputReader in);

        public void solve();

        public void write(OutputWriter out, int testNumber);

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

    static class IOUtils {
        public static void readIntArrays(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
        }

    }
}

