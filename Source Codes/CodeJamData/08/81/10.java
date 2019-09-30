import java.util.*;
import java.math.*;

public class x {
  static Scanner in;
  static double [][] readtriangle () {
    double [][] res = new double [3][2];

    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 2; j++)
        res[i][j] = in.nextInt ();

    return res;
  };

  
  static double [] solve3 (double [][] mat, double [] vec) {
    double det = mat[0][0] * mat[1][1] * mat[2][2] +
                 mat[0][1] * mat[1][2] * mat[2][0] +
                 mat[0][2] * mat[1][0] * mat[2][1] -
                 mat[2][0] * mat[1][1] * mat[0][2] -
                 mat[2][1] * mat[1][2] * mat[0][0] -
                 mat[2][2] * mat[1][0] * mat[0][1];


   /*for (int i = 0; i < 3; i++)
     for (int j = 0; j < 3; j++)
       System.out.println (mat[i][j]);
   System.out.println ("det = " + det);*/

   if (Math.abs (det) < 1e-14) return new double [0];


   double [][] imat = new double [3][3];

    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        double [][] pres = new double [2][2];

        int px = 0, py = 0;

        for (int k = 0; k < 3; k++) if (i != k) {
          py = 0;
          for (int l = 0; l < 3; l++) if (j != l) {
            pres[px][py] = mat [k][l]; 
            ++py;
          }
          ++px;
        };
        imat[j][i] = (pres[0][0] * pres[1][1] - pres[0][1] * pres[1][0]) / det;
        if (((i + j) & 1) != 0) imat[j][i] = -imat[j][i];
      };

    /*for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        System.out.println (imat[i][j]);

    System.out.println ("!!!");*/

    double [] res = new double [3];

    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        res[i] += imat[i][j] * vec[j];

    return res;
  };


  static double [] solve2 (double [][] mat, double [] vec) {
    double det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    /*for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        System.out.println (mat[i][j]);
    System.out.println (det);*/
    if (Math.abs (det) < 1e-14) return new double [0];
    double [] res = new double[2];
    res[0] = (mat[1][1] * vec[0] - mat[0][1] * vec[1]) / det;
    res[1] = (mat[0][0] * vec[1] - mat[1][0] * vec[0]) / det;
    return res;
  };

  /*static double [][] tryGet (double [][] t1, double [][] t2, int p1, int p2) {
    System.out.println (p1 + " " + p2);
    double [][] mat = new double [2][2];
    mat[0][0] = t1[p1][0];
    mat[0][1] = t1[p1][1];
    mat[1][0] = t1[p2][0];
    mat[1][1] = t1[p2][1];

    double [] vec = new double [2];
    vec[0] = t2[p1][0];
    vec[1] = t2[p2][0];

    double [] vec1 = solve (mat, vec);
    if (vec1.length == 0) return new double [0][0];

    vec[0] = t2[p1][1];
    vec[1] = t2[p2][1];
    double [] vec2 = solve (mat, vec);
    if (vec2.length == 0) throw new RuntimeException ("");

    double [][] ret = new double [2][2];
    ret[0][0] = vec1[0];
    ret[0][1] = vec1[1];
    ret[1][0] = vec2[0];
    ret[1][1] = vec2[1];

    return ret;
  };*/

  static double [] get (double [][] t1, double [][] t2) {
    double [][] mat = new double [3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++)
        mat[i][j] = t1[i][j];
      mat[i][2] = 1;
    };

    double [] vec = new double [3];
    for (int j = 0; j < 3; j++) vec[j] = t2[j][0];

    double [] a1 = solve3 (mat, vec);

    for (int j = 0; j < 3; j++) vec[j] = t2[j][1];
    double [] a2 = solve3 (mat, vec);


    double [] ret = new double [6];
    for (int j = 0; j < 3; j++) {
      ret[j] = a1[j];
      ret[j + 3] = a2[j];
    };
    return ret;
  };


  public static void main (String args []) throws Exception {
    in = new Scanner (System.in);
    int tn = in.nextInt ();
    for (int i = 1; i <= tn; i++) {
      double t1 [][] = readtriangle ();
      double t2 [][] = readtriangle ();

      double [] cur = get (t1, t2);

      /*System.out.println ("test");
      for (int a = 0; a < 6; a++)
        System.out.println (cur[a]);*/


      double [][] mat = new double[2][2];

      mat[0][0] = cur[0] - 1;
      mat[0][1] = cur[1];
      mat[1][0] = cur[3];
      mat[1][1] = cur[4] - 1;

      double [] vec = new double [2];

      vec[0] = -cur[2];
      vec[1] = -cur[5];




      /*mat[0][0] -= 1;
      mat[1][1] -= 1;

      double [] vec = new double [2];*/

      double [] res = solve2 (mat, vec);
      if (res.length == 0) throw new RuntimeException ("");

      System.out.printf ("Case #%d: %.6f %.6f\n", i, res[0], res[1]);
    };
  };
};
