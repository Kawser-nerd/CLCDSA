import java.util.*;
import java.io.*;
import java.awt.*;

public class x {
  static int w, h;

  static long line (int px, int py, int x1, int y1) {
    int xval, yval;
    if (x1 != 0) {
      if (x1 > 0) xval = (w - px - 1) / x1; else xval = px / (-x1);
    } else xval = Integer.MAX_VALUE;
    if (y1 != 0) {
      if (y1 > 0) yval = (h - py - 1) / y1; else yval = py / (-y1);
    } else yval = Integer.MAX_VALUE;
    return Math.min (xval, yval);
  };

  static Point [] Q;
  static HashSet <Point> q;
  static int qh, qt;


  static void put (int x, int y) {
    if (x < 0 || x >= w || y < 0 || y >= h) return;
    Point p = new Point (x, y);
    if (q.contains (p)) return;
    q.add (p);
    Q[qt++] = p;
  };

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    PrintWriter out = new PrintWriter (System.out);

    int tcnt = in.nextInt ();

    for (int i = 1; i <= tcnt; i++) {
      w = in.nextInt ();
      h = in.nextInt ();

      int x1 = in.nextInt ();
      int y1 = in.nextInt ();
      
      int x2 = in.nextInt ();
      int y2 = in.nextInt ();

      int px = in.nextInt ();
      int py = in.nextInt ();

      long ans = 0;

      if (x1 * y2 - x2 * y1 == 0) {
        q = new HashSet <Point> ();
        Q = new Point [2000000];
        qh = 0; qt = 0;
        put (px, py);
        while (qh < qt) {
          Point p = Q[qh++];
          put (p.x + x1, p.y + y1);
          put (p.x + x2, p.y + y2);
        };
        ans = qt;
      } else {
        do {
          long cur = line (px, py, x1, y1);
          ans += cur + 1;
          px += x2; py += y2;
          while (cur >= 0 && (px < 0 || px >= w || py < 0 || py >= h)) {
            --cur; px += x1; py += y1;
          }; 
          if (cur < 0) break;
        } while (true);
      };

      out.println ("Case #" + i + ": " + ans);
    };

    out.close ();
  };
};