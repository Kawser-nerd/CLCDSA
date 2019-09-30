import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[][] boxes = new int[N][2];
    for (int i = 0; i < N; i++) boxes[i] = new int[]{scanner.nextInt(), scanner.nextInt()};
    Arrays.sort(boxes, (b1, b2) -> {
      if (b1[0] != b2[0]) return b1[0] - b2[0];
      return b2[1] - b1[1];
    });

    int[] dp = new int[N];
    int INF = 1_000_000;
    for (int i = 0; i < N; i++) dp[i] = INF;
    for (int i = 0; i < N; i++) dp[upperBound(dp, boxes[i][1]) + 1] = boxes[i][1];
    System.out.println(upperBound(dp, INF) + 1);
  }

  private static int upperBound(int[] a, int k) {
    int left = -1;
    int right = a.length;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (a[mid] < k) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return left;
  }
}