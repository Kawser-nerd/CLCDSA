import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashSet;

@SuppressWarnings("unchecked")
public class Main {
    static final int INF = 1000000007;

    static int b;

    static int[] dp;

    static ArrayList<Integer>[] graph;
    static boolean[] gone;

    // ????? Breadth-First Search
    // ?????????????????????
    static void bfs(int start) {
        HashSet<Integer> list = new HashSet<>();
        HashSet<Integer> next = new HashSet<>();

        // ?????????
        list.add(start);

        // ????????
        gone[start] = true;

        while (0 < list.size()) {
            boolean goalFlg = false;

            // ???
            next.clear();

            for (Integer from : list) {
                for (Integer to : graph[from]) {
                    // ????????
                    if (!gone[to]) {
                        next.add(to);

                        dp[to] = (dp[to] + dp[from]) % INF;

                        // ???
                        if (to == b) goalFlg =true;
                    }
                }
            }

            if (goalFlg) break;

            list = new HashSet<>(next);

            // ??????????
            for (Integer i : next) gone[i] = true;
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int N = nextInt();

        // 0-indexed
        final int a = nextInt() - 1;
        b = nextInt() - 1;

        final int M = nextInt();

        graph = new ArrayList[N];

        for (int i = 0; i < N; i++) graph[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            // 0-indexed
            final int x = nextInt() - 1;
            final int y = nextInt() - 1;

            graph[x].add(y);
            graph[y].add(x);
        }

        gone = new boolean[N];
        dp = new int[N];

        Arrays.fill(gone, false);
        Arrays.fill(dp, 0);

        // ????? Breadth-First Search
        // ?????????????????????
        dp[a] = 1;

        bfs(a);

        out.println(dp[b]);

        out.flush();
    }

    // FastScanner start
    static final InputStream in = System.in;
    static final byte[] buffer = new byte[1024];
    static int ptr = 0;
    static int buflen = 0;
    static boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    static int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }
    static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    static boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    static String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    static long nextLong() {
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
            } else if(b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    static int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }
    static double nextDouble() {
        return Double.parseDouble(next());
    }
    // FastScanner end
}