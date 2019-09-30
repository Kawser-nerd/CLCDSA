import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] x = new int[M];
    int[] y = new int[M];
    ArrayList[] edge = new ArrayList[N];
    for(int i = 0; i < N; i++) {
      edge[i] = new ArrayList();
    }
    for(int i = 0; i < M; i++) {
      x[i] = sc.nextInt() - 1;
      y[i] = sc.nextInt() - 1;
      edge[x[i]].add(y[i]);
    }
    long[] dp = new long[(int)Math.pow(2, N)];
    dp[0] = 1;
    for(int i = 1; i < (int)Math.pow(2, N); i++) {
      for(int j = 0; j < N; j++) {
        if((i & (1 << j)) != 0) {
          boolean flg = true;
          for(int k = 0; k < N; k++) {
            if((i & (1 << k)) != 0 && edge[j].contains(k)) flg = false; 
          }
          if(flg) dp[i] += dp[i - (1 << j)]; 
        }
      }
    }
    System.out.println(dp[(int)Math.pow(2, N) - 1]);
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.