import java.io.*;
import java.util.*;

public class C {
    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String POSSIBLE = "POSSIBLE";
    FastScanner in;
    PrintWriter out;

    class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    enum DIRECTION {
        DOWN, UP, LEFT, RIGHT;
    }

    int getDxByDirection(DIRECTION dir) {
        switch (dir) {
            case UP:
                return -1;
            case DOWN:
                return 1;
            default:
                return 0;
        }
    }

    int getDyByDirection(DIRECTION dir) {
        switch (dir) {
            case LEFT:
                return -1;
            case RIGHT:
                return 1;
            default:
                return 0;
        }
    }

    DIRECTION getNextDir(char c, DIRECTION dir) {
        if (c == '/') {
            switch (dir) {
                case UP:
                    return DIRECTION.RIGHT;
                case RIGHT:
                    return DIRECTION.UP;
                case DOWN:
                    return DIRECTION.LEFT;
                default:
                    return DIRECTION.DOWN;
            }
        } else if (c == '\\') {
            switch (dir) {
                case UP:
                    return DIRECTION.LEFT;
                case LEFT:
                    return DIRECTION.UP;
                case RIGHT:
                    return DIRECTION.DOWN;
                default:
                    return DIRECTION.RIGHT;
            }
        } else {
            throw new AssertionError();
        }
    }

    boolean go(Point cell, DIRECTION dir, char[][] a, ArrayList<Point> path, int depth) {
        if (depth > 5010) {
            return false;
        }
        Point next = new Point(cell.x + getDxByDirection(dir), cell.y + getDyByDirection(dir));
        if (next.x < 0 || next.x >= a.length || next.y < 0 || next.y >= a[0].length) {
            return true;
        }
        char c = a[next.x][next.y];
        if (c == '.') {
            path.add(next);
            return go(next, dir, a, path, depth + 1);
        }
        if (c == '-' || c == '|') {
            return false;
        }
        if (c == '#') {
            return true;
        }
        return go(next, getNextDir(c, dir), a, path, depth + 1);
    }

    class How {
        int id;
        boolean hor;

        public How(int id, boolean hor) {
            this.id = id;
            this.hor = hor;
        }
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            out.print("Case #" + (t + 1) + ": ");
            int n = in.nextInt();
            int m = in.nextInt();
            char[][] a = new char[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }
            int iter = 0;
            ArrayList<Point> allPos = new ArrayList<>();
            ArrayList<How>[][] canUse = new ArrayList[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    canUse[i][j] = new ArrayList<>();
                }
            }
            boolean[][] canHor = new boolean[n][m];
            boolean[][] canVer = new boolean[n][m];
            int[][] id = new int[n][m];
            boolean fail = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '-' || a[i][j] == '|') {
                        ArrayList<Point> path = new ArrayList<>();
                        if (go(new Point(i, j), DIRECTION.LEFT, a, path, 0) && go(new Point(i, j), DIRECTION.RIGHT, a, path, 0)) {
                            canHor[i][j] = true;
                            for (Point p : path) {
                                boolean not = false;
                                if (canUse[p.x][p.y].size() > 0) {
                                    How last = canUse[p.x][p.y].get(canUse[p.x][p.y].size() - 1);
                                    if (last.id == iter && last.hor == true) {
                                        not = true;
                                    }
                                }
                                if (!not) {
                                    canUse[p.x][p.y].add(new How(iter, true));
                                }
                            }
                        }
                        path.clear();
                        if (go(new Point(i, j), DIRECTION.UP, a, path, 0) && go(new Point(i, j), DIRECTION.DOWN, a, path, 0)) {
                            canVer[i][j] = true;
                            for (Point p : path) {
                                boolean not = false;
                                if (canUse[p.x][p.y].size() > 0) {
                                    How last = canUse[p.x][p.y].get(canUse[p.x][p.y].size() - 1);
                                    if (last.id == iter && last.hor == false) {
                                        not = true;
                                    }
                                }
                                if (!not) {
                                    canUse[p.x][p.y].add(new How(iter, false));
                                }
                            }
                        }
                        allPos.add(new Point(i, j));
                        id[i][j] = iter;
                        if (!canHor[i][j] && !canVer[i][j]) {
                            fail = true;
                        }
                        iter++;
                    }
                }
            }
            Sat2 sat = new Sat2(iter * 2);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '.') {
                        if (canUse[i][j].size() == 1) {
                            How how = canUse[i][j].get(0);
                            Point p = allPos.get(how.id);
                            if (how.hor) {
                                canVer[p.x][p.y] = false;
                            } else {
                                canHor[p.x][p.y] = false;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!canHor[i][j] && !canVer[i][j] && (a[i][j] == '|' || a[i][j] == '-')) {
                        fail = true;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '.' && canUse[i][j].isEmpty()) {
                        fail = true;
                    }
                    if (a[i][j] == '|' || a[i][j] == '-') {
                        int mid = id[i][j];
                        if (!canHor[i][j]) {
                            sat.addEdge(mid * 2, mid * 2 + 1);
                        }
                        if (!canVer[i][j]) {
                            sat.addEdge(mid * 2 + 1, mid * 2);
                        }
                    }
                    if (a[i][j] == '.') {
                        if (canUse[i][j].size() == 2) {
                            How h1 = canUse[i][j].get(0);
                            How h2 = canUse[i][j].get(1);
                            Point p1 = allPos.get(h1.id);
                            Point p2 = allPos.get(h2.id);
                            if (p1.x == p2.x && p1.y == p2.y) {
                                if (h1.hor == h2.hor) {
                                    fail = true;
                                    for (int ii = 0; ii < n; ii++) {
                                        System.err.println(new String(a[ii]));
                                    }
                                    System.err.println("???");
//                                    throw new AssertionError();
                                }
                            } else {
                                int id1 = h1.id * 2 + (h1.hor ? 1 : 0);
                                int id2 = h2.id * 2 + (h2.hor ? 1 : 0);
                                sat.addEdge(id1, id2 ^ 1);
                                sat.addEdge(id2, id1 ^ 1);
                            }
                        }
                        if (canUse[i][j].size() > 2) {
                            throw new AssertionError();
                        }
                    }
                }
            }
            if (fail) {
                out.println(IMPOSSIBLE);
            } else {
                boolean[] res = sat.solve();
                if (res == null) {
                    out.println(IMPOSSIBLE);
                } else {
                    out.println(POSSIBLE);
                    for (int i = 0; i < iter; i++) {
                        Point p = allPos.get(i);
                        if (res[i]) {
                            a[p.x][p.y] = '-';
                        } else {
                            a[p.x][p.y] = '|';
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        out.println(new String(a[i]));
                    }
                }
            }
            System.err.println((t + 1) + "/" + tc + " done");
        }
    }

    class Sat2 {
        ArrayList<Integer>[] g, gt;
        int n;

        Sat2(int n) {
            this.n = n;
            g = new ArrayList[n];
            gt = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
                gt[i] = new ArrayList<>();
            }
        }

        void addEdge(int fr, int to) {
            g[fr].add(to);
            g[to ^ 1].add(fr ^ 1);
            gt[to].add(fr);
            gt[fr ^ 1].add(to ^ 1);
        }

        boolean[] used;
        int[] comp;
        int[] order;
        int orderIt;

        void dfs1(int v) {
            used[v] = true;
            for (int i = 0; i < g[v].size(); ++i) {
                int to = g[v].get(i);
                if (!used[to])
                    dfs1(to);
            }
            order[orderIt++] = v;
        }

        void dfs2(int v, int cl) {
            comp[v] = cl;
            for (int i = 0; i < gt[v].size(); ++i) {
                int to = gt[v].get(i);
                if (comp[to] == -1)
                    dfs2(to, cl);
            }
        }

        boolean[] solve() {
            order = new int[n];
            used = new boolean[n];
            for (int i = 0; i < n; ++i)
                if (!used[i])
                    dfs1(i);

            comp = new int[n];
            Arrays.fill(comp, -1);
            for (int i = 0, j = 0; i < n; ++i) {
                int v = order[n - i - 1];
                if (comp[v] == -1)
                    dfs2(v, j++);
            }

            for (int i = 0; i < n; ++i)
                if (comp[i] == comp[i ^ 1]) {
                    return null;
                }
            boolean[] res = new boolean[n / 2];
            for (int i = 0; i < n; i += 2) {
                res[i / 2] = comp[i] > comp[i ^ 1];

            }
            return res;
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new C().run();
    }
}