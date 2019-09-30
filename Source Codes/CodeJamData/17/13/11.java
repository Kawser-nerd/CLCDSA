import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Random;
import java.util.InputMismatchException;
import java.io.IOException;
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
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        private static final int INF = 1000 * 1000 * 1000;
        private static int[] d = new int[101 * 101 * 101 * 101];
        private static int[] q = new int[101 * 101 * 101 * 101];
        private static int head;
        private static int tail;

        private int makeState(int myHp, int enemyHp, int myDmg, int enemyDmg) {
            return myHp + 101 * enemyHp + 101 * 101 * myDmg + 101 * 101 * 101 * enemyDmg;
        }

        private TaskC.State parseState(int x) {
            int myHp = x % 101;
            x /= 101;
            int enemyHp = x % 101;
            x /= 101;
            int myDmg = x % 101;
            x /= 101;
            int enemyDmg = x % 101;
            x /= 101;
            if (x != 0) {
                throw new AssertionError();
            }
            return new TaskC.State(myHp, enemyHp, myDmg, enemyDmg);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            out.printFormat("Case #%d: ", testNumber);
            final int myHp = in.readInt();
            final int myDmg = in.readInt();
            final int enemyHp = in.readInt();
            final int enemyDmg = in.readInt();
            final int buff = in.readInt();
            final int debuff = in.readInt();

            {
                Random rnd = new Random(322);
                for (int it = 0; it < 1000; it++) {
                    int[] a = {
                            rnd.nextInt(100) + 1,
                            rnd.nextInt(100) + 1,
                            rnd.nextInt(100) + 1,
                            rnd.nextInt(100) + 1,
                    };
                    int stNum = makeState(a[0], a[1], a[2], a[3]);
                    TaskC.State st = parseState(stNum);
                    int[] b = {st.myHp, st.enemyHp, st.myDmg, st.enemyDmg};
                    if (!Arrays.equals(a, b)) {
                        throw new AssertionError();
                    }
                }
            }

            int startState = makeState(myHp, enemyHp, myDmg, enemyDmg);
            Arrays.fill(d, INF);
            Arrays.fill(q, -1);
            d[startState] = 0;
            head = 0;
            tail = 0;
            q[tail++] = startState;

            int winSt = -1;
            while (head < tail) {
                int curSt = q[head++];
                TaskC.State st = parseState(curSt);
//            System.err.println("Reached state " + st + " with distance " + d[curSt]);

                if (st.enemyHp == 0) {
                    winSt = curSt;
                    break;
                }
                if (st.myHp == 0) {
                    throw new AssertionError();
                }

                // cure, then he hits us
                {
                    int newMyHp = Math.max(0, myHp - st.enemyDmg);
                    if (newMyHp > 0) {
                        int newSt = makeState(newMyHp, st.enemyHp, st.myDmg, st.enemyDmg);
                        tryPushState(curSt, newSt);
                    }
                }

                // buff, then he hits us
                {
                    int newMyDmg = Math.min(100, st.myDmg + buff);
                    int newMyHp = st.myHp - st.enemyDmg;
                    if (newMyHp > 0) {
                        int newSt = makeState(newMyHp, st.enemyHp, newMyDmg, st.enemyDmg);
                        tryPushState(curSt, newSt);
                    }
                }

                // debuff, then he hits us
                {
                    int newEnemyDmg = Math.max(0, st.enemyDmg - debuff);
                    int newMyHp = st.myHp - newEnemyDmg;
                    if (newMyHp > 0) {
                        int newSt = makeState(newMyHp, st.enemyHp, st.myDmg, newEnemyDmg);
                        tryPushState(curSt, newSt);
                    }
                }

                // hit, then he hits us
                {
                    int newEnemyHp = Math.max(0, st.enemyHp - st.myDmg);
                    int newMyHp = Math.max(0, st.myHp - st.enemyDmg);
                    if (newEnemyHp == 0 || newMyHp > 0) {
                        int newSt = makeState(newMyHp, newEnemyHp, st.myDmg, st.enemyDmg);
                        tryPushState(curSt, newSt);
                    }
                }
            }

            if (winSt == -1) {
                out.printLine("IMPOSSIBLE");
            } else {
                out.printLine(d[winSt]);
            }
            System.err.println("Test " + testNumber + " processed");
            System.err.flush();
        }

        private void tryPushState(int curSt, int newSt) {
            if (d[newSt] > d[curSt] + 1) {
                d[newSt] = d[curSt] + 1;
                q[tail++] = newSt;
            }
        }

        private static class State {
            private final int myHp;
            private final int enemyHp;
            private final int myDmg;
            private final int enemyDmg;

            private State(int myHp, int enemyHp, int myDmg, int enemyDmg) {
                this.myHp = myHp;
                this.enemyHp = enemyHp;
                this.myDmg = myDmg;
                this.enemyDmg = enemyDmg;
            }


            public String toString() {
                return "State{" +
                        "myHp=" + myHp +
                        ", enemyHp=" + enemyHp +
                        ", myDmg=" + myDmg +
                        ", enemyDmg=" + enemyDmg +
                        '}';
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

        public void printFormat(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
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

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

