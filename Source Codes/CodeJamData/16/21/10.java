import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int req[][] = new int[10][26];
    String part[] = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
    for(int i=0; i<10; ++i) {
      for(int j=0; j<part[i].length(); ++j) {
        ++req[i][ part[i].charAt(j) - 'A' ];
      }
    }

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      String S = cin.next();
      int count[] = new int[26];
      for(int i=0; i<S.length(); ++i) {
        ++count[ S.charAt(i) - 'A' ];
      }

      int result[] = new int[10];

      // ZERO;
      if( count[ 'Z' - 'A' ] > 0 ) {
        result[0] = count[ 'Z' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[0] * req[0][i];
        }
      }

      // TWO;
      if( count[ 'W' - 'A' ] > 0 ) {
        result[2] = count[ 'W' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[2] * req[2][i];
        }
      }

      // EIGHT;
      if( count[ 'G' - 'A' ] > 0 ) {
        result[8] = count[ 'G' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[8] * req[8][i];
        }
      }

      // THREE;
      if( count[ 'H' - 'A' ] > 0 ) {
        result[3] = count[ 'H' - 'A' ];
        if( count[ 'T' - 'A' ] != result[3] ) { throw new RuntimeException("Implementation Failure: 283"); }
        for(int i=0; i<26; ++i) {
          count[i] -= result[3] * req[3][i];
        }
      }

      // FOUR;
      if( count[ 'R' - 'A' ] > 0 ) {
        result[4] = count[ 'R' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[4] * req[4][i];
        }
      }

      // ONE;
      if( count[ 'O' - 'A' ] > 0 ) {
        result[1] = count[ 'O' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[1] * req[1][i];
        }
      }

      // FIVE;
      if( count[ 'F' - 'A' ] > 0 ) {
        result[5] = count[ 'F' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[5] * req[5][i];
        }
      }

      // SEVEN;
      if( count[ 'V' - 'A' ] > 0 ) {
        result[7] = count[ 'V' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[7] * req[7][i];
        }
      }

      // SIX;
      if( count[ 'S' - 'A' ] > 0 ) {
        result[6] = count[ 'S' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[6] * req[6][i];
        }
      }

      // NINE;
      if( count[ 'I' - 'A' ] > 0 ) {
        result[9] = count[ 'I' - 'A' ];
        for(int i=0; i<26; ++i) {
          count[i] -= result[9] * req[9][i];
        }
      }

      String ans = "";
      for(int i=0; i<10; ++i) {
        for(int j=0; j<result[i]; ++j) {
          ans += i;
        }
      }

      System.out.println("Case #" + C + ": " + ans);

      for(int i=0; i<26; ++i) {
        if( count[i] != 0 ) { throw new RuntimeException("Implementation Error or Input Error: ALL: " + i); }
      }

    }

  }

}
