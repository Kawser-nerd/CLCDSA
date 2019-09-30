import java.util.*;

class D {
  static int getMinusDiag(int r, int c, int n) {
    return r - c + n - 1;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int tcc = sc.nextInt();
    for (int tc = 1; tc <= tcc; ++tc) {
      int n = sc.nextInt();
      int m = sc.nextInt();
      char[][] grid = new char[n][n];
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          grid[i][j] = '.';
        }
      }

      boolean[] rowHasNonPlus = new boolean[n];
      boolean[] colHasNonPlus = new boolean[n];
      boolean[] plusDiagHasNonX = new boolean[2 * n - 1];
      boolean[] minusDiagHasNonX = new boolean[2 * n - 1];

      int score = 0;
      for (int i = 0; i < m; ++i) {
        char model = sc.next().charAt(0);
        int r = sc.nextInt() - 1;
        int c = sc.nextInt() - 1;
        if (model != '+') {
          rowHasNonPlus[r] = true;
          colHasNonPlus[c] = true;
        }
        if (model != 'x') {
          plusDiagHasNonX[r + c] = true;
          minusDiagHasNonX[getMinusDiag(r, c, n)] = true;
        }
        score += model == 'o' ? 2 : 1;
        grid[r][c] = model;
      }

      Map<String, Character> changes = new HashMap<String, Character>();
      for (int i = 0; i < n; ++i) {
        if (rowHasNonPlus[i]) {
          continue;
        }
        for (int j = 0; j < n; ++j) {
          if (colHasNonPlus[j]) {
            continue;
          }
          if (grid[i][j] == 'x' || grid[i][j] == 'o') {
            continue;
          }
          grid[i][j] = grid[i][j] == '+' ? 'o' : 'x';
          rowHasNonPlus[i] = true;
          colHasNonPlus[j] = true;
          ++score;
          changes.put((i+1) + " " + (j+1), grid[i][j]);
          break;
        }
      }
      for (int fd = 0; fd < plusDiagHasNonX.length; ++fd) {
        int d = fd % 2 == 0 ? fd / 2 : plusDiagHasNonX.length - 1 - fd / 2;
        if (plusDiagHasNonX[d]) {
          continue;
        }
        for (int i = 0; i < n; ++i) {
          int j = d - i;
          if (j < 0 || j >= n) {
            continue;
          }
          if (minusDiagHasNonX[getMinusDiag(i, j, n)]) {
            continue;
          }
          if (grid[i][j] == '+' || grid[i][j] == 'o') {
            continue;
          }
          grid[i][j] = grid[i][j] == 'x' ? 'o' : '+';
          plusDiagHasNonX[i + j] = true;
          minusDiagHasNonX[getMinusDiag(i, j, n)] = true;
          ++score;
          changes.put((i+1) + " " + (j+1), grid[i][j]);
          break;
        }
      }

      System.out.printf("Case #%d: %d %d\n", tc, score, changes.size());
      for (String key : changes.keySet()) {
        System.out.println(changes.get(key) + " " + key);
      }
    }
  }
}
