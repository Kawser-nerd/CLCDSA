import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
import static java.lang.Math.*;

class A implements Runnable {
    class Pair implements Comparable<Pair> {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Pair o) {
            if (x != o.x) {
                return x - o.x;
            } else {
                return y - o.y;
            }
        }

        public boolean equals(Object o) {
            Pair pair = (Pair) o;
            return x == pair.x && y == pair.y;
        }

        boolean adj(Pair p) {
            return abs(x - p.x) + abs(y - p.y) == 1;
        }

        public int hashCode() {
            int result;
            result = x;
            result = 31 * result + y;
            return result;
        }
    }

    class Position {
        Pair[] p;
        boolean good;
        int dist;

        Position from;

        Position(ArrayList<Pair> q) {
            p = new Pair[q.size()];
            for (int i = 0; i < q.size(); i++) {
                p[i] = q.get(i);
            }
            Arrays.sort(p);
            good = true;
            dist = 0;
        }

        Position(Position src, int index, Pair newPair) {
            from = src;
            p = src.p.clone();
            p[index] = newPair;
            Arrays.sort(p);
            checkValid();
            dist = src.dist + 1;
        }

        void print() {
            if (from != null) {
                from.print();
            }
            printPosition(this);
        }

        void checkValid() {
            boolean[] r = new boolean[p.length];
            r[0] = true;
            for (int i = 0; i < p.length; i++) {
                for (int j = 0; j < r.length; j++) {
                    if (r[j]) {
                        for (int k = 0; k < p.length; k++) {
                            if (p[j].adj(p[k])) {
                                r[k] = true;
                            }
                        }
                    }
                }
            }
            good = true;
            for (int i = 0; i < r.length; i++) {
                if (!r[i]) {
                    good = false;
                }
            }
        }

        public boolean equals(Object o) {
            Position position = (Position) o;
            return Arrays.equals(p, position.p);
        }

        public int hashCode() {
            return (p != null ? Arrays.hashCode(p) : 0);
        }

    }

    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};

    int r;
    int c;

    Set<Pair> ob;

    public void printPosition(Position p) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                boolean found = false;
                for (int k = 0; k < p.p.length; k++) {
                    if (p.p[k].x == i && p.p[k].y == j) {
                        System.err.print("@");
                        found = true;
                    }
                }
                if (!found) {
                    if (ob.contains(new Pair(i, j))) {
                        System.err.print("#");
                    } else {
                        System.err.print(".");
                    }
                }
            }
            System.err.println("");
        }
        System.err.println("");
    }

    public void solve() throws IOException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("A-large.out"));

        int testn = in.nextInt();
        tests:
        for (int test = 0; test < testn; test++) {
            r = in.nextInt();
            c = in.nextInt();

            ArrayList<Pair> s = new ArrayList<Pair>();
            ArrayList<Pair> t = new ArrayList<Pair>();
            ob = new TreeSet<Pair>();

            for (int i = 0; i < r; i++) {
                String z = in.next();
                for (int j = 0; j < c; j++) {
                    switch (z.charAt(j)) {
                        case '#':
                            ob.add(new Pair(i, j));
                            break;
                        case 'o':
                            s.add(new Pair(i, j));
                            break;
                        case 'x':
                            t.add(new Pair(i, j));
                            break;
                        case 'w':
                            s.add(new Pair(i, j));
                            t.add(new Pair(i, j));
                            break;
                    }
                }
            }

            Position st = new Position(s);
            Position tg = new Position(t);
            if (st.equals(tg)) {
                System.out.println("Case #" + (test + 1) + ": " + 0);
                out.println("Case #" + (test + 1) + ": " + 0);
                continue tests;
            }
            Set<Position> was = new HashSet<Position>();
            was.add(st);
            Queue<Position> q = new ArrayDeque<Position>();
            q.add(st);
            int ans = -1;
            bfs:
            while (q.size() > 0) {
                Position p = q.poll();
                for (int i = 0; i < p.p.length; i++) {
                    search:
                    for (int d = 0; d < 4; d++) {
                        Pair pp = new Pair(p.p[i].x + dx[d], p.p[i].y + dy[d]);
                        Pair bp = new Pair(p.p[i].x - dx[d], p.p[i].y - dy[d]);
                        if (pp.x < 0 || pp.x >= r || pp.y < 0 || pp.y >= c) {
                            continue;
                        }
                        if (bp.x < 0 || bp.x >= r || bp.y < 0 || bp.y >= c) {
                            continue;
                        }
                        if (ob.contains(pp)) {
                            continue;
                        }
                        if (ob.contains(bp)) {
                            continue;
                        }
                        for (Pair pq : p.p) {
                            if (pq.equals(pp)) {
                                continue search;
                            }
                            if (pq.equals(bp)) {
                                continue search;
                            }
                        }
                        Position np = new Position(p, i, pp);
                        if (np.equals(tg)) {
                            ans = np.dist;
//                            np.print();
                            break bfs;
                        }
                        if (!p.good && !np.good) {
                            continue;
                        }
                        if (was.contains(np)) {
                            continue;
                        }
                        was.add(np);
                        q.add(np);
                    }
                }
            }

            System.out.println("Case #" + (test + 1) + ": " + ans);
            out.println("Case #" + (test + 1) + ": " + ans);
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
            throw new AssertionError();
        }
    }

    public static void main(String[] args) {
        new Thread(new A()).start();
    }
}