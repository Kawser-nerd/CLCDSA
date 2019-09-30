import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      String s = cin.next();

      System.out.println("Case #" + C + ": " + solve(s));

    }

  }

  long solve(String s) {

    // ends;
    if( Long.parseLong(s) == 0 ) { return 0; }

    int N = s.length();

    String head = s.substring(0, N / 2);
    String tail = s.substring(N / 2);

    long tmp = Long.parseLong(tail);
    if( tmp == 0 ) {
      return 1 + solve("" + (Long.parseLong(s) - 1));
    }

    String next = "" + (Long.parseLong(s) - (tmp - 1));
    String rev = rev(next);

    // same (need not to flip);
    if( Long.parseLong(next) == Long.parseLong(rev) ) {
      return tmp + solve("" + (Long.parseLong(s) - tmp));
    }

    return tmp + solve(rev);

  }

  String rev(String s) {
    return (new StringBuilder(s)).reverse().toString();
  }

}
