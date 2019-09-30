import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            new Main().solve(in);
        }
    }

    private void solve(Scanner in) {
        int N = in.nextInt(), K = in.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = in.nextInt();
        }
        java.util.Arrays.sort(a);

        int from = -1;
        int to = N;
        while (from + 1 < to) {
            int n = (to + from) / 2;
            if (a[n] >= K) {
                to = n;
                continue;// necessary
            }
            boolean[][] dp = new boolean[N + 1][K];
            dp[0][0] = true;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < K; j++) {
                    if (n != i && a[i] + j < K) {
                        dp[i + 1][a[i] + j] |= dp[i][j];
                    }
                    dp[i + 1][j] |= dp[i][j];
                }
            }
            boolean nece = false;
            for (int j = K - a[n]; j < K; j++) {
                if (dp[N][j]) {
                    nece = true;
                    break;
                }
            }
            if (nece) {
                to = n;
            } else {
                from = n;
            }
        }
        int ans = to;
        System.out.println(ans);
    }
}