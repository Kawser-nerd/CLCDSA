import java.util.*;

public class A {

  static Scanner in;

  public static void main(String[] args) {
    in = new Scanner(System.in);
    int T = in.nextInt();
    for (int C = 1; C <= T; C++) {
      System.out.println("Case #" + C + ":");
      solve();
    }
  }

  static void solve() {
    int R = in.nextInt();
    int C = in.nextInt();

    char[][] cake = new char[R][C];

    for (int i = 0; i < R; i++) {
      cake[i] = in.next().toCharArray();
    }

    //printCake(cake);

    for (int i = 0; i < R; i++) {
      boolean inRow = false;
      char r = '?';
      for (int j = 0; j < C; j++) {
        if (cake[i][j] != '?') {
          inRow = true;
          if (r == '?') r = cake[i][j];
        }
      }

      if (inRow) {
        for (int j = 0; j < C; j++) {
          if (cake[i][j] == '?') {
            cake[i][j] = r;
          } else {
            r = cake[i][j];
          }
        }
      }
    }

    int start = -1;

    for (int i = 0; i < R; i++) {
      if (cake[i][0] != '?') {
        start = i;
        break;
      }
    }

    for (int i = 0; i < R; i++) {
      if (cake[i][0] != '?') {
        start = i;
      } else {
        for (int j = 0; j < C; j++) {
          cake[i][j] = cake[start][j];
        }
      }
    }

    printCake(cake);
  }

  static void printCake(char[][] c) {
    for (int i = 0; i < c.length; i++) {
      for (int j = 0; j < c[i].length; j++) {
        System.out.print(c[i][j]);
      }
      System.out.println();
    }
  }
}
