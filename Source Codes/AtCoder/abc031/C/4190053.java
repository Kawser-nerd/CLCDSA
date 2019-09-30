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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] sum = new int[n + 2];
            for (int i = 0; i < n; i++)
                sum[i + 2] = sum[i] + in.nextInt();
            int ans = Integer.MIN_VALUE;
            for (int i = 2; i < n + 2; i++) {
                int max = Integer.MIN_VALUE;
                int a = 0;
                for (int j = 2; j < n + 2; j++) {
                    if (i == j)
                        continue;
                    int l = Math.min(i, j);
                    int r = Math.max(i, j);
                    int cn = ((r - l) & 1) == 0 ? sum[r - 1] : sum[r];
                    cn -= sum[l - 1];
                    if (cn > max) {
                        max = cn;
                        a = j;
                    }
                }
                int l = Math.min(i, a);
                int r = Math.max(i, a);
                int cn = ((r - l) & 1) == 0 ? sum[r] : sum[r - 1];
                cn -= sum[l - 2];
                ans = Math.max(cn, ans);
            }
            out.println(ans);
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