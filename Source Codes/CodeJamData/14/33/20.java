import java.util.*;

class C {
  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    for (int tc = 1, tcc = sc.nextInt(); tc <= tcc; ++tc) {
      int n = sc.nextInt();
      int m = sc.nextInt();
      int k = sc.nextInt();
      boolean[][] grid = new boolean[m][n];
      int best = m * n;
      for (int bm = 0; bm < (1 << (m * n)); ++bm) {
        int cur = 0;
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            grid[i][j] = 0 != (bm & (1 << (n * i + j)));
            if (grid[i][j]) ++cur;
          }
        }
        if (cur < best && enclose(grid) >= k) {
          best = cur;

/*
          System.err.println(cur);
          for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
              grid[i][j] = 0 != (bm & (1 << (n * i + j)));
            }
          }
          for (boolean[] row: grid) System.err.println(Arrays.toString(row).replaceAll("true", "1").replaceAll("false", "0").replaceAll("[^01]+", ""));
          System.err.println(enclose(grid));
          for (boolean[] row: grid) System.err.println(Arrays.toString(row).replaceAll("true", "1").replaceAll("false", "0").replaceAll("[^01]+", ""));
          System.err.println();
*/
        }
      }
      System.out.printf("Case #%d: %d%n", tc, best);
    }
  }

  static int[] di = {-1, 1, 0, 0};
  static int[] dj = {0, 0, -1, 1};

  static int enclose(boolean[][] grid) {
    int ret = 0;
    for (boolean[] row: grid) for (boolean val: row) if (val) ++ret;
    int m = grid.length;
    int n = grid[0].length;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != 0 && j != 0 && i != m - 1 && j != n - 1) continue;
        if (grid[i][j]) continue;
        Queue<int[]> q = new LinkedList<int[]>();
        q.add(new int[] {i, j});
        grid[i][j] = true;
        do {
          int[] cur = q.poll();
          for (int d = 0; d < di.length; ++d) {
            int ni = cur[0] + di[d];
            int nj = cur[1] + dj[d];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
            if (grid[ni][nj]) continue;
            q.add(new int[] {ni, nj});
            grid[ni][nj] = true;
          }
        } while (!q.isEmpty());
      }
    }    
    for (boolean[] row: grid) for (boolean val: row) if (!val) ++ret;
    return ret;
  }
}
