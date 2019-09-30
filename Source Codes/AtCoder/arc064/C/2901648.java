import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Cord S;
    static Cord E;
    static int N;
    static Circle[] C;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        S = new Cord(sc.nextInt(), sc.nextInt());
        E = new Cord(sc.nextInt(), sc.nextInt());
        N = sc.nextInt();
        C = new Circle[N];
        for (int i = 0; i < N; i++) {
            C[i] = new Circle(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }

        System.out.println(BigDecimal.valueOf(solve()).toPlainString());
    }

    static class Edge {
        int a;
        int b;
        double cost;

        public Edge(int a, int b, double cost) {
            this.a = a;
            this.b = b;
            this.cost = cost;
        }
    }

    static class Cord {
        final int x;
        final int y;

        public Cord(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public double dist(Cord to) {
            return Point2D.distance(x, y, to.x, to.y);
        }
    }

    static class Circle {
        Cord c;
        int r;

        public Circle(int x, int y, int r) {
            this.c = new Cord(x, y);
            this.r = r;
        }
    }

    static double solve() {
        // circle: [0, N-1]
        // start: N
        // end: N+1
        List<Edge>[] rin = new List[N+2];
        for (int i = 0; i < N+2; i++) {
            rin[i] = new ArrayList<>(N+10);
        }
        Edge st = new Edge(N, N+1, S.dist(E));
        rin[N].add(st);
        rin[N+1].add(st);

        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                Circle c1 = C[i];
                Circle c2 = C[j];

                double cost = Math.max(0, c1.c.dist(c2.c) - (c1.r + c2.r));
                Edge e = new Edge(i, j, cost);
                rin[i].add(e);
                rin[j].add(e);
            }
        }
        for (int i = 0; i < N; i++) {
            Circle c = C[i];
            double cost_sc = Math.max(0, c.c.dist(S) - c.r);
            Edge sc = new Edge(i, N, cost_sc);
            rin[i].add(sc);
            rin[N].add(sc);

            double cost_se = Math.max(0, c.c.dist(E) - c.r);
            Edge se = new Edge(i, N+1, cost_se);
            rin[i].add(se);
            rin[N+1].add(se);
        }

        PriorityQueue<State> q = new PriorityQueue<>();
        double[] dist = new double[N+2];
        Arrays.fill(dist, Double.NaN);

        q.add( new State(N, 0.0) );
        dist[N] = 0.0;

        while(!q.isEmpty()) {
            State s = q.poll();

            if( dist[s.a] != s.cost ) continue;

            for (Edge e : rin[s.a]) {
                int next = s.a == e.a ? e.b : e.a;
                double nextCost = s.cost + e.cost;

                if( Double.isNaN(dist[next]) || dist[next] > nextCost ) {
                    q.add(new State(next, nextCost));
                    dist[next] = nextCost;
                }
            }
        }

        return dist[N+1];
    }

    static class State implements Comparable<State> {
        int a;
        double cost;

        public State(int a, double cost) {
            this.a = a;
            this.cost = cost;
        }

        @Override
        public int compareTo(State o) {
            return Double.compare(cost, o.cost);
        }
    }



    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.