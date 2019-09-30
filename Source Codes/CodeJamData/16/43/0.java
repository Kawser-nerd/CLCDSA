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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                int r;
                int c;
                int[] p;


                public void read(InputReader in) {
                    r = in.readInt();
                    c = in.readInt();
                    p = IOUtils.readIntArray(in, 2 * (r + c));
                }

                char[][] answer;


                public void solve() {
                    MiscUtils.decreaseByOne(p);
                    int[] id = new int[2 * (r + c)];
                    for (int i = 0; i < r + c; i++) {
                        id[p[2 * i]] = id[p[2 * i + 1]] = i;
                    }
                    answer = new char[r][c];
                    int[] stack = new int[2 * (r + c)];
                    int at = 0;
                    for (int i = 0; i < 2 * (r + c); i++) {
                        int current = id[i];
                        if (at > 0 && stack[at - 1] == current) {
                            at--;
                            int row;
                            int column;
                            TaskC.Direction direction;
                            if (i < c) {
                                row = 0;
                                column = i;
                                direction = TaskC.Direction.DOWN;
                            } else if (i < r + c) {
                                row = i - c;
                                column = c - 1;
                                direction = TaskC.Direction.LEFT;
                            } else if (i < r + 2 * c) {
                                row = r - 1;
                                column = c - 1 - (i - r - c);
                                direction = TaskC.Direction.UP;
                            } else {
                                row = 2 * r + 2 * c - 1 - i;
                                column = 0;
                                direction = TaskC.Direction.RIGHT;
                            }
                            while (true) {
                                if (row < 0 || row >= r || column < 0 || column >= c) {
                                    int j;
                                    if (row == -1) {
                                        j = column;
                                    } else if (column == c) {
                                        j = c + row;
                                    } else if (row == r) {
                                        j = r + c + (c - 1 - column);
                                    } else {
                                        j = 2 * r + 2 * c - 1 - row;
                                    }
                                    if (id[j] == id[i]) {
                                        break;
                                    } else {
                                        answer = null;
                                        return;
                                    }
                                }
                                if (answer[row][column] == 0) {
                                    if (direction == TaskC.Direction.UP || direction == TaskC.Direction.DOWN) {
                                        answer[row][column] = '/';
                                    } else {
                                        answer[row][column] = '\\';
                                    }
                                }
                                if (answer[row][column] == '/') {
                                    if (direction == TaskC.Direction.UP) {
                                        column++;
                                        direction = TaskC.Direction.RIGHT;
                                    } else if (direction == TaskC.Direction.DOWN) {
                                        column--;
                                        direction = TaskC.Direction.LEFT;
                                    } else if (direction == TaskC.Direction.LEFT) {
                                        row++;
                                        direction = TaskC.Direction.DOWN;
                                    } else {
                                        row--;
                                        direction = TaskC.Direction.UP;
                                    }
                                } else {
                                    if (direction == TaskC.Direction.UP) {
                                        column--;
                                        direction = TaskC.Direction.LEFT;
                                    } else if (direction == TaskC.Direction.DOWN) {
                                        column++;
                                        direction = TaskC.Direction.RIGHT;
                                    } else if (direction == TaskC.Direction.LEFT) {
                                        row--;
                                        direction = TaskC.Direction.UP;
                                    } else {
                                        row++;
                                        direction = TaskC.Direction.DOWN;
                                    }
                                }
                            }
                        } else {
                            stack[at++] = current;
                        }
                    }
                    if (at != 0) {
                        answer = null;
                        return;
                    }
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            if (answer[i][j] == 0) {
                                answer[i][j] = '/';
                            }
                        }
                    }
                }


                public void write(OutputWriter out, int testNumber) {
                    out.printLine("Case #" + testNumber + ":");
                    if (answer == null) {
                        out.printLine("IMPOSSIBLE");
                    } else {
                        for (char[] row : answer) {
                            out.printLine(row);
                        }
                    }
                }
            }, 4);
        }

        enum Direction {
            LEFT,
            RIGHT,
            UP,
            DOWN,;
        }

    }

    static class IOUtils {
        public static int[] readIntArray(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readInt();
            }
            return array;
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

        public void printLine(char[] array) {
            writer.println(array);
        }

        public void close() {
            writer.close();
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

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }

    }
}

