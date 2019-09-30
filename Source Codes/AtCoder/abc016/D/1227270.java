import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long ax = sc.nextLong();
    long ay = sc.nextLong();
    long bx = sc.nextLong();
    long by = sc.nextLong();
    int N = sc.nextInt();
    long[] x = new long[N];
    long[] y = new long[N];
    for(int i = 0; i < N; i++) {
      x[i] = sc.nextLong();
      y[i] = sc.nextLong();
    }
    int count = 0;
    for(int i = 0; i < N; i++) {
      long abx = bx - ax;
      long aby = by - ay;
      long px = x[i] - ax;
      long py = y[i] - ay;
      long qx = x[0] - ax;
      long qy = y[0] - ay;
      if(i < N - 1) {
        qx = x[i + 1] - ax;
        qy = y[i + 1] - ay;
      }
      long ex = x[0] - x[N - 1];
      long ey = y[0] - y[N - 1];
      if(i < N - 1) {
        ex = x[i + 1] - x[i];
        ey = y[i + 1] - y[i];
      }
      long rx = ax - x[i];
      long ry = ay - y[i];
      long sx = bx - x[i];
      long sy = by - y[i];
      if(((abx * py - aby * px) * (abx * qy - aby * qx) <= 0) && ((ex * ry - ey * rx) * (ex * sy - ey * sx) <= 0)) count++;
    }
    System.out.println(count / 2 + 1);
  }
}