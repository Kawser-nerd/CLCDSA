import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        final int mod = 1_000_000_007;
        
        long[][][][] dp = new long[110][5][5][5];
        dp[0][0][0][0] = 1;
        for (int i = 0 ; i < n ; i++) {
            for (int a = 0 ; a < 5 ; a++) {
                for (int b = 0 ; b < 5 ; b++) {
                    for (int c = 0 ; c < 5 ; c++) {
                        for (int d = 1 ; d <= 4; d++) {
                            if (b == 1 && c == 3 && d == 2) continue;
                            if (a == 1 && c == 3 && d == 2) continue;
                            if (b == 3 && c == 1 && d == 2) continue;
                            if (b == 1 && c == 2 && d == 3) continue;
                            if (a == 1 && b == 3 && d == 2) continue;
                            dp[i+1][b][c][d] = (dp[i+1][b][c][d] + dp[i][a][b][c]) % mod;
                        }
                    }
                }
            }
        }
        long ans = 0;
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                for (int c = 0; c < 5; c++) {
                    ans = (ans + dp[n][a][b][c]) % mod;
                }
            }
        }
        System.out.println(ans);
    }


}