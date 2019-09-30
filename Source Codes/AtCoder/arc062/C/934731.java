import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {

    private Map<Long, Integer> keyDups;

    private void solve(FastScanner sc) {
        int n = sc.nextInt();
        long[] keys = new long[n];
        Map<Long, int[][]> rotates = new HashMap<>();
        keyDups = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int d = sc.nextInt();
            long key = toKey(a, b, c, d);
            keys[i] = key;
            rotates.putIfAbsent(key, toRotates(a, b, c, d));
            keyDups.computeIfAbsent(key, l -> 0);
            keyDups.compute(key, (l, old) -> old + 1);
        }
        long count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int[] foot = rotates.get(keys[i])[0];
                for (int[] head : rotates.get(keys[j])) {
                    long ka = toKey(head[1], head[0], foot[1], foot[0]);
                    long kb = toKey(head[2], head[1], foot[0], foot[3]);
                    long kc = toKey(head[3], head[2], foot[3], foot[2]);
                    long kd = toKey(head[0], head[3], foot[2], foot[1]);
                    long kh = toKey(head[0], head[1], head[2], head[3]);
                    long kf = toKey(foot[0], foot[1], foot[2], foot[3]);
                    keyDups.compute(kh, (l, old) -> old - 1);
                    keyDups.compute(kf, (l, old) -> old - 1);
                    long a = match(head[1], head[0], foot[1], foot[0]);
                    keyDups.computeIfPresent(ka, (l, old) -> old - 1);
                    long b = match(head[2], head[1], foot[0], foot[3]);
                    keyDups.computeIfPresent(kb, (l, old) -> old - 1);
                    long c = match(head[3], head[2], foot[3], foot[2]);
                    keyDups.computeIfPresent(kc, (l, old) -> old - 1);
                    long d = match(head[0], head[3], foot[2], foot[1]);
                    keyDups.compute(kh, (l, old) -> old + 1);
                    keyDups.compute(kf, (l, old) -> old + 1);
                    keyDups.computeIfPresent(ka, (l, old) -> old + 1);
                    keyDups.computeIfPresent(kb, (l, old) -> old + 1);
                    keyDups.computeIfPresent(kc, (l, old) -> old + 1);
                    count += a * b * c * d;
                }
            }
        }
        System.out.println(count/6);
    }

    private int match(int a, int b, int c, int d) {
        long key = toKey(a, b, c, d);
        int m = a == c && b == d ? (a == b ? 4 : 2) : 1;
        return keyDups.containsKey(key) ? keyDups.get(key) * m : 0;
    }

    private int[][] toRotates(int a, int b, int c, int d) {
        int[][] rs = new int[4][];
        rs[0] = new int[]{a, b, c, d};
        rs[1] = new int[]{b, c, d, a};
        rs[2] = new int[]{c, d, a, b};
        rs[3] = new int[]{d, a, b, c};
        return rs;
    }

    private long toKey(int a, int b, int c, int d) {
        return Math.min(Math.min(
                a * 1000000000L + b * 1000000L + c * 1000 + d,
                b * 1000000000L + c * 1000000L + d * 1000 + a), Math.min(
                c * 1000000000L + d * 1000000L + a * 1000 + b,
                d * 1000000000L + a * 1000000L + b * 1000 + c));
    }

    /*
     * template
     */

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        new Main().solve(sc);
    }

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int bufLen = 0;

        private boolean hasNextByte() {
            if (ptr < bufLen) {
                return true;
            } else {
                ptr = 0;
                try {
                    bufLen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (bufLen <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
            return hasNextByte();
        }

        String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}