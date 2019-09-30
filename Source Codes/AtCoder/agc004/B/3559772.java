import java.util.Scanner;

public class Main {
    static int n;
    static long x;
    static long[][] dp;
    static long[] a;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        x = sc.nextInt();
        a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        dp = new long[n][n];
        for (int i = 0; i < n; i++) {
            dp[0][i] = a[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = Math.min(dp[i-1][(n+j-1)%n], dp[i-1][j]);
            }
        }

        long ret = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            long sum = 0;
            for (int j = 0; j < n; j++) {
                sum += dp[i][j];
            }
            ret = Math.min(ret, sum+x*i);
        }

        System.out.println(ret);
    }
}