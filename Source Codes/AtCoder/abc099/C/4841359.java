import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Set<Integer> candidates = new TreeSet<>();

        long tmp = 1;
        while (tmp <= N) {
            candidates.add((int) tmp);
            tmp *= 6;
        }

        tmp = 1;
        while (tmp <= N) {
            candidates.add((int) tmp);
            tmp *= 9;
        }

        int INF = 1_000_000;
        int dp[] = new int[N + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int n : candidates) {
                if (i >= n) {
                    dp[i] = Math.min(dp[i], dp[i - n] + 1);
                }
            }
        }

        out.println(dp[N]);
    }
}