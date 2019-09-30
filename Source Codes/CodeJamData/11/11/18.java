import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  boolean solve(long n, int pd, int pg) {

    long max = Math.min(n, 100);

    int base = 10000;
    int all = 100 * base;
    int win = pg * base;

    for(int i=1; i<=max; ++i) {

      int w = i * pd;
      if( w % 100 != 0 ) { continue; }
      w /= 100;

      int m = all - i;
      int c = win - w;

      if( c < 0 || c > m ) { continue; }
      return true;

    }

    return false;

  }

  void exec() {

    Scanner cin = new Scanner(System.in);

    int t = cin.nextInt();
    for(int i=1; i<=t; ++i) {

      long n = cin.nextLong();
      int pd = cin.nextInt();
      int pg = cin.nextInt();

      System.out.print("Case #" + i + ": ");
      System.out.println(solve(n, pd, pg) ? "Possible" : "Broken");

    }

  }

}
