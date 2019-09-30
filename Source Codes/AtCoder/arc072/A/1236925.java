import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {

    static void solve(FastScanner sc, PrintWriter out) {
        int N = sc.ni();
        int[] a = sc.nia(N);
        long[][] p = new long[2][N + 1];
        long[][] n = new long[2][N + 1];
        for (int i = 1; i <= N; i++) {
            if (p[1][i - 1] + a[i - 1] < 0) {
                n[0][i] = p[0][i - 1];
                n[1][i] = p[1][i - 1] + a[i - 1];
            } else {
                n[0][i] = p[0][i - 1] + 1 + p[1][i - 1] + a[i - 1];
                n[1][i] = -1;
            }
            if (n[1][i - 1] + a[i - 1] > 0) {
                p[0][i] = n[0][i - 1];
                p[1][i] = n[1][i - 1] + a[i - 1];
            } else {
                p[0][i] = n[0][i - 1] + 1 - n[1][i - 1] - a[i - 1];
                p[1][i] = 1;
            }
        }
        out.println(Math.min(p[0][N], n[0][N]));
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        solve(sc, out);
        out.flush();
    }

    static class FastScanner {
        private final InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0, ptrbuf = 0;

        FastScanner(InputStream is) {
            this.is = is;
        }

        char nc() {
            return (char) skip();
        }

        char[] nca(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(isSpaceChar(b))) {
                buf[p++] = (char) b;
                b = readByte();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        char[][] nca2(int n, int m) {
            char[][] buf = new char[m][n];
            for (int i = 0; i < m; i++) {
                buf[i] = nca(n);
            }
            return buf;
        }

        String ns() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        int ni() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        int[] nia(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = ni();
            return a;
        }

        long nl() {
            long num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        double nd() {
            return Double.parseDouble(ns());
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }
    }

}