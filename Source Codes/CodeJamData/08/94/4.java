import java.util.*;
import java.io.*;
import java.awt.*;

public class x {
  static Point [] Q;
  static int qh, qt;
  static HashMap <Point, Integer> q;
  static char [][] F;

  static void put (int x, int y, int l) {
    if (F[x][y] != 'T' && F[x][y] != '#') return;
    Point p = new Point (x, y);
    if (q.containsKey (p)) return;
    q.put (p, l);
    Q[qt++] = p;
  };


  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    PrintWriter out = new PrintWriter (System.out);

    int tcnt = in.nextInt ();

    for (int i = 1; i <= tcnt; i++) {
      int n = in.nextInt ();
      int m = in.nextInt ();

      F = new char [n + 2][m + 2];

      for (int a = 0; a < n; a++) {
        String s = in.next ();
        for (int b = 0; b < m; b++)
          F[a + 1][b + 1] = s.charAt (b);
      };

      Q = new Point [10000];
      q = new HashMap <Point, Integer> ();
      qh = 0; qt = 0;
      put (1, 1, 0);
      while (qh < qt) {
        Point p = Q[qh++];
        int l = q.get (p);
        put (p.x + 1, p.y, l + 1);
        put (p.x - 1, p.y, l + 1);
        put (p.x, p.y + 1, l + 1);
        put (p.x, p.y - 1, l + 1);
      };

      int tx = -1, ty = -1;

      for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
          if ((x != 1 || y != 1) && F[x][y] == 'T') {
            tx = x; ty = y;
          };

      long ans = 0;
      if (tx == -1 && ty == -1) {
        for (int x = 1; x <= n; x++)
          for (int y = 1; y <= m; y++)
            if (F[x][y] == 'T' || F[x][y] == '#') {
              ans += q.get (new Point (x, y));
            };
      } else {
        int tl = q.get (new Point (tx, ty));
        Q = new Point [10000];
        q = new HashMap <Point, Integer> ();
        qh = 0; qt = 0;
        put (1, 1, 0);
        put (tx, ty, 0);
        while (qh < qt) {
          Point p = Q[qh++];
          int l = q.get (p);
          put (p.x + 1, p.y, l + 1);
          put (p.x - 1, p.y, l + 1);
          put (p.x, p.y + 1, l + 1);
          put (p.x, p.y - 1, l + 1);
        };
        for (int x = 1; x <= n; x++)
          for (int y = 1; y <= m; y++)
            if (F[x][y] == 'T' || F[x][y] == '#') {
              ans += q.get (new Point (x, y));
              //System.out.println (x + " " + y + " " + q.get (new Point (x, y)));
            };
        for (int j = 0; j + j <= tl; j++)
          ans = ans + (tl - j) - j;
      };

      out.println ("Case #" + i + ": " + ans);
    };

    out.close ();
  };
};