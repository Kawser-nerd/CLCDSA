package gcj.gcj2016.round2;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by hama_du on 5/1/16.
 */
public class A {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int T = in.nextInt();
        for (int t = 1 ; t <= T ; t++) {
            int n = in.nextInt();
            int r = in.nextInt();
            int p = in.nextInt();
            int s = in.nextInt();
            out.println(String.format("Case #%d: %s", t, solve(n, r, p, s)));
        }
        out.flush();
    }

    private static String solve(int n, int r, int p, int s) {
        List<String> ok = new ArrayList<>();
        for (char c : new char[]{'R', 'P', 'S'}) {
            String f = tournament(n, 0, c);
            if (isOK(f, r, p, s)) {
                ok.add(f);
            }
        }
        Collections.sort(ok);
        if (ok.size() >= 1) {
            return ok.get(0);
        }
        return "IMPOSSIBLE";
    }

    private static boolean isOK(String a, int r, int p, int s) {
        for (char c : a.toCharArray()) {
            switch (c) {
                case 'R':
                    r--;
                    break;
                case 'S':
                    s--;
                    break;
                case 'P':
                    p--;
                    break;
            }
        }
        return r == 0 && p == 0 && s == 0;
    }

    private static String tournament(int n, int round, char head) {
        if (n == round) {
            return String.valueOf(head);
        }
        List<String> rnd = new ArrayList<>();
        switch (head) {
            case 'R':
                rnd.add(tournament(n, round+1, 'R'));
                rnd.add(tournament(n, round+1, 'S'));
                break;
            case 'S':
                rnd.add(tournament(n, round+1, 'S'));
                rnd.add(tournament(n, round+1, 'P'));
                break;
            case 'P':
                rnd.add(tournament(n, round+1, 'P'));
                rnd.add(tournament(n, round+1, 'R'));
                break;
        }
        Collections.sort(rnd);
        return rnd.get(0) + rnd.get(1);
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
