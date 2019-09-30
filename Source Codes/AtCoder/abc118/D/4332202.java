import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    private static final int[] DIGIT_TO_MATCHES = new int[]{0, 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6 };

    public static void main(final String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] arr = new int[m];
        for (int i = 0; i < m; i++) {
            arr[i] = in.nextInt();
        }
        BigInteger[] dp = new BigInteger[n + 1];
        dp[0] = BigInteger.ZERO;
        for (int i = 0; i < n; i++) {
            if (dp[i] == null) {
                continue;
            }
            for (int j : arr) {
                int matches = DIGIT_TO_MATCHES[j];
                if (i + matches > n) {
                    continue;
                }
                BigInteger next = dp[i].multiply(BigInteger.TEN).add(BigInteger.valueOf(j));
                if (dp[i + matches] == null || dp[i + matches].compareTo(next) < 0) {
                    dp[i + matches] = next;
                }
            }
        }
        System.out.println(dp[n]);
    }
}