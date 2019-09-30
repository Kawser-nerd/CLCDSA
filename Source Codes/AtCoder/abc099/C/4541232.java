import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static int[] dp = new int[0];

    public static void main(String[] args) {
        int N = sc.nextInt();
        dp = new int[N+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        calc(N);
        System.out.println(dp[N]);
    }

    private static void calc(int n) {
        for (int i = 1; i <= n; i++) {
            int power = 1;
            int ans = Integer.MAX_VALUE;
            while (0 <= i - power) {
                ans = Math.min(ans, 1 + dp[i - power]);
                power *= 6;
            }

            power = 1;
            while (0 <= i - power) {
                ans = Math.min(ans, 1 + dp[i - power]);
                power *= 9;
            }
            dp[i] = ans;
        }
    }
}