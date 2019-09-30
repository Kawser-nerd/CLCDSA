import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int Row = cin.nextInt();
      int Col = cin.nextInt();
      int Num = cin.nextInt();

      System.out.println("Case #" + C + ": " + solve(Row, Col, Num));

    }

  }

  int solve(int R, int C, int N) {

    List<Integer> all = new ArrayList<Integer>();
    List<Integer> all2 = new ArrayList<Integer>();

    for(int i=0; i<R; ++i) {
      for(int j=0; j<C; ++j) {
        int wall = 0;
        if( i > 0 ) { ++wall; }
        if( j > 0 ) { ++wall; }
        if( i + 1 < R ) { ++wall; }
        if( j + 1 < C ) { ++wall; }
        if( (i + j) % 2 == 0 ) { all.add(wall); }
        else { all2.add(wall); }
      }
    }

    int ret = 0;

    Collections.sort(all);
    for( int i = 0; i < all.size() - (R * C - N); ++i ) {
      ret += all.get(i);
    }

    int ret2 = 0;
    Collections.sort(all2);
    for( int i = 0; i < all2.size() - (R * C - N); ++i ) {
      ret2 += all2.get(i);
    }

    return Math.min(ret, ret2);

  }

}
