import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            final String n = in.next();

            int digit = n.length();

            long[][][] memo = new long[digit + 1][2][digit + 1];

            memo[0][0][0] = 1;
            for (int d = 0; d < digit; d++) {
                for (int l = 0; l < 2; l++) {
                    for (int o = 0; o < digit; o++) {
                        char lim = l == 1 ? '9' : n.charAt(d);
                        for (char i = '0'; i <= lim; i++) {
                            int less = (l == 1 || i < n.charAt(d)) ? 1 : 0;
                            int one = o + ((i == '1') ? 1 : 0);
                            memo[d + 1][less][one] += memo[d][l][o];
                        }
                    }
                }
            }

            long ans = 0;
            for (int l = 0; l < 2; l++)
                for (int o = 1; o <= digit; o++)
                    ans += o * memo[digit][l][o];
            out.println(ans);
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer;
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
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
            return hasNextByte() ? buffer[bufPointer++] : -1;
        }

        private static boolean isPrintableChar(int c) {
            return (c >= 33 && c <= 126);
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[bufPointer]))
                bufPointer++;
            return hasNextByte();
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
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