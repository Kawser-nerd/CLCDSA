import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long W = sc.nextLong();
    long[] v = new long[N];
    long[] w = new long[N];
    boolean flg = true;
    for(int i = 0; i < N; i++) {
      v[i] = sc.nextLong();
      w[i] = sc.nextLong();
      if(w[i] > 1000) flg = false;
    }
    long ans = 0;
    if(N <= 30) {
      if(N == 1) {
        if(w[0] <= W) ans = v[0];
      } else {
        int m = N / 2;
        ArrayList<long[]> A = new ArrayList<long[]>();
        ArrayList<long[]> B = new ArrayList<long[]>();
        for(int i = 0; i < (int)Math.pow(2, m); i++) {
          long vt = 0;
          long wt = 0;
          for(int j = 0; j < m; j++) {
            if((i & (1 << j)) != 0) {
              vt += v[j];
              wt += w[j];
            }
          }
          long[] x = {vt, wt};
          A.add(x);
        }
        for(int i = 0; i < (int)Math.pow(2, N - m); i++) {
          long vt = 0;
          long wt = 0;
          for(int j = 0; j < N - m; j++) {
            if((i & (1 << j)) != 0) {
              vt += v[j + m];
              wt += w[j + m];
            }
          }
          long[] x = {vt, wt};
          B.add(x);          
        }
        Collections.sort(A, new Comparator<long[]>() {
                         public int compare(long[] a, long[] b) {
                           if(a[1] > b[1]) {
                             return 1;
                           } else if(a[1] < b[1]) {
                             return -1;
                           } else {
                             if(a[0] > b[0]) {
                               return 1;
                             } else if(a[0] < b[0]) {
                               return -1;
                             } else {
                               return 0;
                             }
                           }
                         }
                       });
        Collections.sort(B, new Comparator<long[]>() {
                         public int compare(long[] a, long[] b) {
                           if(a[1] > b[1]) {
                             return 1;
                           } else if(a[1] < b[1]) {
                             return -1;
                           } else {
                             if(a[0] > b[0]) {
                               return 1;
                             } else if(a[0] < b[0]) {
                               return -1;
                             } else {
                               return 0;
                             }
                           }
                         }
                       });
        
        ArrayList<long[]> alist = new ArrayList<long[]>();
        ArrayList<long[]> blist = new ArrayList<long[]>();
        long temp = 0;
        long temp2 = 0;
        for(int i = 0; i < A.size(); i++) {
          long[] x = A.get(i);
          if(x[0] >= temp) {
            temp = x[0];
            alist.add(x);
          }
        }
        for(int i = 0; i < B.size(); i++) {
          long[] x = B.get(i);
          if(x[0] >= temp2) {
            temp2 = x[0];
            blist.add(x);
          }          
        } 
        for(int i = 0; i < blist.size(); i++) {
          long[] x = blist.get(i);
          long vt = x[0];
          long wt = x[1];
          if(wt <= W) {
            int left = 0;
            int right = alist.size();
            while(left < right) {
              int med = (left + right) / 2;
              long[] y = alist.get(med);
              if(y[1] <= (W - wt)) {
                ans = Math.max(ans, vt + y[0]);
                left = med + 1;
              } else {
                right = med;
              }
            }
          }
        }      
      }
    } else if(flg) {
      // dp[i][j]?v0?vi???????j??????????????????????
      long[][] dp = new long[N][200 * 1000 + 1];
      for(int j = 0; j < 200 * 1000 + 1; j++) {
        if(j >= w[0]) dp[0][j] = v[0]; 
      }
      for(int i = 1; i < N; i++) {
        for(int j = 0; j < 200 * 1000 + 1; j++) {
          dp[i][j] = dp[i - 1][j];
          if(w[i] <= j) dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - (int)w[i]] + v[i]); 
        }
      }
      ans = dp[N - 1][200 * 1000];
      if(W < 200 * 1000) ans = dp[N - 1][(int)W];
    } else {
      // dp[i][j]?v0?vi???????j??????????????????????
      long[][] dp = new long[N][200 * 1000 + 1];
      for(int j = 0; j < 200 * 1000 + 1; j++) {
        if(j <= v[0]) {
          dp[0][j] = w[0];
        } else {
          dp[0][j] = Long.MAX_VALUE;
        }
      }
      for(int i = 1; i < N; i++) {
        for(int j = 0; j < 200 * 1000 + 1; j++) {
          if(j <= v[i]) {
            dp[i][j] = Math.min(dp[i - 1][j], w[i]);
          } else {
            if(dp[i - 1][j - (int)v[i]] == Long.MAX_VALUE) {
              dp[i][j] = Long.MAX_VALUE;
            } else {
              dp[i][j] = Math.min(dp[i - 1][j], dp[i - 1][j - (int)v[i]] + w[i]);
            }
          }
        }
      }
      for(int j = 200 * 1000; j >= 0; j--) {
        if(dp[N - 1][j] <= W) {
          ans = j;
          break;
        }
      }
    }
    System.out.println(ans);
  }
}