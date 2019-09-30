import java.util.Arrays;
import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int H = scanner.nextInt();
    int W = scanner.nextInt();
    String[] S = new String[H];
    for (int i = 0; i < H; i++) {
      S[i] = scanner.next();
    }
    int[] xs = { -1, 1, 0, 0 };
    int[] ys = { 0, 0, 1, -1 };
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        boolean[] ks = new boolean[4];
        Arrays.fill(ks, false);
        if (S[y].charAt(x) == '#') {
          for (int k = 0; k < 4; k++) {
            if (0 <= x + xs[k] && x + xs[k] < W && 0 <= y + ys[k] && y + ys[k] < H
                && S[y + ys[k]].charAt(x + xs[k]) == '#') {
              ks[k] = true;
            }
          }
          boolean ans = false;
          for (int i = 0; i < 4; i++) {
            if (ks[i]) {
              ans = true;
            }
          }
          if (!ans) {
            System.out.println("No");
            return;
          }
        }
      }
    }
    System.out.println("Yes");
  }

}