// package arc.arc092;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }
        long max = (long)-1e12;
        int bestIdx = -1;
        for (int i = 0; i < n ; i++) {
            if (max < a[i]) {
                max = a[i];
                bestIdx = i;
            }
        }

        if (max < 0) {
            out.println(max);
            out.println(n-1);
            for (int i = n-1 ; i > bestIdx ; i--) {
                out.println(i+1);
            }
            for (int i = 0; i < bestIdx; i++) {
                out.println(1);
            }
            out.flush();
            return;
        }

        long odd = 0;
        long even = 0;
        for (int i = 0; i < n ; i++) {
            if (a[i] >= 0) {
                if (i % 2 == 0) {
                    odd += a[i];
                } else {
                    even += a[i];
                }
            }
        }

        long best = Math.max(odd, even);
        List<Integer> operations = solve(a, odd >= even ? 0 : 1, best);

        out.println(best);
        out.println(operations.size());
        for (int o : operations) {
            out.println(o+1);
        }
        out.flush();
    }


    private static List<Integer> solve(long[] a, int par, long want) {
        List<Integer> operations = new ArrayList<>();
        if (par == 1) {
            operations.add(0);
        }

        List<Long> v = new ArrayList<>();
        for (int i = par; i < a.length ; i++) {
            v.add(a[i]);
        }

        while (true) {
            boolean done = false;
            for (int x = 0 ; x < v.size() ; x += 2) {
                if (v.get(x) < 0) {
                    if (x == 0) {
                        doit(v, operations, 0);
                        doit(v, operations, 0);
                    } else if (x == v.size()-1) {
                        doit(v, operations, v.size()-1);
                        doit(v, operations, v.size()-1);
                    } else {
                        doit(v, operations, x);
                    }
                    done = true;
                    break;
                }
            }
            if (!done) {
                break;
            }
        }

        while (v.size() >= 2) {
            doit(v, operations, 1);
        }

        long wo = v.get(0);
        if (want != wo) {
            debug(want, wo);
            throw new RuntimeException("ng");
        }

        return operations;
    }

    static void doit(List<Long> array, List<Integer> operations, int p) {
        operations.add(p);

        if (p == 0) {
            array.remove(0);
        } else if (p == array.size()-1) {
            array.remove(array.size()-1);
        } else {
            long newv = array.get(p-1) + array.get(p+1);
            array.set(p, newv);
            array.remove(p+1);
            array.remove(p-1);
        }
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
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
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}