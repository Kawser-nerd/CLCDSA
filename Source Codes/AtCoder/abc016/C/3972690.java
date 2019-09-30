import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.Arrays;
import java.util.ArrayDeque;
import java.util.ArrayList;
//import java.util.Collection;
//import java.util.Collections;
//import java.util.Comparator;
//import java.util.Formatter;
//import java.util.HashSet;
//import java.util.HashMap;
//import java.util.Iterator;
//import java.util.LinkedHashMap;
//import java.util.Map;
//import java.util.Map.Entry;
//import java.util.PriorityQueue;
//import java.util.Set;
//import java.util.Stack;
//import java.util.stream.Collectors;
//import java.util.stream.Stream;

class Edge implements Comparable<Edge> {
    // ???? ?????
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
    static ArrayList<Edge>[] routeList;
    static int[] costAry;

    static boolean[] gone;

    static int cnt;

    // ????? Breadth-First Search
    static void bfs(int start) {
        ArrayDeque<Edge> que = new ArrayDeque<>();

        // ??????????????
        que.add(new Edge(start, 0));

        // ???0???
        costAry[start] = 0;

        // ????????
        gone[start] = true;

        while (0 < que.size()) {
            Edge q = que.getFirst();
            que.pop();

            for (int i = 0; i < routeList[q.to].size(); i++) {
                Edge e = routeList[q.to].get(i);

                // ????????
                if (gone[e.to] == false) {
                    int cost = costAry[q.to] + e.cost;
                    costAry[e.to] = cost;

                    if (cost == 2) cnt++;
                    else if (cost < 2)
                    // push ?? ??
                    que.add(new Edge(e.to, costAry[e.to]));

                    // ????????
                    gone[e.to] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        final int N = nextInt();
        final int M = nextInt();

        routeList = new ArrayList[N];

        for (int i = 0; i < N; i++) routeList[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            final int A = nextInt() - 1;
            final int B = nextInt() - 1;

            routeList[A].add(new Edge(B, 1));
            routeList[B].add(new Edge(A, 1));
        }

        costAry = new int[N];
        gone = new boolean[N];

        for (int i = 0; i < N; i++) {
            cnt = 0;

            Arrays.fill(costAry, 0);
            Arrays.fill(gone, false);

            // ????? Breadth-First Search
            bfs(i);

            out.println(cnt);
        }

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