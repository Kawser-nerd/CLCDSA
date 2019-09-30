import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] dp = new int[n];
        dp[0] = 0;
        dp[1] = Math.abs(a[0] - a[1]);
        for(int i = 2; i < n; i++) {
            dp[i] = Math.min(dp[i-1] + Math.abs(a[i] - a[i-1]), dp[i-2] + Math.abs(a[i] - a[i-2]));
        }
        System.out.println(dp[n-1]);
    }
}