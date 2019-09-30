import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static InputStream is;
    static PrintWriter out;
    static String INPUT = "";

    void solve() {
        int n = ni();
        Set<Integer> edge[] = new Set[n];
        for (int i = 0; i < n; ++i) {
            edge[i] = new HashSet<>();
        }
        Map<Long, Integer> edges = new HashMap<>();
        Queue<Long> pair = new ArrayDeque<>();
        for (int i = 0; i < (n - 1) * 2; ++i) {
            int a = ni() - 1;
            int b = ni() - 1;
            edge[a].add(b);
            edge[b].add(a);
            long key = getKey(a, b);
            int c = inc(edges, key);
            if (c == 2) {
                pair.add(key);
            }
        }
        boolean used[] = new boolean[n];
        for (int m = 1; m < n; ++m) {
            Integer x = -1, y = -1;
            while (!pair.isEmpty()) {
                long key = pair.poll();
                int a = (int) (key >>> 32);
                int b = (int) (key & ((1L << 32) - 1L));
                if (!used[a] && !used[b]) {
                    x = a;
                    y = b;
                    break;
                }
            }
            if (x.equals(-1)) {
                out.println("NO");
                return;
            }
            for (Integer t : edge[y]) {
                edge[t].remove(y);
                if (!t.equals(x)) {
                    edge[t].add(x);
                    edge[x].add(t);
                    long key = getKey(t, x);
                    int c = add(edges, getKey(t, y), key);
                    if (c >= 2) {
                        pair.add(key);
                    }
                }
            }
            used[y] = true;
        }
        out.println("YES");
    }

    long getKey(int a, int b) {
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        return (((long) a) << 32) | (long) b;
    }

    int add(Map<Long, Integer> map, long from, long to) {
        int a = get(map, from);
        int b = get(map, to);
        map.put(to, a + b);
        return a + b;
    }

    int inc(Map<Long, Integer> map, long key) {
        int x = get(map, key) + 1;
        map.put(key, x);
        return x;
    }

    int get(Map<Long, Integer> map, long key) {
        Integer x = map.get(key);
        return x == null ? 0 : x;
    }

    public static void main(String[] args) throws Exception {
        long S = System.currentTimeMillis();
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);

        new Main().solve();
        out.flush();
        long G = System.currentTimeMillis();
        // tr(G - S + "ms");
    }

    private static boolean eof() {
        if (lenbuf == -1) return true;
        int lptr = ptrbuf;
        while (lptr < lenbuf)
            if (!isSpaceChar(inbuf[lptr++])) return false;

        try {
            is.mark(1000);
            while (true) {
                int b = is.read();
                if (b == -1) {
                    is.reset();
                    return true;
                } else if (!isSpaceChar(b)) {
                    is.reset();
                    return false;
                }
            }
        } catch (IOException e) {
            return true;
        }
    }

    private static byte[] inbuf = new byte[1024];
    static int lenbuf = 0, ptrbuf = 0;

    private static int readByte() {
        if (lenbuf == -1) throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0) return -1;
        }
        return inbuf[ptrbuf++];
    }

    private static boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    private static int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b))
            ;
        return b;
    }

    private static double nd() {
        return Double.parseDouble(ns());
    }

    private static char nc() {
        return (char) skip();
    }

    private static String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private static char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private static char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++)
            map[i] = ns(m);
        return map;
    }

    private static int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = ni();
        return a;
    }

    private static int ni() {
        int num = 0, b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private static long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private static void tr(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.