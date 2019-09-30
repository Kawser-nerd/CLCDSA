import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int n = in.nextInt ();

      double x [] = new double [n];
      double y [] = new double [n];
      double z [] = new double [n];
      double p [] = new double [n];
      double a [][] = new double[n][4];

      for (int i = 0; i < n; i++) {
        x[i] = in.nextInt ();
        y[i] = in.nextInt ();
        z[i] = in.nextInt ();
        p[i] = in.nextInt ();
        a[i][0] = x[i] + y[i] + z[i];
        a[i][1] = x[i] + y[i] - z[i];
        a[i][2] = x[i] - y[i] + z[i];
        a[i][3] = - x[i] + y[i] + z[i];
      };


      double l = 0, r = 1e20;
      for (int it = 0; it <= 500; it++) {
        double m = (l + r) / 2;
        boolean fl = true;
        for (int j = 0; j < 4; j++) {
          double lb = -1e100, rb = 1e100;
          for (int i = 0; i < n; i++) {
            double clb = a[i][j] - m * p[i];
            double crb = a[i][j] + m * p[i];
            //System.out.println (j + " " + i + " " + m + " " + clb + " " + crb);
            lb = Math.max (lb, clb);
            rb = Math.min (rb, crb);
          };
          //System.out.println (j + " " + m + " " + lb + " " + rb);
          if (lb > rb) {
            fl = false;
            break;
          };
        };
        if (fl) r = m; else l = m;
      };

      System.out.println ("Case #" + tt + ": " + l /*/ Math.sqrt (3)*/);
    };
  };
};