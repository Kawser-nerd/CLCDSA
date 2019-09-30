import java.util.*;

public class A {

  String solve(Scanner sc) {
    int N = sc.nextInt();
    int[] dp = new int[N+1];
    dp[1] = 1;
    for(int i = 2; i <= N; i++) {
      dp[i] = Integer.MAX_VALUE;
    }
    for(int i = 1; i < N; i++) {
      dp[i+1] = Math.min(dp[i+1], dp[i] + 1);
      int r = reverse(i);
      if(r <= N) {
        dp[r] = Math.min(dp[r], dp[i] + 1);
      }
    }
    
    return "" + dp[N];
  }
  
  int reverse(int N) {
    int r = 0;
    while(N > 0) {
      r *= 10;
      r += N % 10;
      N /= 10;
    }
    return r;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int T = sc.nextInt();
    for(int cs = 1; cs <= T; cs++) {
      String res = new A().solve(sc);
      System.out.println("Case #" + cs + ": " + res);
    }
    
    sc.close();
  }
  
}
