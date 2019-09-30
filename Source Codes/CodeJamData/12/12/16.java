import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  boolean check(int n, int req[][]) {
    int list[] = new int[n * 2];
    for(int i=0; i<n; ++i) {
      for(int j=0; j<2; ++j) {
        list[i * 2 + j] = req[i][j];
      }
    }
    Arrays.sort(list);
    for(int i=0; i<n+n; ++i) {
      if( list[i] > i ) { return false; }
    }
    return true;
  }

  String solve(int n, int req[][]) {
    if( !check(n, req) ) { return "Too Bad"; }
    Arrays.sort(req, new Comparator<int[]>() {
      public int compare(int a[], int b[]) {
        return a[1] - b[1];
      }
    });
    int cur = 0;
    int ret = 0;
    boolean used[] = new boolean[n];
    boolean pre[] = new boolean[n];
    int rest = n;
    while( rest > 0 && cur < n + n ) {
      boolean update = false;
      // greedy;
      for(int i=0; i<n; ++i) {
        if( used[i] ) { continue; }
        if( req[i][1] <= cur ) {
          cur += pre[i] ? 1 : 2;
          update = true;
          --rest;
          ++ret;
          used[i] = true;
        }
      }
      // re-greedy;
      if( update ) { continue; }
      // rev-greedy;
      for(int i=n-1; i>=0; --i) {
        if( used[i] || pre[i] ) { continue; }
        if( req[i][0] <= cur ) {
          ++cur;
          ++ret;
          pre[i] = true;
          break;
        }
      }
    }
    return "" + ret;
  }

  void solve() {

    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();

    for(int C=1; C<=T; ++C) {

      int n = cin.nextInt();
      int req[][] = new int[n][2];
      for(int i=0; i<n; ++i) {
        req[i][0] = cin.nextInt();
        req[i][1] = cin.nextInt();
      }

      System.out.println("Case #" + C + ": " + solve(n, req));

    }

  }

}
