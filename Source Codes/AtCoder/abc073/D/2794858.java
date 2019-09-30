import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private int[][] dist;
    private List<Integer> r = new ArrayList<>();

    private int ans = Integer.MAX_VALUE / 2;

    private void solve(Scanner sc) {
        /*
         * ??????????
         */
        int N = sc.nextInt();
        dist = new int[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    dist[i][j] = Integer.MAX_VALUE / 2;
                }
            }
        }
        int M = sc.nextInt();
        int R = sc.nextInt();
        for (int i = 0; i < R; ++i) {
            r.add(sc.nextInt() - 1);
        }

        for (int i = 0; i < M; ++i) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int c = sc.nextInt();
            if (dist[a][b] > c) {
                dist[a][b] = dist[b][a] = c;
            }
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        dfs(new HashSet<>(), -1, 0);

        _out.println(ans);
    }
    private void dfs(Set<Integer> set, int p, int d) {
        if (set.size() >= r.size()) {
            if (d < ans) {
                ans = d;
            }
            return;
        }

        for (int t : r) {
            if (set.contains(t)) {
                continue;
            }
            set.add(t);
            if (p < 0) {
                dfs(set, t, d);
            } else {
                dfs(set, t, d + dist[p][t]);
            }
            set.remove(t);
        }
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();

        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}