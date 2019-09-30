import java.io.*;
import java.util.Arrays;

public class B {

    final static boolean DEBUG = true;

    final void solve() throws Exception {
        for (int testCount = nextInt(), testId = 1; testCount > 0; --testCount, ++testId) {

            int n = nextInt();
            int m = nextInt();

            final int size = 24 * 60;
            final int maxSingle = 12 * 60;
            int[] type = new int[size];
            Arrays.fill(type, -1);

            for (int i = 0; i < n; ++i) {
                int a = nextInt();
                int b = nextInt();
                for (int j = a; j < b; ++j) {
                    type[j] = 0;
                }
            }

            for (int i = 0; i < m; ++i) {
                int a = nextInt();
                int b = nextInt();
                for (int j = a; j < b; ++j) {
                    type[j] = 1;
                }
            }

            int result = -1;

            int[][][] c;
            c = new int[2][size + 1][maxSingle + 1];
            c[0][0][0] = 1;

            for (int time = 0; time < size; ++time) {
                for (int currentType = 0; currentType < 2; ++currentType) {
                    for (int spentTime = 0; spentTime <= maxSingle; ++spentTime) {

                        if (c[currentType][time][spentTime] == 0) {
                            continue;
                        }

                        if (type[time] != currentType || type[time] == -1) {
                            if (spentTime + 1 <= maxSingle) {
                                if (c[currentType][time + 1][spentTime + 1] == 0 ||
                                        c[currentType][time + 1][spentTime + 1] > c[currentType][time][spentTime]) {
                                    c[currentType][time + 1][spentTime + 1] = c[currentType][time][spentTime];
                                }
                            }
                        }

                        if (type[time] == -1 || type[time] == currentType) {
                            final int otherSpentTime = time - spentTime;
                            if (otherSpentTime + 1 <= maxSingle) {
                                if (c[1 - currentType][time + 1][otherSpentTime + 1] == 0 ||
                                        c[1 - currentType][time + 1][otherSpentTime + 1] > c[currentType][time][spentTime] + 1) {
                                    c[1 - currentType][time + 1][otherSpentTime + 1] = c[currentType][time][spentTime] + 1;
                                }
                            }
                        }
                    }
                }
            }

            if (c[0][size][maxSingle] != 0) {
                if (result == -1 || c[0][size][maxSingle] - 1 < result) {
                    result = c[0][size][maxSingle] - 1;
                }
            }

            if (c[1][size][maxSingle] != 0) {
                if (result == -1 || c[1][size][maxSingle] < result) {
                    result = c[1][size][maxSingle];
                }
            }

            c = new int[2][size + 1][size + 1];
            c[1][0][0] = 1;

            for (int time = 0; time < size; ++time) {
                for (int currentType = 0; currentType < 2; ++currentType) {
                    for (int spentTime = 0; spentTime <= maxSingle; ++spentTime) {

                        if (c[currentType][time][spentTime] == 0) {
                            continue;
                        }

                        if (type[time] != currentType || type[time] == -1) {
                            if (spentTime + 1 <= maxSingle) {
                                if (c[currentType][time + 1][spentTime + 1] == 0 ||
                                        c[currentType][time + 1][spentTime + 1] > c[currentType][time][spentTime]) {
                                    c[currentType][time + 1][spentTime + 1] = c[currentType][time][spentTime];
                                }
                            }
                        }

                        if (type[time] == -1 || type[time] == currentType) {
                            final int otherSpentTime = time - spentTime;
                            if (otherSpentTime + 1 <= maxSingle) {
                                if (c[1 - currentType][time + 1][otherSpentTime + 1] == 0 ||
                                        c[1 - currentType][time + 1][otherSpentTime + 1] > c[currentType][time][spentTime] + 1) {
                                    c[1 - currentType][time + 1][otherSpentTime + 1] = c[currentType][time][spentTime] + 1;
                                }
                            }
                        }
                    }
                }
            }


            if (c[1][size][maxSingle] != 0) {
                if (result == -1 || c[1][size][maxSingle] - 1 < result) {
                    result = c[1][size][maxSingle] - 1;
                }
            }

            if (c[0][size][maxSingle] != 0) {
                if (result == -1 || c[0][size][maxSingle] < result) {
                    result = c[0][size][maxSingle];
                }
            }

            print(String.format("Case #%d: %d", testId, result));
            println();
        }
    }

    final static BufferedReader in;
    final static PrintWriter out;

    static final boolean isWhiteSpace(final int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == -1;
    }

    static final int read() throws Exception {
        return in.read();
    }

    static final int nextInt() throws Exception {
        int result = 0;
        boolean negative = false;
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c == '-') {
            negative = true;
            c = read();
        }
        while (!isWhiteSpace(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        return negative ? -result : result;
    }

    static final long nextLong() throws Exception {
        long result = 0;
        boolean negative = false;
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c == '-') {
            negative = true;
            c = read();
        }
        while (!isWhiteSpace(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        return negative ? -result : result;
    }

    static final StringBuilder tmpString = new StringBuilder(1 << 20);

    static final String nextString() throws Exception {
        tmpString.setLength(0);
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            tmpString.append((char) c);
            c = read();
        }
        return tmpString.toString();
    }

    static final void print(final int i) {
        out.print(i);
    }

    static final void print(final long l) {
        out.print(l);
    }

    static final void print(final String s) {
        out.print(s);
    }

    static final void println() {
        out.println();
    }

    static {
        try {
            if (DEBUG) {
                String fileName = B.class.getSimpleName();
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
            }
        } catch (Exception ex) {
            throw new RuntimeException(ex);
        }
    }

    public static void main(String[] args) throws Exception {
        new B().solve();
        out.close();
    }
}
