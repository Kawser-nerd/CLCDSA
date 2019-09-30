package gcj2015.round2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B1 {

    static final double EPS = 1e-10;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = in.nextInt();
        for (int cs = 1 ; cs <= t ; cs++) {
            int n = in.nextInt();
            double v = in.nextDouble();
            double x = in.nextDouble();
            double[][] source = new double[n][2];
            for (int i = 0; i < n ; i++) {
                source[i][0] = in.nextDouble();
                source[i][1] = in.nextDouble();
            }
            out.println(String.format("Case #%d: %s", cs, solve(v, x, source)));
        }

        out.flush();
    }

    private static String solve(double V, double X, double[][] source) {
        int n = source.length;
        double best = Double.MAX_VALUE;

        double sumRate = 0;
        for (int i = 0 ; i < n ; i++) {
            if (source[i][1] - EPS <= X && X <= source[i][1] + EPS) {
                sumRate += source[i][0];
            }
        }
        if (sumRate > 0) {
            best = Math.min(best, V / sumRate);
        }

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (i == j) {
                    continue;
                }
                double min = Math.min(source[i][1], source[j][1]);
                double max = Math.max(source[i][1], source[j][1]);
                if (min - EPS <= X && X <= max + EPS) {
                } else {
                    continue;
                }

                double fr = 0;
                double to = V / source[i][0];
                double lastTime = 0;
                double lastTemp = 0;
                for (int k = 0; k < 500 ; k++) {
                    double med = (fr + to) / 2;
                    double left = V - med * source[i][0];
                    double doubleTime = left / (source[i][0] + source[j][0]);
                    double amountI = (med + doubleTime) * source[i][0];
                    double amountJ = V - amountI;
                    lastTime = med + doubleTime;

                    double temp = (amountI * source[i][1] + amountJ * source[j][1]) / V;
                    lastTemp = temp;

                    if (temp < X) {
                        if (source[i][1] > source[j][1]) {
                            fr = med;
                        } else {
                            to = med;
                        }
                    } else {
                        if (source[i][1] < source[j][1]) {
                            fr = med;
                        } else {
                            to = med;
                        }
                    }
                }
                if (Math.abs(X - lastTemp) <= EPS) {
                    best = Math.min(best, lastTime);
                }
            }
        }

        return best >= Double.MAX_VALUE ? "IMPOSSIBLE" : String.format("%f", best);
    }

    static class UnionFind {
        int[] parent, rank;
        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0 ; i < n ; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int x) {
            if (parent[x] == x) {
                return x;
            }
            parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return;
            }
            if (rank[x] < rank[y]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }
        boolean issame(int x, int y) {
            return (find(x) == find(y));
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}



