import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  double solve(int A, int B, double d[]) {

    // reset + B + enter;
    double exp = B + 2;

    double right[] = new double[A+1];
    right[0] = 1.0;
    for(int i=0; i<A; ++i) {
      right[i+1] = (right[i] * d[i]);
    }

    // press back space;
    for(int i=0; i<A; ++i) {
      // A -> (A - i) -> B = (B - A + i + i);
      // enter;
      // if failed then B + enter;
      double cand = right[A - i] * (B - A + i + i + 1) + (1 - right[A - i]) * (B + B - A + i + i + 2);
      exp = Math.min(exp, cand);
    }

    return exp;

  }

  void solve() {

    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();

    for(int C=1; C<=T; ++C) {

      int A = cin.nextInt();
      int B = cin.nextInt();
      double d[] = new double[A];
      for(int i=0; i<A; ++i) { d[i] = cin.nextDouble(); }

      System.out.println("Case #" + C + ": " + solve(A, B, d));

    }

  }

}
