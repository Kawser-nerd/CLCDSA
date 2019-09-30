import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  double solve(String s) {

    int N = s.length();
    int state = 0;
    for(int i=0; i<N; ++i) {
      if( s.charAt(i) == '.' ) { state |= 1 << i; }
    }

    int max = 1 << N;
    double dp[] = new double[max];

    for(int i=1; i<max; ++i) {
      double add = 0;
      for(int j=0; j<N; ++j) {
        int k = 0;
        while( (i & (1 << ((j + k) % N))) == 0 ) { ++k; }
        add += N - k;
        add += dp[i ^ (1 << ((j + k) % N))];
      }
      dp[i] = add / N;
    }

    return dp[state];

  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      String s = cin.next();
      System.out.println("Case #" + C + ": " + solve(s));

    }

  }

}
