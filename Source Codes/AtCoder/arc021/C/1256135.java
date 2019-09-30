// package atcoder.arc.arc021;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Created by hama_du on 2017/05/01.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        long k = in.nextInt();
        int n = in.nextInt();
        long[][] a = new long[n][2];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                a[i][j] = in.nextInt();
            }
        }

        long min = 0;
        long max = (long)(1e11);
        while (max - min > 1) {
            long med = (min + max) / 2;
            if (isOK(a, med, k)) {
                max = med;
            } else {
                min = med;
            }
        }
        debug(min,max);

        long build = 0;
        long money = 0;
        for (int i = 0; i < n ; i++) {
            money += cost(a[i][0], a[i][1], min);
            build += count(a[i][0], a[i][1], min);
        }
        money += (k-build)*max;

        out.println(money);
        out.flush();
    }

    private static boolean isOK(long[][] a, long med, long k) {
        int n = a.length;
        long sum = 0;
        for (int i = 0; i < n ; i++) {
            sum += count(a[i][0], a[i][1], med);
            if (sum >= k) {
                return true;
            }
        }
        return sum >= k;
    }

    private static long count(long a, long d, long upto) {
        if (a > upto) {
            return 0;
        }
        return (upto - a) / d + 1;
    }

    private static long cost(long a, long d, long upto) {
        long count = count(a, d, upto);
        if (count == 0) {
            return 0;
        }
        long updw = (a + (a + d * (count - 1)));
        if (updw % 2 == 0) {
            updw /= 2;
        } else {
            count /= 2;
        }
        return updw * count;
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
            return res * sgn;
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
            return res * sgn;
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