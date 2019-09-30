import java.util.*;
 
class Point implements Comparable<Point> {
  int a, b;
  Point (int a, int b) {
    this.a = a;
    this.b = b;
  }
 
  public int hashCode() {
    return ((a & 0xFFFF0000) | (b>>16)) ^ ((b & 0xFFFF0000) | (a>>16));
  }
 
  public boolean equals(Object object) {
    Point point = (Point)object;
    return this.a == point.a && this.b == point.b;
  }

  public int compareTo(Point p) {
    if (this.a != p.a) {
      return this.a - p.a;
    }
    return this.b - p.b;
  }
}
 
public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int h = s.nextInt();
    int w = s.nextInt();
    int n = s.nextInt();
    HashMap<Point, Integer> map = new HashMap<Point, Integer>();
//    TreeMap<Point, Integer> map = new TreeMap<Point, Integer>();
    for (int i = 0; i < n; i++) {
      int a = s.nextInt() - 1;
      int b = s.nextInt() - 1;
      for (int da = Math.max(0, a - 2); da <= Math.min(h - 3, a); da++) {
        for (int db = Math.max(0, b - 2); db <= Math.min(w - 3, b); db++) {
          Point p = new Point(da, db);
          if (map.get(p) == null) {
            map.put(p, 1);
          } else {
            map.put(p, map.get(p) + 1);
          }
        }
      }
    }
    long[] output = new long[10];
    output[0] = (long)(h - 2) * (long)(w - 2);
    for (int value : map.values()) {
      output[0]--;
      output[value]++;
    }
    for (long value : output) {
      System.out.println(value);
    }
  }
}