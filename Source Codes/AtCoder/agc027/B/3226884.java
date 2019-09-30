import java.util.*;

public class Main {

    int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long X = sc.nextLong();
        long[] x = new long[N];
        long[] xsum = new long[N + 1];
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
            xsum[i + 1] = xsum[i] + x[i];
        }
        long ans = X * N + 5 * xsum[N];
        for (int i = 1; i < N; i++) {
            long cost = X * i + 5 * (xsum[N] - xsum[N - i]);
            for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
                if (cost > ans) {
                    break;
                }
                cost += j * (xsum[k] - xsum[Math.max(k - i, 0)]);
            }
            ans = Math.min(ans, cost);
        }
        System.out.println(ans + N * X);
    }
}