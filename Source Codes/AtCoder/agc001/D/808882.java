// package atcoder.agc.agc001;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

/**
 * Created by hama_du on 2016/07/16.
 */
public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();

        int[] a = new int[m];
        for (int i = 0; i < m ; i++) {
            a[i] = in.nextInt();
        }
        int odd = 0;
        for (int i = 0; i < m ; i++) {
            odd += a[i] % 2;
        }
        if (odd >= 3) {
            out.println("Impossible");
            out.flush();
            return;
        }

        List<Integer> od = new ArrayList<>();
        List<Integer> ev = new ArrayList<>();
        for (int i = 0; i < m ; i++) {
            if (a[i] % 2 == 1) {
                od.add(a[i]);
            } else {
                ev.add(a[i]);
            }
        }

        List<Integer> desireOrder = new ArrayList<>();
        if (od.size() >= 1) {
            desireOrder.add(od.get(0));
        }
        desireOrder.addAll(ev);
        if (od.size() == 2) {
            desireOrder.add(od.get(1));
        }

        if (desireOrder.size() == 1) {
            if (n == 1) {
                out.println(1);
                out.println(1);
                out.println(1);
                out.flush();
                return;
            } else {
                out.println(n);
                out.println(2);
                out.println(1 + " " + (n-1));
                out.flush();
                return;
            }
        }

        List<Integer> b = new ArrayList<>();
        int sum = 0;
        for (int i = 0 ; i < m ; i++) {
            if (sum == n) {
                break;
            }
            if (i == 0) {
                b.add(desireOrder.get(0)+1);
            } else if (i+1 < m) {
                b.add(desireOrder.get(i));
            } else {
                b.add(desireOrder.get(m-1)-1);
            }
            sum += b.get(b.size()-1);
        }

        out.println(buildLine(desireOrder));
        out.println(b.size());
        out.println(buildLine(b));
        out.flush();
    }

    private static String buildLine(List<Integer> o) {
        StringBuilder line = new StringBuilder();
        for (int i : o) {
            line.append(' ').append(i);
        }
        return line.substring(1);
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