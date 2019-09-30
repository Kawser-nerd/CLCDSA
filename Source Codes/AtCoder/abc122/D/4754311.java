import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mod = 1000000007;
        int[][][][] dp = new int[101][4][4][4];
        dp[0][3][3][3] = 1;
        for(int len = 0; len < n; len++) {
            for(int c1 = 0; c1 < 4; c1++) {
                for(int c2 = 0; c2 < 4; c2++) {
                    for(int c3 = 0; c3 < 4; c3++) {
                        if(dp[len][c1][c2][c3] == 0) continue;
                        for(int newC = 0; newC < 4; newC++) {
                            if(newC == 2 && c1 == 1 && c2 == 0) continue;
                            if(newC == 2 && c1 == 0 && c2 == 1) continue;
                            if(newC == 1 && c1 == 2 && c2 == 0) continue;
                            if(newC == 2 && c1 == 1 && c3 == 0) continue;
                            if(newC == 2 && c2 == 1 && c3 == 0) continue;

                            dp[len + 1][newC][c1][c2] += dp[len][c1][c2][c3];
                            dp[len + 1][newC][c1][c2] %= mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int c1 = 0; c1 < 4; c1++) {
            for (int c2 = 0; c2 < 4; c2++) {
                for (int c3 = 0; c3 < 4; c3++) {
                    ans += dp[n][c1][c2][c3];
                    ans %= mod;
                }
            }
        }
        System.out.println(ans);
    }
}