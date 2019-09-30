import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;


public class CC {

  static boolean[][][] a;
  static boolean[][][] xx;
  static boolean[][][] yy;
  public static void gao(int ii, int jj, int kk) {
    
    for (int i = Math.max(0, ii - kk + 1); i < ii + kk; ++i) {
      for (int j = Math.max(0, jj - kk + 1); j < jj + kk; ++j) {
        for (int k = 2; k <= kk; ++k) {
          if (i + k - 1>=ii && j + k - 1 >= jj) a[i][j][k] = false;
        }
      }
    }
    
    
  }
  public static long gao(boolean[][] b, int z) {
    int m = b.length;
    int n = b[0].length;
    
    int kk = Math.max(m, n);
    a = new boolean[m][n][kk+1];
    xx = new boolean[m][n][kk+1];
    yy = new boolean[m][n][kk+1];
    
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 1; k + i < m; ++k) {
          xx[i][j][k+1] = b[i+k][j] != b[i+k-1][j];
          if (!xx[i][j][k+1]) break;
        }
        for (int k = 1; k + j < n; ++k) {
          yy[i][j][k+1] = b[i][j+k] != b[i][j+k-1];
          if (!yy[i][j][k+1]) break;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 1;  k + i < m &&  k + j < n; ++k) {
          if (xx[i][j+k][k+1] && b[i][j+k] != b[i][j+k-1] &&
              yy[i+k][j][k+1] && b[i+k][j] != b[i+k-1][j]) {
            a[i][j][k+1] = true;
          } else {
            break;
          }
        }
      }
    }
   

    int[] cnt = new int[kk+1];
    
    for (int ret = kk; ret >= 2; --ret) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) if (a[i][j][ret]){
        cnt[ret] ++;
        gao(i, j, ret);
      }
    } 
    }

    int one = m*n;
    int tot = 0;
    for (int i = 2; i <= kk; ++i) {
      if (cnt[i]> 0) tot++;
      one -= i*i*cnt[i];
    }
    if (one > 0) tot ++;
    cnt[1] = one;
    System.out.println("Case #" + (z+1) + ": " + tot);
    for (int i = kk; i >=1; --i) {
      if (cnt[i] > 0) {
        System.out.println(i + " " + cnt[i]);
      }
    }
    /*
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        System.out.print(b[i][j] ? "X" : ".");
      }
      System.out.println();
    }
    */
    
    
    return 0;
                    
  }
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    
    int t = in.nextInt();
    for (int i  = 0; i < t; ++i) {
      
      int m, n;
      m = in.nextInt();
      n = in.nextInt();
      boolean[][] map = new boolean[m][n];
      for (int ii = 0; ii < m; ++ii) {
        String l = in.next();
        
        for (int jj = 0; jj < n/4; ++jj) {
          char c = l.charAt(jj);
          int d = Integer.parseInt(""+c, 16);
          for (int k = 3; k >=0; --k) {
            map[ii][jj*4 + k] = d % 2 == 0;
            d/=2;
          }
        }
      }
    
        
        gao(map, i);
        //System.out.println("Case #" + (i+1) + ": " + ret);
    }
    
    
    
    
  }
}
