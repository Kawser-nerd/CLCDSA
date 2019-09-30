// package arc.arc096;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    static class Donut implements Comparable<Donut> {
        int count;
        long dough;
        long max;

        public Donut(int c, long d, long m) {
            count = c;
            dough = d;
            max = m;
        }

        @Override
        public int compareTo(Donut o) {
            long w0 = o.count * dough;
            long w1 = count * o.dough;
            if (w0 != w1) {
                return Long.compare(o.count * dough, count * o.dough);
            }
            return count - o.count;
        }
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long X = in.nextInt();
        long D = in.nextInt();
        long[] gram = new long[n];
        int[] cn = new int[n];
        int[] par = new int[n];
        gram[0] = in.nextInt();
        for (int i = 1 ; i < n; i++) {
            gram[i] = in.nextInt();
            par[i] = in.nextInt()-1;
        }
        Arrays.fill(cn, 1);
        for (int i = n-1 ; i >= 1 ; i--) {
            cn[par[i]] += cn[i];
            gram[par[i]] += gram[i];
        }

        Donut[] don = new Donut[n];
        for (int i = 0; i < n ; i++) {
            don[i] = new Donut(cn[i], gram[i], i == 0 ? X : D);
        }
        Arrays.sort(don);


        int CTR = 63751;
        int INF = (int)X + 100;
        long[][] dp = new long[2][CTR];
        for (int i = 0; i < 2; i++) {
            Arrays.fill(dp[i], INF);
        }

        List<Donut> leftDon = new ArrayList<>();
        int parity = 0;
        dp[0][0] = 0;
        {
            int t = 0;
            for (int i = 0; i < n; i++) {
                int max = (int)Math.min(50, don[i].max);
                int sum = 0;
                for (int m = 1 ; m <= max ; m *= 2) {
                    int take = sum + m <= max ? m : max - sum;
                    sum += m;

                    int fr = t % 2;
                    int to = 1 - fr;
                    Arrays.fill(dp[to], INF);
                    t++;
                    for (int c = 0 ; c < CTR ; c++) {
                        long base = dp[fr][c];
                        dp[to][c] = Math.min(dp[to][c], base);
                        int tc = c+take*don[i].count;
                        if (c + take * don[i].count < CTR) {
                            dp[to][tc] = Math.min(dp[to][tc], base + take * don[i].dough);
                        } else {
                            break;
                        }
                    }
                }
                if (don[i].max - max >= 1) {
                    leftDon.add(new Donut(don[i].count, don[i].dough, don[i].max - max));
                }
            }
            parity = t % 2;
        }
        
        Collections.sort(leftDon);

        long best = 0;
        for (int i = 0 ; i < CTR ; i++) {
            if (dp[parity][i] == INF) {
                continue;
            }
            long totalCount = i;
            long left = X - dp[parity][i];
            if (left >= 0) {
                for (int j = 0; j < leftDon.size(); j++) {
                    Donut ld = leftDon.get(j);
                    long canTake = Math.min(ld.max, left / ld.dough);
                    totalCount += canTake * ld.count;
                    left -= canTake * ld.dough;
                }
                best = Math.max(best, totalCount);
            }
        }

        out.println(best);
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