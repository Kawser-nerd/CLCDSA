import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int k = in.nextInt (), l = 2 * k - 1;
      char [][] a = new char [l + 2][];
      in.nextLine ();
      a[0] = new char[0];
      a[l + 1] = new char [0];
      for (int j = 1; j <= l; j++) {
        a[j] = (" " + in.nextLine () + " ").toCharArray ();
        //System.out.println (a[j]);
      }
      int ans = Integer.MAX_VALUE;

      for (int i = 0; i <= l + 1; i++)
        for (int j = 0; j <= l + 1; j++) 
          if (true) {
            //System.out.println ("i = " + i + ", j = " + j);
            boolean ok = true;
            int csize = 0;
            for (int x = 0; x <= l + 1; x++) {
              for (int y = 0; y < a[x].length; y++) {
                int nx = 2 * i - x, ny = y;
                char symm = ' ';
                if (!(nx < 0 || ny < 0 || nx >= l + 2 || ny >= a[nx].length || a[nx][ny] == ' ')) {
                  symm = a[nx][ny];
                  //System.out.println (nx + " " + ny);
                  //csize = Math.max (Math.abs (nx - i) + Math.abs (ny - j) + 1, csize);
                }
                if (a[x][y] != ' ') {
                  if (symm != ' ' && a[x][y] != symm) {
                    ok = false;
                    break;
                  }
                  //System.out.println (x + " " + y);
                  csize = Math.max (Math.abs (x - i) + Math.abs (y - j) + 1, csize);
                }
                nx = x; ny = 2 * j - y;
                symm = ' ';
                if (!(nx < 0 || ny < 0 || nx >= l + 2 || ny >= a[nx].length || a[nx][ny] == ' ')) {
                  symm = a[nx][ny];
                  //System.out.println (nx + " " + ny);
                  //csize = Math.max (Math.abs (nx - i) + Math.abs (ny - j) + 1, csize);
                }
                if (a[x][y] != ' ') {
                  if (symm != ' ' && a[x][y] != symm) {
                    ok = false;
                    break;
                  }
                  //System.out.println (x + " " + y);
                  csize = Math.max (Math.abs (x - i) + Math.abs (y - j) + 1, csize);
                }
              }
              if (!ok) {
                break;
              }
            }
            if (ok) {
              //System.out.println ("csize = " + csize);
              ans = Math.min (ans, csize);
            }
          }

      System.out.println ("Case #" + tt + ": " + (ans * ans - k * k));
    };
  };
};