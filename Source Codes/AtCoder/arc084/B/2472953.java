import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int k = in.nextInt();

        int[] dp = new int[2*k];
        Arrays.fill(dp, 10000);
        dp[1] = 1;

        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(u -> u[1]));
        q.add(new int[]{1, 1});
        while (q.size() >= 1) {
            int[] now = q.poll();
            int time = now[1];
            int num = now[0] - ((now[0] >= k) ? k : 0);
            boolean flg = now[0] >= k;
            if (dp[num] < time) {
                continue;
            }

            if (!flg) {
                for (int i = 1; i <= 9; i++) {
                    int tk = (num+i)%k+k;
                    if (dp[tk] > time+i) {
                        dp[tk] = time+i;
                        q.add(new int[]{tk, time+i});
                    }
                }
            }
            int tk = (num*10)%k;
            if (dp[tk] > time) {
                dp[tk] = time;
                q.add(new int[]{tk, time});
            }
        }
        out.println(Math.min(dp[0], dp[k]));
        out.flush();
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