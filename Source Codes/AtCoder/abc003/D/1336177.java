import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long MOD = (long)Math.pow(10, 9) + 7;
    int R = sc.nextInt();
    int C = sc.nextInt();
    int X = sc.nextInt();
    int Y = sc.nextInt();
    int D = sc.nextInt();
    int L = sc.nextInt();
    long[][] dp = new long[901][901];
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i < 901; i++) {
      dp[i][0] = 1;
      for(int j = 1; j <= i; j++) {
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
      }
    }
    long ans = 0;
    long a = dp[(X - 1) * Y][D + L];
    long b = dp[(Y - 1) * X][D + L];
    long c = dp[(X - 1) * Y][D + L];
    long d = dp[(Y - 1) * X][D + L];
    long ab = dp[(X - 1) * (Y - 1)][D + L];
    long ac = 0;
    if(X > 2) ac = dp[(X - 2) * Y][D + L];
    long ad = dp[(X - 1) * (Y - 1)][D + L];
    long bc = dp[(X - 1) * (Y - 1)][D + L];
    long bd = 0;
    if(Y > 2) bd = dp[(Y - 2) * X][D + L];
    long cd = dp[(X - 1) * (Y - 1)][D + L];
    long bcd = 0;
    if(Y > 2) bcd = dp[(Y - 2) * (X - 1)][D + L];
    long abd = bcd;
    long acd = 0;
    if(X > 2) acd = dp[(X - 2) * (Y - 1)][D + L];
    long abc = acd;
    long abcd = 0;
    if(X > 2 && Y > 2) abcd = dp[(X - 2) * (Y - 2)][D + L];
    long[] num = {a, b, c, d, abc, abd, acd, bcd, ab, ac, ad, bc, bd, cd, abcd};
    for(int i = 0; i < 8; i++) {
      ans = (ans + num[i]) % MOD;
    }
    for(int i = 8; i < 15; i++) {
      if(ans - num[i] >= 0) {
        ans -= num[i];
      } else {
        ans = ans + MOD - num[i]; 
      }
    }
    if(dp[X * Y][D + L] - ans >= 0) {
      ans = dp[X * Y][D + L] - ans;
    } else {
      ans = dp[X * Y][D + L] + MOD - ans;
    }
    ans = (ans * dp[D + L][D]) % MOD;
    long ans1 = 0;
    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        if((i + X - 1 < R) && (j + Y - 1 < C)) ans1 = (ans1 + ans) % MOD;
      }
    }
    System.out.println(ans1);
  }
}