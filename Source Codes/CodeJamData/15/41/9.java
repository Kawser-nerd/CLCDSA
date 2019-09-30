import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int H = cin.nextInt();
      int W = cin.nextInt();

      char map[][] = new char[H][W];

      for(int i=0; i<H; ++i) {
        String s = cin.next();
        for(int j=0; j<W; ++j) {
          map[i][j] = s.charAt(j);
        }
      }

      System.out.println("Case #" + C + ": " + solve(map, H, W));

    }

  }

  String solve(char map[][], int H, int W) {

    int ret = 0;

    for(int i=0; i<H; ++i) {
    MAIN:
      for(int j=0; j<W; ++j) {
        switch( map[i][j] ) {
        case '>':
          for(int k=j+1; k<W; ++k) {
            if( map[i][k] != '.' ) { continue MAIN; }
          }
          break;
        case 'v':
          for(int k=i+1; k<H; ++k) {
            if( map[k][j] != '.' ) { continue MAIN; }
          }
          break;
        case '^':
          for(int k=i-1; k>=0; --k) {
            if( map[k][j] != '.' ) { continue MAIN; }
          }
          break;
        case '<':
          for(int k=j-1; k>=0; --k) {
            if( map[i][k] != '.' ) { continue MAIN; }
          }
          break;
        case '.':
          continue MAIN;
        default:
          throw new RuntimeException("invalid input: " + map[i][j]);
        }
        if( find(map, i, j, H, W) ) { ++ret; }
        else { return "IMPOSSIBLE"; }
      }
    }

    return "" + ret;

  }

  boolean find(char map[][], int Y, int X, int H, int W) {
    for(int i=0; i<H; ++i) {
      if( i == Y ) { continue; }
      if( map[i][X] != '.' ) { return true; }
    }
    for(int i=0; i<W; ++i) {
      if( i == X ) { continue; }
      if( map[Y][i] != '.' ) { return true; }
    }
    return false;
  }

}
