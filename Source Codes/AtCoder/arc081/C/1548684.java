// package arc.arc081;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        char[] A = in.nextToken().toCharArray();

        n = A.length;
        nextChar = new int[26][n+2];
        nextAny = new int[19][n+2];
        nextAny[0][n+1] = n+1;

        int[] lastC = new int[26];
        Arrays.fill(lastC, n+1);
        for (int i = n - 1; i >= -1 ; i--) {
            for (int j = 0; j < 26; j++) {
                nextChar[j][i+1] = lastC[j];
                nextAny[0][i+1] = Math.max(nextAny[0][i+1], lastC[j]);
            }
            if (i >= 0) {
                lastC[A[i] - 'a'] = i + 1;
            }
        }
        for (int f = 1 ; f < nextAny.length ; f++) {
            for (int i = 0 ; i <= n+1 ; i++) {
                nextAny[f][i] = nextAny[f-1][nextAny[f-1][i]];
            }
        }

        int cnt = canTakeFrom(0) + 1;

        StringBuilder ans = new StringBuilder();
        int head = 0;
        for (int i = 0 ; i < cnt ; i++) {
            int left = cnt - i - 1;
            boolean found = false;
            for (int cc = 0 ; cc < 26 ; cc++) {
                int chead = nextChar[cc][head];
                if (canTakeFrom(chead) < left) {
                    found = true;
                    head = chead;
                    ans.append((char)('a'+cc));
                    break;
                }
            }
            if (!found) {
                debug("==");
                while (i < cnt) {
                    ans.append('a');
                    i++;
                }
                break;
            }
        }
        
        out.println(ans.toString());
        out.flush();
    }

    static int n;
    static int[][] nextChar;
    static int[][] nextAny;

    static int canTakeFrom(int head) {
        if (head > n) {
            return -1;
        }
        int tk = 0;
        for (int c = 18 ; c >= 0 ; c--) {
            int th = nextAny[c][head];
            if (th <= n) {
                tk += 1<<c;
                head = th;
            }
        }
        return tk;
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