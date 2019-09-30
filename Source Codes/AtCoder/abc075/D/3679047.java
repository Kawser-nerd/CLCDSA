import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int K = scanner.nextInt();

    int[][] pts = new int[N][2];
    int[] x = new int[N];
    int[] y = new int[N];

    for (int i = 0; i < N; i++) {
      x[i] = scanner.nextInt();
      y[i] = scanner.nextInt();
      pts[i][0] = x[i];
      pts[i][1] = y[i];
    }

    Arrays.sort(x);
    Arrays.sort(y);

    long min = Long.MAX_VALUE;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        for (int k = 0; k < N; k++) {
          for (int l = k + 1; l < N; l++) {
            long left = x[i];
            long right = x[j];
            long bottom = y[k];
            long top = y[l];

            int count = 0;
            for (int m = 0; m < N; m++)
              if (pts[m][0] >= left
                  && pts[m][0] <= right
                  && pts[m][1] >= bottom
                  && pts[m][1] <= top) {
                count++;
              }
            if (count >= K) min = Math.min(min, Math.abs(right - left) * Math.abs(top - bottom));
          }
        }
      }
    }
    System.out.println(min);
  }
}