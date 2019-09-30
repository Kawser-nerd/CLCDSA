import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long X = sc.nextLong();
        long A = N + ans(N - X, X);
        System.out.println(A);
    }

    long ans(long a, long b) {
        if (a == 0) {
            return -b;
        }
        return 2 * (b / a) * a + ans(b % a, a);
    }
}