import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    List<Integer>[] g;

    int[] maxDist;
    int[] firstEdgeS;

    void go(int v, int p, int curMaxDist, int firstEdge) {
        dfsOrder.add(v);
        maxDist[v] = curMaxDist;
        firstEdgeS[v] = firstEdge;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (v > curMaxDist) {
                go(to, v, v, to);
            } else {
                go(to, v, curMaxDist, firstEdge);
            }
        }
    }

    int getCnt(int v, int shouldBeLess, int p) {
        int res = 1;
        for (int to : g[v]) {
            if (to == p || to >= shouldBeLess) {
                continue;
            }
            res += getCnt(to, shouldBeLess, v);
        }
        return res;
    }

    List<Integer> dfsOrder = new ArrayList<>();

    int[] p;
    int[] sz;

    int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }

    void join(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            sz[y] += sz[x];
        }
    }

    void solve() {
        int n = in.nextInt();
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        maxDist = new int[n];
        firstEdgeS = new int[n];
        go(0, -1, -1, -1);
        int[] ans = new int[n];
        ans[0] = 1;

        List<Event> events = new ArrayList<>();
        for (int startV : dfsOrder) {
            if (startV == 0) {
                continue;
            }
            int goTo = maxDist[startV];
            events.add(new Event(startV, startV, goTo, 1));
            int u = firstEdgeS[startV];
            int next = maxDist[goTo];
            if (u < next) {
                events.add(new Event(startV, u, next, -1));
            }
        }

        p = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
        Collections.sort(events);
        int it = 0;
        int[] time = new int[n];
        Arrays.fill(time, -1);
        for (int v = 0; v < n; v++) {
            while (it < events.size() && events.get(it).shouldBeLess == v) {
                int curVertex = events.get(it).startVertex;
                int sumSize = sz[get(curVertex)];
                time[get(curVertex)] = it;
                for (int u : g[curVertex]) {
                    if (u < v) {
                        int oo = get(u);
                        if (time[oo] != it) {
                            time[oo] = it;
                            sumSize += sz[oo];
                        }
                    }
                }
                ans[events.get(it).whereToAdd] += events.get(it).mul * sumSize;
                it++;
            }
            for (int u : g[v]) {
                if (u < v) {
                    join(u, v);
                }
            }
        }

        for (int startV : dfsOrder) {
            if (startV == 0) {
                continue;
            }
            int goTo = maxDist[startV];
            ans[startV] += ans[goTo];
        }
        for (int v = 1; v < n; v++) {
            out.print((ans[v] - 1) + " ");
        }
    }

    class Event implements Comparable<Event> {
        int whereToAdd;
        int startVertex;
        int shouldBeLess;
        int mul;

        public Event(int whereToAdd, int startVertex, int shouldBeLess, int mul) {
            this.whereToAdd = whereToAdd;
            this.startVertex = startVertex;
            this.shouldBeLess = shouldBeLess;
            this.mul = mul;
        }

        @Override
        public int compareTo(Event o) {
            return Integer.compare(shouldBeLess, o.shouldBeLess);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

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
        new Main().runIO();
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.