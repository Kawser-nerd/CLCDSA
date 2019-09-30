import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int Tz = cin.nextInt();
    for(int C=1; C<=Tz; ++C) {

      int N = cin.nextInt();

      double V = cin.nextDouble();
      double T = cin.nextDouble();

      double amount = 0;

      List<Source> low = new ArrayList<Source>();
      List<Source> hi = new ArrayList<Source>();

      for(int i=0; i<N; ++i) {
        double v = cin.nextDouble();
        double t = cin.nextDouble();
        if( t == T ) { amount += v; }
        if( t < T ) {
          low.add(new Source(T - t, v));
        }
        if( t > T ) {
          hi.add(new Source(t - T, v));
        }
      }

      Collections.sort(low);
      Collections.sort(hi);

      int lp = 0;
      int hp = 0;

      double lused = 0;
      double hused = 0;

      while( lp < low.size() && hp < hi.size() ) {

        Source L = low.get(lp);
        Source H = hi.get(hp);

        // use H all;
        if( (L.v - lused) * L.diff > (H.v - hused) * H.diff ) {
          double luse = (H.v - hused) * H.diff / L.diff;
          double huse = H.v - hused;
          amount += (luse + huse);
          lused += luse;
          hused = 0;
          ++hp;
        }

        else {
          double luse = L.v - lused;
          double huse = (L.v - lused) * L.diff / H.diff;
          amount += (luse + huse);
          lused = 0;
          ++lp;
          hused += huse;
        }

      }

      String res = "IMPOSSIBLE";

      if( amount > 0 ) { res = "" + (V / amount); }

      System.out.println("Case #" + C + ": " + res);

    }

  }

  class Source implements Comparable<Source> {

    double diff;
    double v;

    Source(double diff, double v) {
      this.diff = diff;
      this.v = v;
    }

    public int compareTo(Source s) {
      if( diff < s.diff ) { return -1; }
      if( diff > s.diff ) { return 1; }
      return 0;
    }

  }

}
