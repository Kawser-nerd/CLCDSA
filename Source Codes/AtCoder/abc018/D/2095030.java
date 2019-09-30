import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

    int n = s.nextInt();
    int m = s.nextInt();
    int p = s.nextInt();
    int q = s.nextInt();
    int r = s.nextInt();

    int[][] score = new int[n][m];
    for (int i = 0; i < r; i++) {
      int x = s.nextInt() - 1;
      int y = s.nextInt() - 1;
      score[x][y] = s.nextInt();
    }

    int topScore = 0;
    for (int i = 0; i < (1 << n); i++) {
      boolean[] xSelected = new boolean[n];
      int xSelectedCount = 0;
      for (int j = 0; j < n; j++) {
        xSelected[j] = (i & (1 << j)) != 0;
        if (xSelected[j]) {
          xSelectedCount++;
        }
      }
      if (xSelectedCount != p) {
        continue;
      }

      int[] yScore = new int[m];
      for (int k = 0; k < m; k++) {
        for (int j = 0; j < n; j++) {
          if (xSelected[j]) {
            yScore[k] += score[j][k];
          }
        }
      }
      Arrays.sort(yScore);
      int sumScore = 0;
      for (int k = 0; k < q; k++) {
        sumScore += yScore[m - 1 - k];
      }
      topScore = Math.max(topScore, sumScore);
    }
    System.out.println(topScore);
  }
}