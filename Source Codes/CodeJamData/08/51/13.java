import java.util.*;
import java.io.*;

public class x {
  static int dx [] = {0, -1, 0, 1};
  static int dy [] = {1, 0, -1, 0};

  static final int mc = 100;


  static int [][] f;

  static int xc, yc, dir;

  static void traverse (String s) {
    for (int i = 0; i < s.length (); i++) {
      if (s.charAt (i) == 'F') {
        f[xc][yc] = 2;
        xc += dx[dir];
        yc += dy[dir];
        f[xc][yc] = 2;
        xc += dx[dir];
        yc += dy[dir];
        f[xc][yc] = 2;
      } else
      if (s.charAt (i) == 'L') ++dir;
      else
      --dir;
      dir &= 3;
    };
  };


  static void dfs (int x, int y) {
    if (f[x][y] != 0) return;
    f[x][y] = 1;
    dfs (x + 1, y);
    dfs (x, y + 1);
    dfs (x - 1, y);
    dfs (x, y - 1);
  };

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int l = in.nextInt ();

      f = new int [mc * 4 + 10][mc * 4 + 10];

      xc = mc * 2 + 4; yc = mc * 2 + 4; dir = 0;
      for (int i = 0; i < l; i++) {
        String s = in.next ();
        int rc = in.nextInt ();
        for (int j = 0; j < rc; j++)
          traverse (s);
      };

      for (int i = 0; i < mc * 4 + 10; i++) {
        f[0][i] = 1;
        f[i][0] = 1;
        f[mc * 4 + 9][i] = 1;
        f[i][mc * 4 + 9] = 1;
      };
      /*for (int i = 0; i < mc * 4 + 10; i++) {
        for (int j = 0; j < mc * 4 + 10; j++)
          System.out.print (f[i][j] + " ");
        System.out.println ();
      };*/

      dfs (1, 1);

      /*for (int i = 0; i < mc * 4 + 10; i++) {
        for (int j = 0; j < mc * 4 + 10; j++)
          System.out.print (f[i][j] + " ");
        System.out.println ();
      };*/

      int area = 0;

      for (int i = 0; i < mc * 2 + 5; i++)
       for (int j = 0; j < mc * 2 + 5; j++) {
         int x = 2 * i + 1;
         int y = 2 * j + 1;
         if (f[x][y] == 1) {
           int cnt = 0;

           for (int k = y - 1; k >= 0; k--)
             if (f[x][k] == 2) {
               ++cnt;
               break;
             };

           for (int k = y + 1; k <= mc * 4 + 9; k++)
             if (f[x][k] == 2) {
               ++cnt;
               break;
             };

           //System.out.println (x + " " + y + " " + cnt);

           if (cnt == 2) ++area; else {
             cnt = 0;

             for (int k = x - 1; k >= 0; k--)
               if (f[k][y] == 2) {
                 ++cnt;
                 break;
               };

             for (int k = x + 1; k <= mc * 4 + 9; k++)
               if (f[k][y] == 2) {
                 ++cnt;
                 break;
               };
             if (cnt == 2) ++area;
             //System.out.println (x + " " + y + " " + cnt);
           };
         };
       };



      System.out.println ("Case #" + tt + ": " + area);
    };
  };
};