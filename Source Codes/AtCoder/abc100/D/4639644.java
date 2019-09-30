import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        InputStreamScanner in = new InputStreamScanner(System.in);
        new Main().solve(in, out);
        out.flush();
    }

    private void solve(InputStreamScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        long[][] a = new long[3][n];
        for (int i = 0; i < n; i++) {
            a[0][i] = in.nextLong();
            a[1][i] = in.nextLong();
            a[2][i] = in.nextLong();
        }

        long[][] t = new long[1 << 3][n];
        for (int f = 0; f < n; f++) {

            for (int i = 0; i < 1 << 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if ((1 & i >> j) == 1) {
                        t[i][f] += a[j][f];
                    } else {
                        t[i][f] -= a[j][f];
                    }
                }
            }
        }

        for (int i = 0; i < 1 << 3; i++) {
            Arrays.sort(t[i]);
        }

        long r = 0;
        for (int i = 0; i < 1 << 3; i++) {
            long s = 0;
            for (int j = n - 1; j >= n - m; j--) {
                s += t[i][j];
            }
            r = Math.max(r, s);
        }

        out.println(r);
    }

    static class InputStreamScanner {

        private InputStream in;

        private byte[] buf = new byte[1024];
        private int len = 0;
        private int off = 0;

        InputStreamScanner(InputStream in)	{
            this.in = in;
        }

        String next() {
            StringBuilder sb = new StringBuilder();
            for (int b = skip(); !isSpace(b);){
                sb.appendCodePoint(b);
                b = read();
            }
            return sb.toString();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        char nextChar() {
            return (char)skip();
        }

        int skip() {
            for (int b; (b = read()) != -1;) {
                if (!isSpace(b)) {
                    return b;
                }
            }
            return -1;
        }

        private boolean isSpace(int c) {
            return c < 33 || c > 126;
        }

        private int read() {
            if (len == -1) {
                throw new InputMismatchException("End of Input");
            }
            if (off >= len){
                off = 0;
                try {
                    len = in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException(e.getMessage());
                }
                if (len <= 0) {
                    return -1;
                }
            }
            return buf[off++];
        }
    }
}