import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class AShow {
  public static void main(String[]args) throws Exception {
    File f = new File(args[0]);
    File f2 = new File(f.getParentFile(),f.getName()+".out");
    Scanner s = new Scanner(f);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int N = s.nextInt();
      int points[] = new int[N];
      int total = 0;
      for (int i=0;i<N;i++)
        total += points[i]=s.nextInt();

      println(f2,"Case #"+t+": "+solve(points, total));
    }
    s.close();
  }

  private static String solve(int[] points, int tot) {
    String s = "";
    for (int i=0;i<points.length;i++) {
      if (i>0) s+= " ";
      double min = 0, max = 100;
      while (Math.abs(max - min) > 1e-6) {
        if (ok(points, i, min, tot)) {
          break;
        }
        double mid = (max + min) / 2;
        if (ok(points, i, mid, tot)) {
          max = mid;
        } else {
          min = mid;
        }
      }
      s += min;
    }
    return s;
  }
  static boolean ok(int[] points, int idx, double pct, int tot) {
    double val = points[idx] + pct * tot / 100.;
    double rem = 100 - pct;
    int inplay = 0;
    int subtot = 0;
    for (int x=0;x<points.length; x++) {
      if (x == idx) continue;
      if (points[x] > val) continue;
      inplay++;
      subtot += points[x];
    }
    if (inplay == 0) return false;
    double xyz = (subtot + rem * tot/100.) * 1./inplay;
    if (val >= xyz) return true;
    return false;
  }

  static void println(File f, String s) throws Exception {
    FileWriter w = new FileWriter(f,true);
    w.write(s+"\n");
    w.close();
    System.out.println(s);
  }
}
/*
 * 177
 * 59 59 1 0 0 0 58
 * 
 * 1 1 1 1 1 5
 * 
 * 10
 * 
 * 3.33333
 * 1 + .2 * 10 = 3
 * (3.333 - 1) * 2 / 10
 * 
 */
