import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FasterScanner in = new FasterScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        long[][][][][] memo;

        public void solve(int testNumber, FasterScanner in, PrintWriter out) {
            char[] a = in.next().toCharArray();
            char[] b = in.next().toCharArray();

            int dl = b.length;

            char[] na = new char[dl];
            Arrays.fill(na, '0');
            System.arraycopy(a, 0, na, dl - a.length, a.length);
            a = na;

            memo = new long[dl + 1][2][2][2][2];   // digit more less has4 has9
            memo[0][0][0][0][0] = 1;

            for (int i = 0; i < dl; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        for (int l = 0; l < 2; l++) {
                            for (int m = 0; m < 2; m++) {
                                int start = (j == 1) ? 0 : (a[i] - '0');
                                int end = (k == 1) ? 9 : (b[i] - '0');
                                for (int n = start; n <= end; n++) {
                                    int more = (j == 1 || n > start) ? 1 : 0;
                                    int less = (k == 1 || n < end) ? 1 : 0;
                                    int has4 = (l == 1 || n == 4) ? 1 : 0;
                                    int has9 = (m == 1 || n == 9) ? 1 : 0;
                                    memo[i + 1][more][less][has4][has9] += memo[i][j][k][l][m];
                                }
                            }
                        }
                    }
                }
            }

            long ans = 0;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        for (int l = 0; l < 2; l++)
                            if ((k | l) == 1)
                                ans += memo[dl][i][j][k][l];
            out.println(ans);
        }

    }

    static class FasterScanner {
        private InputStream in;
        private byte[] buffer;
        private int bufPointer;
        private int bufLength;

        public FasterScanner(InputStream in) {
            this.in = in;
            buffer = new byte[1024];
        }

        private boolean hasNextByte() {
            if (bufPointer < bufLength) return true;
            bufPointer = 0;
            try {
                bufLength = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (bufLength > 0);
        }

        private int readByte() {
            if (hasNextByte()) return buffer[bufPointer++];
            return -1;
        }

        private static boolean isPrintableChar(int c) {
            return (c >= 33 && c <= 126);
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[bufPointer])) bufPointer++;
            return hasNextByte();
        }

        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

    }
}