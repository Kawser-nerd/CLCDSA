import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  double solve(long B, int N, long arr[]) {

    double ret = 0.0;
    Arrays.sort(arr);

    // num of winners;
    for(int i=1; i<=37; ++i) {

      long hi = Long.MAX_VALUE / 1000;
      long lo = arr[i - 1];

      for(int j=0; j<100; ++j) {

        long mid = (hi + lo) / 2;
        if( valid(B, i, arr, mid) ) {
          lo = mid;
          ret = Math.max(ret, score(B, i, arr, mid));
        }
        else {
          hi = mid;
        }

      }

    }

    return ret;

  }

  double score(long B, int K, long arr[], long req) {

    long use = count(B, K, arr, req);

    double pay = 0;

    for(int i=0; i<K; ++i) {
      pay += (req - arr[i]);
    }

    pay *= 36;
    pay /= K;
    return pay - use;

  }

  long count(long B, int K, long arr[], long req) {

    long use = 0;

    for(int i=0; i<37; ++i) {
      if( i < K ) {
        use += (req - arr[i]);
      }
      else {
        if( arr[i] < req + 1 ) {
          use += (req + 1 - arr[i]);
        }
      }
    }

    return use;

  }

  boolean valid(long B, int K, long arr[], long req) {
    long use = count(B, K, arr, req);
    if( use > B ) { return false; }
    return true;
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      long B = cin.nextLong();
      int N = cin.nextInt();

      long arr[] = new long[37];
      for(int i=0; i<N; ++i) { arr[i] = cin.nextLong(); }

      System.out.println("Case #" + C + ": " + solve(B, N, arr));

    }

  }

}
