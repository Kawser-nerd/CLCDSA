import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class RatherPerplexingShowdown {

  static class Req {
    final int n;
    final Turn winner;

    public Req(int n, Turn winner) {
      this.n = n;
      this.winner = winner;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;

      Req req = (Req) o;

      if (n != req.n) return false;
      return winner == req.winner;

    }

    @Override
    public int hashCode() {
      int result = n;
      result = 31 * result + (winner != null ? winner.hashCode() : 0);
      return result;
    }
  }

  static Map<Req, String> cache = new HashMap<>();
  static {
    cache.put(new Req(0, Turn.R), "R");
    cache.put(new Req(0, Turn.P), "P");
    cache.put(new Req(0, Turn.S), "S");
  }

  // R > S, S > P, P > R
  // PRS

  enum Turn {
    R, P, S;

    Turn iWinWhom() {
      switch (this) {
        case R:
          return S;
        case S:
          return P;
        case P:
          return R;
        default:
          throw new AssertionError();
      }
    }
  }

  static class Stats {
    final int r, p, s;

    Stats(int r, int p, int s) {
      this.r = r;
      this.p = p;
      this.s = s;
    }

    Stats(Turn t) {
      switch (t) {
        case P:
          r = 0; p = 1; s = 0;
          break;
        case R:
          r = 1; p = 0; s = 0;
          break;
        case S:
          r = 0; p = 0; s = 1;
          break;
        default:
          throw new AssertionError();
      }
    }

    Stats merge(Stats other) {
      return new Stats(r + other.r, p + other.p, s + other.s);
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;

      Stats stats = (Stats) o;

      if (r != stats.r) return false;
      if (p != stats.p) return false;
      return s == stats.s;

    }

    @Override
    public int hashCode() {
      int result = r;
      result = 31 * result + p;
      result = 31 * result + s;
      return result;
    }
  }

  static Stats getStats(Turn winner, int layers) {
    Stats current = new Stats(winner);
    int r = current.r;
    int p = current.p;
    int s = current.s;
    for (int i = 0; i < layers; i++) {
      int newR = p;
      int newP = s;
      int newS = r;
      r += newR;
      p += newP;
      s += newS;
    }
    return new Stats(r, p, s);
  }

  static String min(String s1, String s2, String s3) {
    String best = s1;
    if (best == null || (s2 != null && s2.compareTo(best) < 0)) {
      best = s2;
    }
    if (best == null || (s3 != null && s3.compareTo(best) < 0)) {
      best = s3;
    }
    return best;
  }

  static String solve(Req req) {
    if (cache.containsKey(req)) {
      return cache.get(req);
    }
    String part1 = solve(new Req(req.n - 1, req.winner));
    String part2 = solve(new Req(req.n - 1, req.winner.iWinWhom()));
    final String ans;
    if (part1.compareTo(part2) < 0) {
      ans = part1 + part2;
    } else {
      ans = part2 + part1;
    }
    cache.put(req, ans);
    return ans;
  }

  static String solve(Turn winner, int layers) {
    return solve(new Req(layers, winner));
  }

  static String solve(int n, int r, int p, int s) {
    Stats here = new Stats(r, p, s);
    Stats ifR = getStats(Turn.R, n);
    Stats ifP = getStats(Turn.P, n);
    Stats ifS = getStats(Turn.S, n);
    if (!here.equals(ifR) && !here.equals(ifP) && !here.equals(ifS)) {
      return "IMPOSSIBLE";
    }
    String ansIfR = here.equals(ifR) ? solve(Turn.R, n) : null;
    String ansIfP = here.equals(ifP) ? solve(Turn.P, n) : null;
    String ansIfS = here.equals(ifS) ? solve(Turn.S, n) : null;
    return min(ansIfR, ansIfP, ansIfS);
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int tests = in.nextInt();
    for (int t = 1; t <= tests; t++) {
      int n = in.nextInt();
      int r = in.nextInt();
      int p = in.nextInt();
      int s = in.nextInt();
      String ans = solve(n, r, p, s);
      System.out.println("Case #" + t + ": " + ans);
    }
  }
}
