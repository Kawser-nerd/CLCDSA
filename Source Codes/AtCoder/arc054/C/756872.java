// package atcoder.arc.arc054;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * Created by hama_du on 2016/06/04.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long[][] a = new long[n][n];
        for (int i = 0; i < n ; i++) {
            char[] c = in.nextToken().toCharArray();
            for (int j = 0; j < n ; j++) {
                a[i][j] = c[j]-'0';
            }
        }
        out.println(det(a, 2) == 0 ? "Even" : "Odd");
        out.flush();
    }

    public static long det(long[][] A, long mod) {
        int n = A.length;
        long D = 1;
        for (int i = 0; i < n ; i++) {
            int pivot = i;
            for (int j = i+1; j < n ; j++) {
                if (A[j][i] >= 1) {
                    pivot = j;
                }
            }
            long[] t = A[pivot].clone();
            A[pivot] = A[i].clone();
            A[i] = t;

            D *= A[i][i];
            D %= mod;
            D = (i == pivot) ? D : (mod - D) % mod;
            if (A[i][i] == 0) {
                break;
            }
            for (int j = i+1 ; j < n ; j++) {
                for (int k = n-1 ; k >= i  ; k--) {
                    long sub = A[i][k] * A[j][i] % mod * invl(A[i][i], mod) % mod;
                    A[j][k] += mod - sub;
                    A[j][k] %= mod;
                }
            }
        }
        return D % mod;
    }

    public static long invl(long a, long mod) {
        long b = mod;
        long p = 1, q = 0;
        while (b > 0) {
            long c = a / b;
            long d;
            d = a;
            a = b;
            b = d % b;
            d = p;
            p = q;
            q = d - c * q;
        }
        return p < 0 ? p + mod : p;
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
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
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}