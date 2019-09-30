import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String c = sc.next();
    int n = c.length();
    int[][] televi = new int[n][n];
    for(int i = 0; i < n; i++) {
      if(c.charAt(i) == 'o') televi[0][i] = 1;
    }
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < n; j++) {
        televi[i][(j + i) % n] = televi[0][j];
      }
    }
    int ans = 20;
    for(int i = 1; i < (int)Math.pow(2, n); i++) {
      int[] watch = new int[n];
      int count = 0;
      for(int k = 0; k < n; k++) {
        if((i & (1 << k)) != 0) {
          for(int j = 0; j < n; j++) {
            watch[j] += televi[k][j];
          }
          count++;
        }
      }
      boolean flg = true;
      for(int j = 0; j < n; j++) {
        if(watch[j] == 0) flg = false;
      }
      if(flg) ans = Math.min(ans, count);
    }
    System.out.println(ans);
  }
}