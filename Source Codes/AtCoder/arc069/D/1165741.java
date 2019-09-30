// package atcoder.arc.arc069;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        pair = new Point[n][2];
        pt = new ArrayList<>();
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < 2 ; j++) {
                pair[i][j] = new Point(in.nextInt(), i*2+j);
                pt.add(pair[i][j]);
            }
        }
        Collections.sort(pt, (p, q) -> Long.compare(p.sortValue(), q.sortValue()));

        foundIds = new int[1000];
        M = Integer.highestOneBit(2*n-1)<<1;
        for (int i = 0 ; i < pt.size() ; i++) {
            pt.get(i).id = M-1+i;
        }
        sat = new SAT2(2*M);

        int ok = 0;
        int ng = 1000000000;
        while (ng - ok > 1) {
            int med = (ng + ok) / 2;
            if (canBuild(med)) {
                ok = med;
            } else {
                ng = med;
            }
        }

        out.println(ok);
        out.flush();
    }

    static Point[][] pair;
    static List<Point> pt;
    static SAT2 sat;
    
    private static boolean canBuild(int range) {
        sat.clear();

        for (int i = 0; i < pair.length ; i++) {
            sat.xor(pair[i][0].id, pair[i][1].id);
        }
        for (int p = 1 ; p < 2*M-2 ; p++) {
            sat.then(p, (p-1)/2);
        }

        int pn = pt.size();
        int L = 0;
        int R = 0;
        for (int i = 0 ; i < pn ; i++) {
            Point c = pt.get(i);
            int p = c.pos;
            while (L < i && pt.get(L).pos + range <= p) {
                L++;
            }
            while (R < pn && pt.get(R).pos < p + range) {
                R++;
            }

            findSegments(L, i);
            for (int j = 0; j < fn; j++) {
                sat.or(sat.not(foundIds[j]), sat.not(c.id));
            }
            findSegments(i+1, R);
            for (int j = 0; j < fn; j++) {
                sat.or(sat.not(foundIds[j]), sat.not(c.id));
            }
        }

        return sat.hasValidAssign();
    }


    static int M;

    static int fn;

    static int[] foundIds;

    static void findSegments(int ql, int qr) {
        fn = 0;
        findSegments(ql, qr, 0, 0, M);
        if (fn >= 30) {
            throw new RuntimeException();
        }
    }

    static void findSegments(int ql, int qr, int idx, int fr, int to) {
        if (qr <= fr || to <= ql) {
            return;
        }

        if (ql <= fr && to <= qr) {
            foundIds[fn++] = idx;
            return;
        }

        int med = (fr + to) / 2;
        findSegments(ql, qr, idx*2+1, fr, med);
        findSegments(ql, qr, idx*2+2, med, to);
    }

    static class Point {
        int id;
        int pos;
        int pos2;

        Point(int p, int i) {
            pos = p;
            pos2 = i;
        }

        long sortValue() {
            return (long)pos * 114514 + pos2;
        }
    }

    public static class DirectedGraph {
        int[] head;
        int[] next;
        int[] to;
        int eidx;

        public DirectedGraph(int v, int e) {
            head = new int[v];
            next = new int[e];
            to = new int[e];
            clear();
        }

        public void clear() {
            Arrays.fill(head, -1);
            eidx = 0;
        }

        public void add(int a, int b) {
            next[eidx] = head[a];
            head[a] = eidx;
            to[eidx++] = b;
        }

        public Iterable<Integer> nexts(int v) {
            final int firstE = head[v];
            return () -> new Iterator<Integer>() {
                int cursor = firstE;

                @Override
                public boolean hasNext() {
                    return cursor != -1;
                }

                @Override
                public Integer next() {
                    int ret = to[cursor];
                    cursor = next[cursor];
                    return ret;
                }
            };
        }
    }

    public static class SAT2 {
        boolean[] visited;
        int[] nodeId;
        int[] rev;
        int rvn;

        int n;
        int vn;
        DirectedGraph graph;
        DirectedGraph revGraph;

        public SAT2(int maxN) {
            n = maxN;
            vn = n * 2;

            graph = new DirectedGraph(vn, 2000000);
            revGraph = new DirectedGraph(vn, 2000000);
            nodeId = new int[vn];
            visited = new boolean[vn];
            rev = new int[vn];
        }

        public void clear() {
            Arrays.fill(nodeId, 0);
            Arrays.fill(visited, false);
            graph.clear();
            revGraph.clear();
            rvn = 0;
        }

        public int not(int v) {
            return v >= n ? v - n : v + n;
        }

        public void xor(int a, int b) {
            // a xor b => [a or b] and [(not a) or (not b)]
            or(a, b);
            or(not(a), not(b));
        }

        public void or(int a, int b) {
            // a or b => [(not a) then b] and [(not b) then a]
            then(not(a), b);
            then(not(b), a);
        }

        public void then(int a, int b) {
            graph.add(a, b);
            revGraph.add(b, a);
        }

        public void doit() {
            for (int i = 0; i < vn ; i++) {
                if (!visited[i]) {
                    dfs(i);
                }
            }
            Arrays.fill(visited, false);
            int id = 0;
            for (int i = rvn-1 ; i >= 0; i--) {
                if (!visited[rev[i]]) {
                    rdfs(rev[i], id);
                    id++;
                }
            }
        }

        private boolean hasValidAssign() {
            doit();
            for (int i = 0; i < n ; i++) {
                if (nodeId[i] == nodeId[i+n]) {
                    return false;
                }
            }
            return true;
        }

        private boolean[] findValidAssign() {
            doit();
            boolean[] ret = new boolean[n];
            for (int i = 0; i < n ; i++) {
                if (nodeId[i] == nodeId[i+n]) {
                    return null;
                }
                ret[i] = nodeId[i] > nodeId[i+n];
            }
            return ret;
        }

        private void dfs(int i) {
            visited[i] = true;
            for (int next : graph.nexts(i)) {
                if (!visited[next]) {
                    dfs(next);
                }
            }
            rev[rvn++] = i;
        }

        private void rdfs(int i, int id) {
            visited[i] = true;
            nodeId[i] = id;
            for (int next : revGraph.nexts(i)) {
                if (!visited[next]) {
                    rdfs(next, id);
                }
            }
        }
    }


    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int[] nextInts(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        private int[][] nextIntTable(int n, int m) {
            int[][] ret = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextInt();
                }
            }
            return ret;
        }

        private long[] nextLongs(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

        private long[][] nextLongTable(int n, int m) {
            long[][] ret = new long[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i][j] = nextLong();
                }
            }
            return ret;
        }

        private double[] nextDoubles(int n) {
            double[] ret = new double[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextDouble();
            }
            return ret;
        }

        private int next() {
            if (numChars == -1)
                throw new InputMismatchException();
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
            int c = next();
            while (isSpaceChar(c))
                c = next();
            if ('a' <= c && c <= 'z') {
                return (char) c;
            }
            if ('A' <= c && c <= 'Z') {
                return (char) c;
            }
            throw new InputMismatchException();
        }

        public String nextToken() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public long nextLong() {
            int c = next();
            while (isSpaceChar(c))
                c = next();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c-'0';
                c = next();
            } while (!isSpaceChar(c));
            return res*sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}