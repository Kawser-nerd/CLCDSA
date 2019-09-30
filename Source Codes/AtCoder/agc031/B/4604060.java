import java.util.HashMap;
import java.util.Scanner;

class Problem {
    private int N;
    private int[] C;
    private final int MOD = (int) 1e9 + 7;

    Problem() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        C = new int[N];
        for (int i = 0; i < N; i++) {
            C[i] = sc.nextInt();
        }
    }

    int solve() {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] dp = new int[N];

        dp[N - 1] = 1;
        map.put(C[N-1], N-1);

        for (int i = N - 2; i >= 0; i--) {
            int n = map.getOrDefault(C[i], -1);
            if (n > i + 1) {
                dp[i] = (dp[i+1] + dp[n]) % MOD;
            } else {
                dp[i] = dp[i+1];
            }
            map.put(C[i], i);
        }
        return dp[0];
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println(new Problem().solve());
    }
}