import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i = 0; i < n; i++) a[i] = sc.nextLong();
        long[] dp = new long[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if(i + 1 < n){
                dp[i+1] = Math.min(dp[i+1], dp[i] + Math.abs(a[i+1] - a[i]));
            }
            if(i + 2 < n){
                dp[i+2] = Math.min(dp[i+2], dp[i] + Math.abs(a[i+2] - a[i]));
            }
        }

        System.out.println(dp[n-1]);
        sc.close();


    }

}