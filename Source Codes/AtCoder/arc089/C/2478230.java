import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int a = in.nextInt();
        int b = in.nextInt();
        int[][] d = new int[a][b];
        for (int i = 0; i < a ; i++) {
            for (int j = 0; j < b ; j++) {
                d[i][j] = in.nextInt();
            }
        }

        List<int[]> edges = solve(d);

        if (edges == null) {
            out.println("Impossible");
        } else {
            out.println("Possible");
            out.println(String.format("%d %d", 202, edges.size()));
            for (int[] e : edges) {
                out.print(String.format("%d %d ", e[0]+1, e[1]+1));
                if (e[2] == -1) {
                    out.println('X');
                } else if (e[2] == -2) {
                    out.println('Y');
                } else {
                    out.println(e[2]);
                }
            }
            out.println("201 202");
        }
        out.flush();
    }

    private static List<int[]> solve(int[][] d) {
        int a = d.length;
        int b = d[0].length;


        int[][] table = new int[101][101];
        for (int i = 0; i < table.length ; i++) {
            Arrays.fill(table[i], -1);
        }

        for (int i = 0 ; i < a ; i++) {
            for (int j = 0; j < b ; j++) {
                int x = i+1;
                int y = j+1;
                for (int useX = 0 ; useX <= 100 ; useX++) {
                    for (int useY = 0 ; useY <= 100 ; useY++) {
                        int leftCost = d[i][j] - x * useX - y * useY;
                        if (leftCost >= 0) {
                            table[useX][useY] = Math.max(table[useX][useY], leftCost);
                        }
                    }
                }
            }
        }

        if (!verify(d, table)) {
            return null;
        }

        List<int[]> e = new ArrayList<>();
        int S = 200;
        int T = 201;
        for (int i = 0 ; i < 100; i++) {
            e.add(new int[]{ i == 0 ? S : i-1, i, -1});
        }
        for (int i = 100 ; i < 200 ; i++) {
            e.add(new int[]{ i, i == 100 ? T : i-1, -2});
        }
        for (int i = 0; i < table.length ; i++) {
            for (int j = 0; j < table[0].length ; j++) {
                if (table[i][j] != -1) {
                    int fi = i == 0 ? S : i-1;
                    int ti = j == 0 ? T : 100+j-1;
                    e.add(new int[]{ fi, ti, table[i][j] });
                }
            }
        }
        return e;
    }

    private static boolean verify(int[][] d, int[][] table) {
        for (int i = 0 ; i < d.length ; i++) {
            for (int j = 0; j < d[0].length ; j++) {
                int x = i+1;
                int y = j+1;

                int cost = 101;
                for (int useX = 0 ; useX <= 100 ; useX++) {
                    for (int useY = 0 ; useY <= 100 ; useY++) {
                        if (table[useX][useY] == -1) {
                            continue;
                        }
                        cost = Math.min(cost, table[useX][useY] + x * useX + y * useY);
                    }
                }
                if (cost != d[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
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
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}