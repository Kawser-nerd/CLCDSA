// package arc.arc086;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    private static final long MOD = 1000000007;

    static class Pattern {
        long leftOperation;
        long head;
        long[] diff;
        Pattern(long[] a, long left) {
            int n = a.length;
            diff = new long[n-1];
            for (int i = 0; i < n-1 ; i++) {
                diff[i] = a[i+1] - a[i];
            }

            head = Long.MAX_VALUE;
            for (int i = 0; i < n ; i++) {
                head = Math.min(head, a[i]);
            }
            leftOperation = Math.min(left, head);
        }

        public int hashCode() {
            return Arrays.hashCode(diff);
        }

        public boolean equals(Object o) {
            Pattern p = (Pattern) o;
            for (int i = 0; i < diff.length; i++) {
                if (diff[i] != p.diff[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        long K = in.nextLong();
        long[] a = new long[n];
        for (int i = 0; i < n ; i++) {
            a[i] = in.nextLong();
        }
        Arrays.sort(a);

        List<Pattern> arr = new ArrayList<>();
        for (int b = 0 ; b <= 60 ; b++) {
            long pw = 1L<<b;
            long[] mod = new long[n+2];
            for (int i = 0; i < n ; i++) {
                mod[i] = a[i] & (pw-1);
            }
            mod[n] = -1;
            mod[n+1] = pw-1;
            Arrays.sort(mod);

            long last = -1;
            for (int i = 0; i+1 < mod.length ; i++) {
                if (mod[i] == mod[i+1]) {
                    continue;
                }
                if (mod[i] > a[0]) {
                    continue;
                }
                Pattern ptn = computePattern(a, b, last+1, mod[i+1], K);
                if (ptn.leftOperation >= 0) {
                    arr.add(ptn);
                }
                last = mod[i+1];
            }
        }

        Map<Pattern, List<long[]>> pset = new HashMap<>();
        for (Pattern ptn : arr) {
            if (!pset.containsKey(ptn)) {
                pset.put(ptn, new ArrayList<>());
            }
            pset.get(ptn).add(new long[]{ptn.head - ptn.leftOperation, ptn.head});
        }

        long ans = 0;
        for (Pattern ptn : pset.keySet()) {
            List<long[]> ranges = pset.get(ptn);
            ans += solve(ranges);
            ans %= MOD;
        }

        out.println(ans);
        out.flush();
    }

    private static Pattern computePattern(long[] a, int B, long from, long to, long K) {
        long div = 1L<<B;
        long[] ta = new long[a.length];
        for (int i = 0; i < a.length ; i++) {
            ta[i] = (a[i] - from) / div;
        }

        long mask = div - 1;
        long cnt = K - B - minPopcount(from & mask, to & mask);
        return new Pattern(ta, cnt);
    }

    private static int minPopcount(long from, long to) {
        int cnt = 0;
        for (int b = 60 ; b >= 0 ; b--) {
            long mask = 1L<<b;
            if ((from & mask) == (to & mask)) {
                cnt += ((from & mask) == 0) ? 0 : 1;
            } else {
                assert (from & mask) == 0;
                assert (to & mask) >= 1;

                if (from % mask >= 1) {
                    cnt++;
                }
                break;
            }
        }
        return cnt;
    }

    private static long solve(List<long[]> ranges) {
        ranges.sort(Comparator.comparingLong(u -> u[0]));

        long count = 0;
        long last = -1;
        long coverMax = -1;

        for (long[] l : ranges) {
            if (coverMax < l[0]) {
                if (last != -1) {
                    count += (coverMax - last + 1) % MOD;
                }
                last = l[0];
                coverMax = l[1];
            } else {
                coverMax = Math.max(coverMax, l[1]);
            }
        }
        count += (coverMax - last + 1) % MOD;

        return count % MOD;
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