import java.util.*;
import java.io.*;

public class x {

  static int [] Qx, Qy, Qa, Qb, Ql;
  static char [][] A;
  static boolean [][][][] F;
  static int qh, qt;


  static void pushE (int mx, int my, int px, int py, int l) {
    if (F[mx][my][px][py]) return;
    //System.out.println ("added to end: " + mx + " " + my + " " + px + " " + py + " " + l);
    Qx[qt] = mx; Qy[qt] = my; Qa[qt] = px; Qb[qt] = py; Ql[qt] = l;
    F[mx][my][px][py] = true;
    ++qt;
  };

  static void pushB (int mx, int my, int px, int py, int l) {
    if (F[mx][my][px][py]) return;
    //System.out.println ("added to beginning: " + mx + " " + my + " " + px + " " + py + " " + l);
    --qh;
    Qx[qh] = mx; Qy[qh] = my; Qa[qh] = px; Qb[qh] = py; Ql[qh] = l;
    F[mx][my][px][py] = true;
  };


  static void trm (int mx, int my, int px, int py, int bx, int by, int l) {
    if (A[mx][my] == '#') {
      if (A[px][py] != '#') {
        pushE (px, py, px, py, l + 1);
        pushE (px, py, bx, by, l + 1);
      };
    } else
      pushE (mx, my, px, py, l + 1);
  };


  static void trp (int mx, int my, int dx, int dy, int l) {
    int px = mx, py = my;
    while (A[px + dx][py + dy] != '#') {
      px += dx;
      py += dy;
    };
    pushB (mx, my, px, py, l);
  };

  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int r = in.nextInt ();
      int c = in.nextInt ();

      A = new char [r + 2][c + 2];

      for (int i = 0; i <= r + 1; i++)
        for (int j = 0; j <= c + 1; j++)
          A[i][j] = '#';

      int mx = -1, my = -1, dx = -1, dy = -1;

      for (int i = 1; i <= r; i++) {
        String s = in.next ();
        //System.out.println (s);
        for (int j = 1; j <= c; j++) {
          A[i][j] = s.charAt (j - 1);
          if (A[i][j] == 'O') {
            A[i][j] = '.'; mx = i; my = j;
          };
          if (A[i][j] == 'X') {
            A[i][j] = '.'; dx = i; dy = j;
          };
        };
      };

      Qx = new int [200000]; 
      Qy = new int [200000]; 
      Qa = new int [200000]; 
      Qb = new int [200000];
      Ql = new int [200000]; 

      F = new boolean [r + 2][c + 2][r + 2][c + 2];
      
      qh = 100000; qt = 100000;

      pushE (mx, my, 0, 0, 0);

      int ans = -1;

      while (qh < qt) {
        mx = Qx[qh];
        my = Qy[qh];
        int px = Qa[qh];
        int py = Qb[qh];
        int ml = Ql[qh];
        
        //System.out.println (mx + " " + my + " " + px + " " + py + " " + ml);

        ++qh;
        if (mx == dx && my == dy) {
          ans = ml;
          break;
        };
        trm (mx - 1, my, px, py, mx, my, ml);
        trm (mx + 1, my, px, py, mx, my, ml);
        trm (mx, my - 1, px, py, mx, my, ml);
        trm (mx, my + 1, px, py, mx, my, ml);
        trp (mx, my, -1,  0, ml);
        trp (mx, my,  1,  0, ml);
        trp (mx, my,  0, -1, ml);
        trp (mx, my,  0,  1, ml);
      };

      if (ans >= 0)
        System.out.println ("Case #" + tt + ": " + ans);
      else
        System.out.println ("Case #" + tt + ": THE CAKE IS A LIE");

    };
  };
};