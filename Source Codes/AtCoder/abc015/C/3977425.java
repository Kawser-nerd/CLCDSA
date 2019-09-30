import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.ArrayDeque;

class Pair {
    int first;
    int second;

    Pair (int first, int second) {
        this.first = first;
        this.second = second;
    }
}

@SuppressWarnings("unchecked")
public class Main {
    static int N;
    static int K;

    static int[][] T;

    // ????? Breadth-First Search
    // ?????? true
    static boolean bfs() {
        ArrayDeque<Pair> que = new ArrayDeque<>();

        // ?????????
        int start = 0;

        for (int i = 0; i < K; i++) que.add(new Pair(T[start][i], start));

        while (!que.isEmpty()) {
            Pair p = que.poll();

            int value = p.first;
            int rank = p.second;

            if (rank == N - 1 && value == 0)
                return true;

            int next = rank + 1;

            if (next < N)
                for (int i = 0; i < K; i++)
                    que.add(new Pair(value ^ T[next][i], next));
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        N = nextInt();
        K = nextInt();

        T = new int[N][K];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < K; j++)
                T[i][j] = nextInt();

        // ????? Breadth-First Search
        out.println(bfs() ? "Found" : "Nothing");

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