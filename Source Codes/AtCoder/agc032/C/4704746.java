import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C1 solver = new C1();
        solver.solve(1, in, out);
        out.close();
    }

    static class C1 {
        List<Edge>[] g;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.ni(), m = in.ni();

            g = new List[n];
            for (int i = 0; i < n; i++) {
                g[i] = new LinkedList<>();
            }
            int[] degree = new int[n];
            for (int i = 0; i < m; i++) {
                int from = in.ni() - 1, to = in.ni() - 1;
                g[from].add(new Edge(from, to, i));
                g[to].add(new Edge(to, from, i));
                degree[from]++;
                degree[to]++;
            }
            LinkedList<Integer> degree4 = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                if (degree[i] % 2 == 1) {
                    out.println("No");
                    return;
                }
            }
            for (int i = 0; i < n; i++) {
                if (degree[i] >= 6) {
                    out.println("Yes");
                    return;
                }
                if (degree[i] == 4) {
                    degree4.add(i);
                }
            }
            if (degree4.size() > 2) {
                out.println("Yes");
                return;
            }
            if (degree4.size() < 2) {
                out.println("No");
                return;
            }
            int from = degree4.getFirst();
            int to = degree4.getLast();
            boolean circle = false;
            for (Edge edge : g[from]) {
                int prev = from;
                int cur = edge.to;
//            System.out.println("edge.to = " + edge.to);
                while (cur != from && cur != to) {
                    for (Edge e : g[cur]) {
                        if (e.to != prev) {
                            prev = cur;
                            cur = e.to;
                            break;
                        }
                    }
                }
//            System.out.println("cur = " + cur);
                if (cur == from) {
                    circle = true;
                    break;
                }
            }
            if (circle) {
                out.println("Yes");
            } else
                out.println("No");


        }

        class Edge {
            int from;
            int to;
            int id;

            public Edge(int from, int to, int id) {
                this.from = from;
                this.to = to;
                this.id = id;
            }

        }

    }

    static class FastScanner {
        private BufferedReader in;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            in = new BufferedReader(new InputStreamReader(stream));
        }

        public String ns() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String rl = in.readLine();
                    if (rl == null) {
                        return null;
                    }
                    st = new StringTokenizer(rl);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int ni() {
            return Integer.parseInt(ns());
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.