import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int H = scanner.nextInt();
    int W = scanner.nextInt();
    char[][] map = new char[H][W];
    for (int i = 0; i < H; i++) map[i] = scanner.next().toCharArray();

    char[][] sol = new char[H][W];
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) sol[i][j] = '.';

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        boolean allBlack = true;
        for (int k = -1; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            int x = i + k;
            int y = j + l;
            if (x >= 0 && x < H && y >= 0 && y < W) allBlack &= map[x][y] == '#';
          }
        }
        if (allBlack) sol[i][j] = '#';
      }
    }

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (map[i][j] == '.') continue;
        boolean hasBlack = false;
        for (int k = -1; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            int x = i + k;
            int y = j + l;
            if (x >= 0 && x < H && y >= 0 && y < W) hasBlack |= sol[x][y] == '#';
          }
        }
        if (!hasBlack) {
          System.out.println("impossible");
          return;
        }
      }
    }
    System.out.println("possible");
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) System.out.print(sol[i][j]);
      System.out.println();
    }
  }
}