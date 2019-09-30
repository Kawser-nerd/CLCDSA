package r3;

import java.util.Scanner;

public class Dsmall {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    for(int cn = 1 ; cn <= N ; cn++){
      int W = sc.nextInt();
      int H = sc.nextInt();
      int R = sc.nextInt();
      boolean stone[][] = new boolean[W][H];
      for(int i = 0 ; i < R ; i++){
        int r = sc.nextInt();
        int c = sc.nextInt();
        stone[r - 1][c - 1] = true;
      }
      int mod = 10007;
      long dp[][] = new long[W][H];
      dp[0][0] = 1;
      for(int i = 0 ; i < W ; i++){
        for(int j = 0 ; j < H ; j++){
          if(i >= 1 && j >= 2){
            if(stone[i][j])continue;
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 2]) % mod;
          }
          if(i >= 2 && j >= 1){
            if(stone[i][j])continue;
            dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % mod;
          }          
        }
      }
      System.out.printf("Case #%d: %d\n", cn ,dp[W - 1][H - 1]);
    }
  }
}
