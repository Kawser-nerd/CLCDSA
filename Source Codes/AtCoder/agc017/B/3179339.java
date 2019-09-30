import java.util.*;

public class Main {

    int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextInt();
        long A = sc.nextInt();
        long B = sc.nextInt();
        long C = sc.nextInt();
        long D = sc.nextInt();
        for (int k = 0; k <= N; k++) {
            if (((k * C - (N - 1 - k) * D) <= (B - A)) && ((B - A) <= (k * D - (N - 1 - k) * C))) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}