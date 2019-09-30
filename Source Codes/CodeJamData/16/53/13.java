package gcj.gcj2016.round3;

import java.io.PrintWriter;
import java.util.*;

/**
 * Created by hama_du on 2016/06/10.
 */
public class C1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = in.nextInt();
        for (int cs = 1 ; cs <= t ; cs++) {
            int n = in.nextInt();
            int s = in.nextInt();
            int[][] ast = new int[n][6];
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < 6 ; j++) {
                    ast[i][j] = in.nextInt();
                }
            }
            out.println(String.format("Case #%d: %.9f", cs, solve(ast, s)));
        }
        out.flush();
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }


    private static double solve(int[][] ast, double S) {
        S = 1e10;
        int n = ast.length;
        double[][] dist = new double[n][n];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                int d2 = 0;
                for (int di = 0; di < 3 ; di++) {
                    int d = Math.abs(ast[i][di] - ast[j][di]);
                    d2 += d * d;
                }
                dist[i][j] = Math.sqrt(d2);
            }
        }
//        debug(dist);


        Dijkstra dijkstra = new Dijkstra(dist);

        double min = 0;
        double max = 2500;
        for (int c = 0 ; c < 30 ; c++) {
            double med = (min + max) / 2;
            if (dijkstra.isOK(0, 1, med, S)) {
                max = med;
            } else {
                min = med;
            }
        }
        return max;
    }

    static class Dijkstra {
        int n;
        double[][] graph;

        class State implements Comparable<State> {
            int now;
            double time;

            State(int n, double t) {
                now = n;
                time = t;
            }

            @Override
            public int compareTo(State o) {
                return Double.compare(time, o.time);
            }
        }

        public Dijkstra(double[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        boolean isOK(int from, int to, double limit, double S) {
            double[] dp = new double[n];
            Arrays.fill(dp, 1e18);
            Queue<State> q = new PriorityQueue<>();
            q.add(new State(from, 0));
            dp[0] = 0;
            while (q.size() >= 1) {
                State st = q.poll();
                if (dp[st.now] < st.time) {
                    continue;
                }
                for (int j = 0 ; j < n ; j++) {
                    if (graph[st.now][j] > limit) {
                        continue;
                    }
                    double time = st.time + graph[st.now][j];
                    if (time > S) {
                        continue;
                    }
                    if (dp[j] > time) {
                        dp[j] = time;
                        q.add(new State(j, time));
                        if (j == to) {
                            return true;
                        }
                    }
                }
            }
            return dp[to] <= S;
        }
    }
}
