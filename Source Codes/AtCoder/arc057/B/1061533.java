import java.util.Scanner;
import java.util.Arrays;
public class Main{
  public static void main(String[] args){
    new Main().solve();
  }

  public void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long K = sc.nextLong();
    int[] a = new int[N+1];
    long[] sum = new long[N+1];
    for(int i=1; i<a.length; i++){
      a[i] = sc.nextInt();
      sum[i] = sum[i-1] + a[i];
    }
    long[][] dp = new long[N+1][N+1];
    for(long[] v : dp) Arrays.fill(v, Long.MAX_VALUE);

    //dynamic programing
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int j=1; j<N; j++){
      for(int i=0; i<=j; i++){
        if(dp[j][i] < Long.MAX_VALUE){
          dp[j+1][i] = Math.min(dp[j][i], dp[j+1][i]); //????
          long temp = dp[j][i]*a[j+1]/sum[j]+1;
          if(temp <= a[j+1]) dp[j+1][i+1] = Math.min(dp[j][i]+temp, dp[j+1][i+1]); //?????
        }
      }
    }

    if(sum[N] == K){
      System.out.println("1");
    }else{
      int max = 0;
      for(int i=0; i<dp[N].length; i++){
        if(dp[N][i] <= K) max = Math.max(max,i);
      }
      System.out.println(max);
    }

  }
}