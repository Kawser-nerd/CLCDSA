import java.util.*;

public class B {

  String solve(Scanner sc) {
    int R = sc.nextInt();
    int C = sc.nextInt();
    int N = sc.nextInt();
    
    int min = Integer.MAX_VALUE;
    for(int i = 0; i < 1 << (R*C); i++) {
      if(Integer.bitCount(i) == N) {
        int s = 0;
        boolean[][] b = new boolean[R][C];
        for(int r = 0; r < R; r++) {
          for(int c = 0; c < C; c++) {
            b[r][c] = (i & (1 << (r*C + c))) != 0;
            if(b[r][c]) {
              if(r > 0 && b[r-1][c]) {
                s++;
              }
              if(c > 0 && b[r][c-1]) {
                s++;
              }
            }
          }
        }
        min = Math.min(min, s);
      }
    }
    
    return "" + min;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int T = sc.nextInt();
    for(int cs = 1; cs <= T; cs++) {
      String res = new B().solve(sc);
      System.out.println("Case #" + cs + ": " + res);
    }
    
    sc.close();
  }
  
}
