import java.util.*;

public class B {

  static Scanner in;
  static List<Point> l;

  public static void main(String[] args) {
    in = new Scanner(System.in);


    int T = in.nextInt();
    for (int C = 1; C <= T; C++) {
      System.out.println("Case #" + C + ": " + solve());
    }
  }

  static int solve() {
    l = new ArrayList<>();
    int N = in.nextInt();
    int P = in.nextInt();
    int[] costs = new int[N];
    int[][] q = new int[N][P];

    for (int i = 0; i < N; i++) {
      costs[i] = in.nextInt();
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < P; j++) {
        q[i][j] = in.nextInt();
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < P; j++) {
        getQuantity(q[i][j], costs[i], i);
      }
    }


    int tot = 0;
    int[] count = new int[N];
    int[] added = new int[N];
    Collections.sort(l);
    for (Point p : l) {
      //System.err.println(p);
      if (p.start) {
        count[p.r]++;
        //System.err.println(Arrays.toString(count));
        boolean match = true;
        for (int i = 0; i < N; i++) {
          if (count[i] <= 0) match = false;
        }
        if (match) {
          tot++;
          for (int i = 0; i < N; i++) {
            count[i]--;
            added[i]++;
          }
        }
      } else {
        if (added[p.r] > 0) {
          added[p.r]--;
        } else {
          count[p.r]--;
        }
      }
    }

    return tot;
  }

  static void getQuantity(double n, double cost, int r) {
    double q = n/cost;
    int hi = (int) Math.floor(q / 0.9);
    int low = (int) Math.ceil(q / 1.1);
    if (low <= hi) {
      //System.err.println(n + " " + cost + ": " + low + " - " + hi);
      l.add(new Point(low, true, r));
      l.add(new Point(hi, false, r));
    }
  }
}

class Point implements Comparable<Point> {
  int val;
  boolean start;
  int r;

  Point(int val, boolean start, int r) {
    this.val = val;
    this.start = start;
    this.r = r;
  }

  public int compareTo(Point o) {
    if (val > o.val) return 1;
    if (val < o.val) return -1;
    if (start && !o.start) return -1;
    if (!start && o.start) return 1;
    return r - o.r;
  }

  public String toString() {
    return r + " at " + val + " " + (start ? "start" : "end");
  }
}
