import java.util.Scanner;

public class Consonant {

    private static void out(int t, String ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
        return;
    }

    private static boolean isBoin(char c) {
        return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            String s = scanner.next();
            int len = scanner.nextInt();
            int n = s.length();
            int boin[] = new int[n];
            long dp[] = new long[n];
            int lastB = -1;
            for (int i = 0; i < n; i++) {
                if (isBoin(s.charAt(i))) {
                    lastB = i;
                }
                boin[i] = lastB;
            }
            long res = 0;
            for (int i = 0; i < n; i++) {
                if (i < len - 1) {
                    continue;
                }
                if (i - boin[i] >= len) {
                    dp[i] = (i - len + 2);
                } else {
                    if (boin[i] > 0) {
                        dp[i] = dp[boin[i] - 1];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                res += dp[i];
            }
            out(t, "" + res);
        }
    }
}
