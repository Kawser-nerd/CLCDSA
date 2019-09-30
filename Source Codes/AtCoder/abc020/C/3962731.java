import java.io.IOException;
import java.util.NoSuchElementException;

import java.io.InputStream;

import java.io.PrintWriter;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.PriorityQueue;

class Edge implements Comparable<Edge> {
    // ??(x, y) ?????
    int toY;
    int toX;
    long cost;

    Edge(int toY, int toX, long cost) {
        this.toY = toY;
        this.toX = toX;
        this.cost = cost;
    }

    // x.compereTo(y)
    // x ? cost
    // y ? Edge.cost
    @Override
    public int compareTo(Edge edge) {
        int ret = 0;

        // this.cost - edge.cost
        if (edge.cost < this.cost)
            ret = 1;
        else if (this.cost < edge.cost)
            ret = -1;

        return ret;
    }
}

@SuppressWarnings("unchecked")
public class Main {
    static final long MAX_T = 1000000001;
    static final char white = '.';
    static final char black = '#';

    static final char S = 'S';
    static final char G = 'G';

    // ???????
    static final int[] dy = { 1, 0, -1, 0 };
    static final int[] dx = { 0, 1, 0, -1 };

    static int H;
    static int W;
    static long T;

    static char[][] field;
    static boolean[][] gone;

    static ArrayList<Edge>[][] routeList;
    static long[][] costAry;

    static int startX;
    static int startY;

    static int goalX;
    static int goalY;

    static void f(int pY, int pX, int nY, int nX, long mid)
    {
        if (field[nY][nX] == black)
            routeList[pY][pX].add(new Edge(nY, nX, mid));
        else
            routeList[pY][pX].add(new Edge(nY, nX, 1));
    }

    // ?????? ?????
    static long dijkstra (ArrayList<Edge>[][] list, long[][] ary) {
        // ??? ??????
        ary[startY][startX] = 0;

        // ??? ??
        PriorityQueue<Edge> que = new PriorityQueue<> ();

        // ?? ?? ???
        que.add(new Edge(startY, startX, 0));

        // ?? ???????
        gone[startY][startX] = true;

        while (!que.isEmpty()) {
            Edge f = que.poll();

            if (ary[f.toY][f.toX] < f.cost) continue;

            for (int i = 0; i < list[f.toY][f.toX].size(); i++) {
                Edge t = list[f.toY][f.toX].get(i);

                // ????????
                if (gone[t.toY][t.toX] == false) {
                    if (ary[f.toY][f.toX] + t.cost < ary[t.toY][t.toX]) {
                        ary[t.toY][t.toX] = ary[f.toY][f.toX] + t.cost;

                        // ?? ?? ?????
                        que.add(new Edge(t.toY, t.toX, ary[t.toY][t.toX]));
                    }
                    gone[t.toY][t.toX] = true;
                }
            }
        }
        return ary[goalY][goalX];
    }

    // Bisection Method
    // [left, right]
    // to narrow the range
    static long bisectionMethod(long left, long right) {
        while (1 < Math.abs(right - left)) {
            long mid = (left + right) / 2;

            for (int y = 0; y < H; y++) {
                for (int x = 0; x < W; x++) {
                    routeList[y][x] = new ArrayList<>();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny < 0 || H <= ny
                            || nx < 0 || W <= nx) continue;

                        // route ??
                        f(y, x, ny, nx, mid);
                    }

                    // ???
                    costAry[y][x] = MAX_T;
                    // ????????
                    gone[y][x] = false;
                }
            }

            // ?????? ?????
            long cost = dijkstra(routeList, costAry);

            // ????T?????
            if (T < cost) right = mid;
            else if (cost < T) left = mid;
            else {
                left = mid;
                break;
            }
        }

        return left;
    }


    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        H = nextInt();
        W = nextInt();

        T = nextLong();

        field = new char[H][W];
        costAry = new long[H][W];
        gone = new boolean[H][W];

        for (int i = 0; i < H; i++) {
            final String str = next();

            for (int j = 0; j < W; j++) {
                char c = str.charAt(j);

                field[i][j] = c;

                if (S == c) {
                    startY = i;
                    startX = j;
                } else if (G == c) {
                    goalY = i;
                    goalX = j;
                }
            }
        }

        routeList = new ArrayList[H][W];

        out.println(bisectionMethod(0, T));

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