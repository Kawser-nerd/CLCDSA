import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void check(int t, Scanner cin) {

    int R = cin.nextInt();
    int C = cin.nextInt();
    int F = cin.nextInt();

    int line[] = new int[R+1];
    for(int i=0; i<R; ++i) {
      String s = cin.next();
      for(int j=0; j<C; ++j) {
        if( s.charAt(j) == '#' ) { line[i] |= 1 << j; }
      }
    }

    int max = 1 << C;
    int dp[][][][] = new int[R][C][max][max];

    Integer digger[] = new Integer[max];
    for(int i=0; i<max; ++i) {
      digger[i] = i;
    }

    Arrays.sort(digger, 0, max, new Comparator<Integer>() {
      public int compare(Integer a, Integer b) {
        int x = a;
        int y = b;
        int p = Integer.bitCount(a);
        int q = Integer.bitCount(b);
        if( p < q ) { return 1; }
        if( q > p ) { return -1; }
        if( x > y ) { return 1; }
        if( x < y ) { return -1; }
        return 0;
      }
    });

    int INF = R * C + 10;

    for(int i=0; i<R; ++i) {
      for(int j=0; j<C; ++j) {
        for(int k=0; k<max; ++k) {
          for(int m=0; m<max; ++m) {
            dp[i][j][k][m] = INF;
          }
        }
      }
    }

    dp[0][0][line[0]][line[1]] = 0;
    int ret = INF;

    for(int i=0; i<R; ++i) {
      for(int k=max-1; k>=0; --k) {
        for(int m : digger) {
          for(int j=0; j<C; ++j) {
            if( dp[i][j][k][m] == INF ) { continue; }
            if( i == R - 1 ) {
              ret = Math.min(ret, dp[i][j][k][m]);
              continue;
            }
            int le = j;
            while( le > 0 && (k & (1 << (le - 1))) == 0 ) {
              --le;
              if( le == 0 || (m & (1 << le)) == 0 ) { break; }
            }
            int ri = j;
            while( ri < C - 1 && (k & (1 << (ri + 1))) == 0 ) {
              ++ri;
              if( ri == C - 1 || (m & (1 << ri)) == 0 ) { break; }
            }
            // left edge
            int ld = 0;
            if( (m & (1 << le)) == 0 ) {
              ld = 1;
              int y = i + 2;
              while( y < R && (line[y] & (1 << le)) == 0 ) {
                ++ld;
                ++y;
              }
              if( y == R || (line[y] & (1 << le)) != 0 ) { --y; }
              if( ld <= F ) {
                if( ld == 1 ) {
                  dp[i+1][le][m][line[i+2]] = Math.min(dp[i+1][le][m][line[i+2]], dp[i][j][k][m]);
                }
                else {
                  dp[y][le][line[y]][line[y+1]] = Math.min(dp[y][le][line[y]][line[y+1]], dp[i][j][k][m]);
                }
              }
            }
            // right edge
            int rd = 0;
            if( (m & (1 << ri)) == 0 ) {
              rd = 1;
              int y = i + 2;
              while( y < R && (line[y] & (1 << ri)) == 0 ) {
                ++rd;
                ++y;
              }
              if( y == R || (line[y] & (1 << ri)) != 0 ) { --y; }
              if( rd <= F ) {
                if( rd == 1 ) {
                  dp[i+1][ri][m][line[i+2]] = Math.min(dp[i+1][ri][m][line[i+2]], dp[i][j][k][m]);
                }
                else {
                  dp[y][ri][line[y]][line[y+1]] = Math.min(dp[y][ri][line[y]][line[y+1]], dp[i][j][k][m]);
                }
              }
            }
            if( ld > 0 ) { ++le; }
            if( rd > 0 ) { --ri; }
            // dig right
            for(int z=le+1; z<=ri; ++z) {
              dp[i][z-1][k][m - (1 << z)] = Math.min(dp[i][z-1][k][m - (1 << z)], dp[i][j][k][m] + 1);
            }
            // dig left
            for(int z=le; z<ri; ++z) {
              dp[i][z+1][k][m - (1 << z)] = Math.min(dp[i][z+1][k][m - (1 << z)], dp[i][j][k][m] + 1);
            }
          }
        }
      }
    }

    String ans = "";
    if( ret == INF ) { ans = "No"; }
    else { ans = "Yes " + ret; }
    System.out.println("Case #" + t + ": " + ans);

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {
      check(i + 1, cin);
    }

  }

}
