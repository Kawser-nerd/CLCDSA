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
 *
 * @author Egor Kulikov (egor@egork.net)
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
                int r;
                int c;
                int d;
                char[][] map;


                public void read(InputReader in) {
                    r = in.readInt();
                    c = in.readInt();
                    d = in.readInt();
                    map = IOUtils.readTable(in, r, c);
                }

                boolean answer;
                int sRow;
                int sCol;
                int fRow;
                int fCol;
                int[][] dst;
                int[] qRow;
                int[] qCol;
                boolean[][] processed;
                char[][] orig;
                int cDist;

                int findDistance() {
                    cDist += 2;
                    if (cDist == d) {
                        ArrayUtils.fill(dst, -1);
                        qRow[0] = sRow;
                        qCol[0] = sCol;
                        int size = 1;
                        dst[sRow][sCol] = 0;
                        for (int i = 0; i < size; i++) {
                            int row = qRow[i];
                            int col = qCol[i];
                            for (int j = 0; j < 4; j++) {
                                int nRow = row + MiscUtils.DX4[j];
                                int nCol = col + MiscUtils.DY4[j];
                                if (MiscUtils.isValidCell(nRow, nCol, r, c) && map[nRow][nCol] == '.' &&
                                        dst[nRow][nCol] == -1) {
                                    dst[nRow][nCol] = dst[row][col] + 1;
                                    qRow[size] = nRow;
                                    qCol[size++] = nCol;
                                }
                            }
                        }
                        cDist = dst[fRow][fCol];
                    }
                    return cDist;
                }

                int findDistance2() {
                    ArrayUtils.fill(dst, -1);
                    qRow[0] = sRow;
                    qCol[0] = sCol;
                    int size = 1;
                    dst[sRow][sCol] = 0;
                    for (int i = 0; i < size; i++) {
                        int row = qRow[i];
                        int col = qCol[i];
                        for (int j = 0; j < 4; j++) {
                            int nRow = row + MiscUtils.DX4[j];
                            int nCol = col + MiscUtils.DY4[j];
                            if (MiscUtils.isValidCell(nRow, nCol, r, c) && map[nRow][nCol] == '.' &&
                                    dst[nRow][nCol] == -1) {
                                dst[nRow][nCol] = dst[row][col] + 1;
                                qRow[size] = nRow;
                                qCol[size++] = nCol;
                            }
                        }
                    }
                    return dst[fRow][fCol];
                }

                void tryAdd(int row, int col) {
                    map[row][col] = '#';
                    processed[row][col] = true;
                    cDist = findDistance();
                    if (cDist == d) {
                        return;
                    }
                    for (int i = 0; i < 4; i++) {
                        int nRow = row + MiscUtils.DX4[i];
                        int nCol = col + MiscUtils.DY4[i];
                        if (!processed[nRow][nCol] && orig[nRow][nCol] == '#') {
                            tryAdd(nRow, nCol);
                            if (cDist == d) {
                                return;
                            }
                        }
                    }
                }


                public void solve() {
                    orig = new char[r][c];
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            orig[i][j] = map[i][j];
                        }
                    }
                    sRow = -1;
                    sCol = -1;
                    fRow = -1;
                    fCol = -1;
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            if (map[i][j] == 'S') {
                                map[i][j] = '.';
                                sRow = i;
                                sCol = j;
                            }
                            if (map[i][j] == 'F') {
                                map[i][j] = '.';
                                fRow = i;
                                fCol = j;
                            }
                        }
                    }
                    dst = new int[r][c];
                    qRow = new int[r * c];
                    qCol = new int[r * c];
                    int o = findDistance2();
                    if (d > o || (o - d) % 2 != 0) {
                        return;
                    }
                    for (int i = 1; i < r - 1; i++) {
                        for (int j = 1; j < c - 1; j++) {
                            map[i][j] = '.';
                        }
                    }
                    cDist = findDistance2();
                    if (cDist > d) {
                        return;
                    }
                    processed = new boolean[r][c];
                    for (int i = 0; i < r; i++) {
                        processed[i][0] = processed[i][c - 1] = true;
                    }
                    for (int i = 0; i < c; i++) {
                        processed[0][i] = processed[r - 1][i] = true;
                    }
                    for (int i = 1; i < r - 1 && cDist != d; i++) {
                        if (!processed[i][1] && orig[i][1] == '#') {
                            tryAdd(i, 1);
                        }
                        if (cDist != d && !processed[i][c - 2] && orig[i][c - 2] == '#') {
                            tryAdd(i, c - 2);
                        }
                    }
                    for (int i = 1; i < c - 1 && cDist != d; i++) {
                        if (!processed[1][i] && orig[1][i] == '#') {
                            tryAdd(1, i);
                        }
                        if (cDist != d && !processed[r - 2][i] && orig[r - 2][i] == '#') {
                            tryAdd(r - 2, i);
                        }
                    }
                    for (int i = 2; cDist != d && i < r - 2; i++) {
                        for (int j = 2; cDist != d && j < c - 2; j++) {
                            if (!processed[i][j] && orig[i][j] == '#') {
                                tryAdd(i, j);
                            }
                        }
                    }
                    answer = true;
                    map[sRow][sCol] = 'S';
                    map[fRow][fCol] = 'F';
                }


                public void write(OutputWriter out, int testNumber) {
                    out.printLine("Case #" + testNumber + ":", answer ? "POSSIBLE" : "IMPOSSIBLE");
                    if (answer) {
                        for (char[] row : map) {
                            out.printLine(row);
                        }
                    }
                }
            }, 8);
        }

    }

    static class MiscUtils {
        public static final int[] DX4 = {1, 0, -1, 0};
        public static final int[] DY4 = {0, -1, 0, 1};

        public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
            return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
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

        public void printLine(char[] array) {
            writer.println(array);
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

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class IOUtils {
        public static char[] readCharArray(InputReader in, int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readCharacter();
            }
            return array;
        }

        public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readCharArray(in, columnCount);
            }
            return table;
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

    static class ArrayUtils {
        public static void fill(int[][] array, int value) {
            for (int[] row : array) {
                Arrays.fill(row, value);
            }
        }

    }
}

