import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.Arrays;
import java.util.ArrayList;

class Edge implements Comparable<Edge> {
    // ???? ????
    int to;
    int cost;

    Edge(int to, int cost) {
        this.to = to;
        this.cost = cost;
    }

    // x.compereTo(y)
    // x ? cost
    // y ? Edge.cost
    @Override
    public int compareTo(Edge edge) {
        return this.cost - edge.cost;
    }
}

@SuppressWarnings("unchecked")
public class Main {
    static final int MAX_L = 100000;

    static int[][] d;

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int N = nextInt();
        final int M = nextInt();

        final int MAX_N = N;
        final int MAX_T = MAX_N * MAX_L + 1;

        d = new int[MAX_N][MAX_N];

        for (int i = 0; i < MAX_N; i++) Arrays.fill(d[i], MAX_T);

        ArrayList<Edge>[] adjacent = new ArrayList[1];

        adjacent[0] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            // 0-indexed
            final int u = nextInt() - 1;
            final int v = nextInt() - 1;
            final int l = nextInt();

            // ??????????????????
            // ??1??????
            if (u == 0) adjacent[u].add(new Edge(v, l));
            else {
                // ??1????????
                d[u][v] = l;
                d[v][u] = l;
            }
        }

        // Warshall–Floyd
        // k????
        for (int k = 1; k < N; k++)
            for (int i = 1; i < N; i++)
                for (int j = 1; j < N; j++)
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);

        int ans = MAX_T;

        for (Edge start : adjacent[0]) {
            for (Edge end : adjacent[0]) {
                int s = start.to;
                int e = end.to;

                if (s == e) continue;

                int sc = start.cost;
                int ec = end.cost;
                ans = Math.min(ans, d[s][e] + sc + ec);
            }
        }

        out.println(ans == MAX_T ? -1 : ans);

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