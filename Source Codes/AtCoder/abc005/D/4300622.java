import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();

            int[][] sum = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    sum[i][j] = in.nextInt() + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

            int[] takoNumToScore = new int[n * n + 1];
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                    for (int i = 0; i < x; i++) {
                        for (int j = 0; j < y; j++) {
                            int cs = sum[x][y] - sum[i][y] - sum[x][j] + sum[i][j];
                            int takoNum = (x - i) * (y - j);
                            takoNumToScore[takoNum] = Math.max(takoNumToScore[takoNum], cs);
                        }
                    }
                }
            }

            for (int i = 1; i <= n * n; i++)
                takoNumToScore[i] = Math.max(takoNumToScore[i - 1], takoNumToScore[i]);

            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                int p = in.nextInt();
                out.println(takoNumToScore[p]);
            }
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
            this.bufPointer = 0;
            this.bufLength = 0;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int nextInt() {
            int n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

    }
}