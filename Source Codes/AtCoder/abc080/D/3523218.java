import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int C = scanner.nextInt();

    List<int[]>[] lists = new List[C];
    for (int i = 0; i < C; i++) lists[i] = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      int s = scanner.nextInt();
      int t = scanner.nextInt();
      int c = scanner.nextInt();
      lists[c - 1].add(new int[]{s, t});
    }

    List<Point> points = new ArrayList<>();
    for (List<int[]> l : lists) {
      l.sort(Comparator.comparingInt(o -> o[0]));
      for (int i = 0; i < l.size(); i++) {
        int[] seg = l.get(i);
        if (i == 0 || seg[0] != l.get(i - 1)[1]) {
          points.add(new Point(true, seg[0] - 1));
        }
        if (i == l.size() - 1 || seg[1] != l.get(i + 1)[0]) {
          points.add(new Point(false, seg[1]));
        }
      }
    }
    Collections.sort(points);

    int max = 0;
    int count = 0;
    for (Point p : points) {
      if (p.up) count++;
      else count--;
      if (count > max) max = count;
    }
    System.out.println(max);
  }

  static class Point implements Comparable<Point> {
    public final boolean up;
    public final int t;

    Point(boolean up, int t) {
      this.up = up;
      this.t = t;
    }

    @Override public int compareTo(Point o) {
      return t != o.t ? (t - o.t) : up ? 1 : -1;
    }

    @Override public String toString() {
      return "[" +  t + ", " + up + ']';
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.