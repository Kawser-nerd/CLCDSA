import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    class P {
        int a, b;

        public P(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            P p = (P) o;

            if (a != p.a) return false;
            if (b != p.b) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = a;
            result = 31 * result + b;
            return result;
        }
    }

    public void solve() throws IOException {
        int testNo = in.nextInt();
        in.next();
        for (int test = 1; test <= testNo; test++) {
            Map<String, Integer> words = new HashMap<>();
            Set<P> eds = new HashSet<>();
            Set<Integer> lineV = new HashSet<>();

            int n = in.nextInt();
            in.next();
            int nv = 2;
            for (int i = 0; i < n; i++) {
                String s = in.next();
                Set<Integer> line = new HashSet<>();
                while (!s.equals("$")) {
                    if (!words.containsKey(s)) {
                        words.put(s, nv++);
                    }
                    line.add(words.get(s));
                    s = in.next();
                }
                int linev = nv++;
                lineV.add(linev);
                for (int x : line) {
                    eds.add(new P(x, linev));
                    eds.add(new P(linev, x));
                }
                if (i == 0) {
                    for (int x : line) {
                        eds.add(new P(0, x));
                    }
                }
                if (i == 1) {
                    for (int x : line) {
                        eds.add(new P(x, 1));
                    }
                }
            }

            Graph g = new Graph(2 * nv);
            for (P p : eds) {
                g.addEdge(2 * p.a + 1, 2 * p.b, 1_000_000);
            }
            for (int i = 0; i < nv; i++) {
                if (lineV.contains(i)) {
                    g.addEdge(2 * i, 2 * i + 1, 1_000_000);
                } else {
                    g.addEdge(2 * i, 2 * i + 1, 1);
                }
            }

            long ans = g.maxFlow(1, 2);
            out("Case #%d: %d\n", test, ans);
        }
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-large.in"));
            out = new PrintWriter(new File("C-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class Edge {
        int s;
        int t;
        int c;
        int f;
        Edge r;

        Edge(int s, int t, int c) {
            this.s = s;
            this.t = t;
            this.c = c;
        }

        public String toString() {
            return s + "->" + t + " (" + f + "/" + c + ")";
        }
    }

    class Graph {
        int vn;
        ArrayList<Edge>[] es;
        int flow;

        Graph(int vn) {
            this.vn = vn;
            es = new ArrayList[vn];
            for (int i = 0; i < vn; i++) {
                es[i] = new ArrayList<Edge>();
            }
        }

        void addEdge(int s, int t, int c) {
            Edge e = new Edge(s, t, c);
            Edge erev = new Edge(t, s, 0);
            e.r = erev;
            erev.r = e;
            es[s].add(e);
            es[t].add(erev);
        }

        boolean[] u;

        int bfs(int s, int t) {
            int[] q = new int[vn];
            boolean[] u = new boolean[vn];
            Edge[] from = new Edge[vn];
            int hd = 0;
            int tl = 1;
            q[hd] = s;
            u[s] = true;
            while (hd < tl) {
                int x = q[hd++];
                for (Edge e : es[x]) {
                    if (e.f < e.c && !u[e.t]) {
                        u[e.t] = true;
                        q[tl++] = e.t;
                        from[e.t] = e;
                    }
                }
            }
            if (u[t]) {
                int cur = t;
                while (cur != s) {
                    from[cur].f++;
                    from[cur].r.f--;
                    cur = from[cur].s;
                }
                return 1;
            } else {
                return 0;
            }
        }

        int maxFlow(int s, int t) {
            u = new boolean[vn];
            flow = 0;
            while (true) {
                Arrays.fill(u, false);
                int df = bfs(s, t);
                if (df > 0) {
                    flow += df;
                } else {
                    break;
                }
            }
            return flow;
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine() + " $");
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}