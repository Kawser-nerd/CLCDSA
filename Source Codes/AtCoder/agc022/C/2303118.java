// package agc.agc022;

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
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n ; i++) {
            b[i] = in.nextInt();
        }

        opset = new List[n];
        for (int i = 0; i < n ; i++) {
            opset[i] = new ArrayList<>();
        }

        for (int i = 0; i < n ; i++) {
            dfs(i, a[i], b[i], new int[64], 0);
        }

        long minCost = 0;
        for (int i = 51 ; i >= 0 ; i--) {
            long bit = 1L<<i;
            long tr = minCost | (bit - 1);
            if (!canMake(tr)) {
                minCost |= bit;
            }
        }
        if (!canMake((1L<<51)-1)) {
            minCost = -1;
        }
        out.println(minCost);
        out.flush();
    }

    private static boolean canMake(long set) {
        for (List<Long> op : opset) {
            boolean isOK = false;
            for (long o : op) {
                if ((o & set) == o) {
                    isOK = true;
                    break;
                }
            }
            if (!isOK) {
                return false;
            }
        }
        return true;
    }


    static List<Long>[] opset;



    static void dfs(int setindex, int now, int target, int[] ops, int idx) {
        if (now < target) {
            return;
        } else if (now == target) {
            long op = 0;
            for (int i = 0; i < idx; i++) {
                op |= 1L<<ops[i];
            }
            opset[setindex].add(op);
            return;
        }

        for (int i = 1 ; i <= 50 ; i++) {
            int mo = now % i;
            if (mo == now) {
                continue;
            }
            ops[idx] = i;
            dfs(setindex, mo, target, ops, idx+1);
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.