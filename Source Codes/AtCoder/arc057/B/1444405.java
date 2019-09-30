import java.util.Scanner;

public class Main{
  static int n, k;
  static int[] a;
  static final int INF = Integer.MAX_VALUE / 2;

  static final boolean DEBUG = false;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    k = sc.nextInt();
    a = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = sc.nextInt();
    }

    if(k == 0){
      System.out.println(0);
      return;
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
      sum += a[i];
    }

    if(sum == k){
      System.out.println(1);
      return;
    }

    int[][] dp = new int[n + 1][n + 1];
    for(int i = 2; i <= n; i++){
      dp[1][i] = INF;
    }
    dp[1][1] = 1;

    sum = a[0];
    for(int i = 2; i <= n; i++){
      for(int j = 0; j <= n; j++){
        dp[i][j] = dp[i - 1][j];
        if(j - 1 >= 0){
          int low = 0, high = a[i - 1] + 1;
          while(high - low > 1){
            int mid = (low + high) / 2;
            if(f(sum, dp[i - 1][j - 1], i - 1, mid)){
              high = mid;
            }
            else{
              low = mid;
            }
          }
          if(high <= a[i - 1] && f(sum, dp[i - 1][j - 1], i - 1, high)){
            dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + high);
          }
        }
      }
      sum += a[i - 1];
    }

    int ans = 0;
    for(int i = n; i >= 0; i--){
      if(dp[n][i] <= k){
        ans = i;
        break;
      }
    }

    System.out.println(ans);
  }

  static boolean f(long sum, long w, int index, long x){
    long sum1 = sum + a[index];
    long w1 = w + x;
    return w * sum1 < w1 * sum;
  }
}