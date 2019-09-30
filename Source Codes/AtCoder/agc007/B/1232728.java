import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.stream.Stream;

public class Main {

    static void solve(FastScanner sc, PrintWriter out) {
        int N = sc.ni();
        int[] p = IntStream.of(sc.nia(N)).map(d -> d - 1).toArray();
        long[] a = LongStream.range(1, N + 1).toArray();
        long[] b = reverse(a);
        long sum = a[p[0]] + b[p[0]] + 1;
        for (int i = 1; i < N; i++, sum++) {
            long diff = sum - (a[p[i]] + b[p[i]]);
            if (diff == 0) continue;
            b[p[i]] += diff;
            if (diff < 0) {
                for (int j = p[i] + 1; j < N; j++) {
                    a[j] -= diff;
                    b[j] += diff;
                }
            } else {
                for (int j = p[i] - 1; j >= 0; j--) {
                    a[j] -= diff;
                    b[j] += diff;
                }
            }
        }
        long minA = LongStream.of(a).min().getAsLong();
        if (minA < 1) {
            long offset = 1 - minA;
            a = Arrays.stream(a).map(i -> i + offset).toArray();
        }
        long minB = LongStream.of(b).min().getAsLong();
        if (minB < 1) {
            long offset = 1 - minB;
            b = Arrays.stream(b).map(i -> i + offset).toArray();
        }
        out.println(join(" ", a));
        out.println(join(" ", b));
    }

    static long[] reverse(long[] array) {
        int len = array.length;
        long[] ret = new long[len];
        for (int i = 0; i < len; i++) {
            ret[i] = array[len - 1 - i];
        }
        return ret;
    }

    static String join(String delimiter, long[] array) {
        return Arrays.stream(array).mapToObj(String::valueOf).collect(Collectors.joining(delimiter));
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