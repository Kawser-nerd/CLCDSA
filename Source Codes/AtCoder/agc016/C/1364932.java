import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int H = sc.nextInt();
    int W = sc.nextInt();
    int h = sc.nextInt();
    int w = sc.nextInt();
    if((H % h == 0) && (W % w == 0)) {
      System.out.println("No");
    } else {
      System.out.println("Yes");
      int[][] ans = new int[H][W];
      if(H % h == 0) {
        for(int i = 0; i < H; i++) {
          for(int j = 0; j < W; j++) {
            if(j % w == 0) {
              ans[i][j] = 1000 * w - 1001;
            } else {
              ans[i][j] = -1000;
            }
          }
        }
      } else {
        for(int i = 0; i < H; i++) {
          for(int j = 0; j < W; j++) {
            if(i % h == 0) {
              ans[i][j] = 1000 * h - 1001; 
            } else {
              ans[i][j] = -1000;
            }
          }
        }
      }
      for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
          System.out.print(ans[i][j]);
          if(j < W - 1) {
            System.out.print(" ");
          } else {
            System.out.println();
          }
        }
      }
    }
  }
}