import java.util.*;
import java.io.*;

public class x {
  static class Directory {
    int st;
    HashMap <String, Directory> h;

    Directory (int cst) {
      h = new HashMap <String, Directory> ();
      st = cst;
    }

    Directory create (String name, int sst) {
      Directory c = h.get (name);
      if (c != null) return c;
      c = new Directory (sst);
      h.put (name, c);
      return c;
    }

    int count (int lst) {
      int cur = 0;
      if (st > lst) ++cur;
      for (Directory z : h.values ()) cur += z.count (lst);
      return cur;
    }
  }

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      Directory r = new Directory (0);
      int n = in.nextInt (), m = in.nextInt ();
      for (int i = 1; i <= n + m; i++) {
        String [] a = in.next ().split ("/");
        Directory c = r;
        for (int j = 1; j < a.length; j++) {
          c = c.create (a[j], i);
        }
      }

      System.out.println ("Case #" + tt + ": " + r.count (n));
    };
  };
};