import java.util.*;

public class Main {

    int[] a;
    int cost;
    int N;
    int[] dp;
    int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N];
        int M = 0;
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            M = Math.max(M, A[i]);
        }
        long g = A[0];
        for (int i = 1; i < N; i++) {
            g = gcd(g, A[i]);
        }
        if (K % g == 0 && K <= M) {
            System.out.println("POSSIBLE");
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }

    long gcd(long n, long m) {
        if (n < m) {
            return gcd(m, n);
        }
        if (m == 0) {
            return n;
        }
        return gcd(m, n % m);
    }
}