import java.util.*;

public class Main {

  public static class Pair {
    int y;
    int x;
    int a;

    public Pair(int y, int x, int a) {
      this.y = y;
      this.x = x;
      this.a = a;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int H = sc.nextInt();
    int W = sc.nextInt();
    int[][] a = new int[H][W];
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        a[i][j] = sc.nextInt();
      }
    }
    Pair[] root = new Pair[H * W];
    int count = 0;
    int sy = 0;
    int sx = 0;
    boolean right = true;
    while (count < H * W) {
      if (W <= sx) {
        sx--;
        sy++;
        right = false;
      } else if (sx < 0) {
        sx++;
        sy++;
        right = true;
      }
      root[count] = new Pair(sy, sx, a[sy][sx]);
      if (right) {
        sx++;
      } else {
        sx--;
      }
      count++;
    }
    boolean[] ans = new boolean[H * W];
    int anscount = 0;
    Arrays.fill(ans, false);
    for (int i = 0; i < H * W - 1; i++) {
      if (root[i].a % 2 == 1) {
        root[i + 1].a++;
        ans[i] = true;
        anscount++;
      }
    }
    System.out.println(anscount);
    for (int i = 0; i < H * W - 1; i++) {
      if (ans[i]) {
        System.out
            .println((root[i].y + 1) + " " + (root[i].x + 1) + " " + (root[i + 1].y + 1) + " " + (root[i + 1].x + 1));
      }
    }
  }
}