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
            final String regex = "B-(small|large).*[.]in";
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
                char[] coders;
                char[] jammers;


                public void read(InputReader in) {
                    coders = in.readString().toCharArray();
                    jammers = in.readString().toCharArray();
                }

                long difference;
                long codersScore;
                long jammersScore;

                String first;
                String second;


                public void solve() {
                    difference = Long.MAX_VALUE;
                    for (int i = 0; i <= coders.length; i++) {
                        if (i == coders.length) {
                            update(getScoreMax(coders, coders.length), getScoreMax(jammers, jammers.length));
                            break;
                        }
                        if (coders[i] == '?') {
                            if (jammers[i] == '?') {
                                coders[i] = '1';
                                jammers[i] = '0';
                                update(getScoreMin(coders, i + 1), getScoreMax(jammers, i + 1));
                                coders[i] = '0';
                                jammers[i] = '1';
                                update(getScoreMax(coders, i + 1), getScoreMin(jammers, i + 1));
                                jammers[i] = '0';
                            } else {
                                if (jammers[i] != '0') {
                                    coders[i] = (char) (jammers[i] - 1);
                                    update(getScoreMax(coders, i + 1), getScoreMin(jammers, i + 1));
                                }
                                if (jammers[i] != '9') {
                                    coders[i] = (char) (jammers[i] + 1);
                                    update(getScoreMin(coders, i + 1), getScoreMax(jammers, i + 1));
                                }
                                coders[i] = jammers[i];
                            }
                        } else {
                            if (jammers[i] == '?') {
                                if (coders[i] != '0') {
                                    jammers[i] = (char) (coders[i] - 1);
                                    update(getScoreMin(coders, i + 1), getScoreMax(jammers, i + 1));
                                }
                                if (coders[i] != '9') {
                                    jammers[i] = (char) (coders[i] + 1);
                                    update(getScoreMax(coders, i + 1), getScoreMin(jammers, i + 1));
                                }
                                jammers[i] = coders[i];
                            } else {
                                if (coders[i] != jammers[i]) {
                                    if (coders[i] > jammers[i]) {
                                        update(getScoreMin(coders, i + 1), getScoreMax(jammers, i + 1));
                                    } else {
                                        update(getScoreMax(coders, i + 1), getScoreMin(jammers, i + 1));
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    first = Long.toString(codersScore);
                    while (first.length() != coders.length) {
                        first = '0' + first;
                    }
                    second = Long.toString(jammersScore);
                    while (second.length() != jammers.length) {
                        second = '0' + second;
                    }
                }

                private void update(long cScore, long jScore) {
                    long dif = Math.abs(cScore - jScore);
                    if (dif < difference ||
                            dif == difference && (cScore < codersScore || cScore == codersScore && jScore
                                    < jammersScore)) {
                        difference = dif;
                        codersScore = cScore;
                        jammersScore = jScore;
                    }
                }

                private long getScoreMax(char[] number, int length) {
                    long result = 0;
                    if (length != 0) {
                        result = Long.parseLong(new String(number, 0, length));
                    }
                    for (int i = length; i < number.length; i++) {
                        result *= 10;
                        if (number[i] == '?') {
                            result += 9;
                        } else {
                            result += number[i] - '0';
                        }
                    }
                    return result;
                }

                private long getScoreMin(char[] number, int length) {
                    long result = 0;
                    if (length != 0) {
                        result = Long.parseLong(new String(number, 0, length));
                    }
                    for (int i = length; i < number.length; i++) {
                        result *= 10;
                        if (number[i] != '?') {
                            result += number[i] - '0';
                        }
                    }
                    return result;
                }


                public void write(OutputWriter out, int testNumber) {
                    out.printLine("Case #" + testNumber + ":", first, second);
                }
            }, 4);
        }

    }

    static interface TaskFactory {
        public Task newTask();

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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

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

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
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
}

