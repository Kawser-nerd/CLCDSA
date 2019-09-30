import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  double ans;

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int Y = cin.nextInt();
      int N = cin.nextInt();

      int pos[] = new int[N];
      for(int i=0; i<N; ++i) {
        pos[i] = cin.nextInt();
      }

      int S[] = new int[N];
      for(int i=0; i<N; ++i) {
        S[i] = cin.nextInt();
      }

      ans = Double.MAX_VALUE;
      solve(0, Y, 0, new boolean[N], pos, S, 0, N);

      System.out.println("Case #" + C + ": " + ans);

    }

  }

  void solve(double self, int Y, double time, boolean used[], int pos[], int S[], int count, int N) {

    if( count == N ) {
      ans = Math.min(ans, time);
      return;
    }

    double Lmin = Double.MAX_VALUE;
    double Rmin = Double.MAX_VALUE;

    int Lindex = -1;
    int Rindex = -1;

    for(int i=0; i<N; ++i) {
      if( used[i] ) { continue; }
      // go left;
      if( pos[i] < 0 ) {
        double Lcand = (self - (pos[i] - time * S[i])) / (Y - S[i]);
        if( Lcand < Lmin ) {
          Lmin = Lcand;
          Lindex = i;
        }
      }
      else {
        double Rcand = ((pos[i] + time * S[i]) - self) / (Y - S[i]);
        if( Rcand < Rmin ) {
          Rmin = Rcand;
          Rindex = i;
        }
      }
    }

    if( Lindex >= 0 ) {
      used[Lindex] = true;
      solve(self - Lmin * Y, Y, time + Lmin, used, pos, S, count + 1, N);
      used[Lindex] = false;
    }

    if( Rindex >= 0 ) {
      used[Rindex] = true;
      solve(self + Rmin * Y, Y, time + Rmin, used, pos, S, count + 1, N);
      used[Rindex] = false;
    }

  }

}
