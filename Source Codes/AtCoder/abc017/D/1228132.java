import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long MOD = 1000000007;
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] f = new int[N];
    for(int i = 0; i < N; i++) {
      f[i] = sc.nextInt() - 1;
    }
    // dp[i]???????i?????????????
    long[] dp = new long[N];
    // s[i]=dp[0]+dp[1]+...+dp[i]
    long[] s = new long[N];
    dp[0] = 1;
    s[0] = 1;
    int[] num = new int[M];
    num[f[0]]++;
    int start = 0;
    int end = 1;
    while(end < N) {
      if(num[f[end]] == 0) {
        num[f[end]]++;
        long a = 0;
        if(start == 0) a = 1 + s[end - 1];
        if(start == 1) a = s[end - 1];
        if(start > 1) {
          if(s[end - 1] >= s[start - 2]) {
            a = s[end - 1] - s[start - 2];
          } else {
            a = s[end - 1] - s[start - 2] + MOD;
          }
        }
        s[end] = (s[end - 1] + a) % MOD;
        if(s[end] >= s[end - 1]) {
          dp[end] = s[end] - s[end - 1];
        } else {
          dp[end] = s[end] - s[end - 1] + MOD;
        }
        end++;
      } else {
        num[f[start]]--;
        start++;
      }
    }
    System.out.println(dp[N - 1]);
  }
}