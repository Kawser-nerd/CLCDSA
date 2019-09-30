import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    Box[] boxes = new Box[N];
    for (int i = 0; i < N; i++) boxes[i] = new Box(scanner.nextInt(), scanner.nextInt());
    Arrays.sort(boxes, (b1, b2) -> {
      if (b1.w != b2.w) return b1.w - b2.w;
      return b2.h - b1.h;
    });

    int[] dp = new int[N];
    int INF = 1_000_000;
    for (int i = 0; i < N; i++) dp[i] = INF;
    for (int i = 0; i < N; i++) {
      int j = lowerBound(dp, boxes[i].h);
      if (j == 0 || dp[j - 1] < boxes[i].h) dp[j] = boxes[i].h;
    }

    int max = 0;
    for (int i = 0; i < N; i++) if(dp[i] < INF) max = Math.max(max, i + 1);
    System.out.println(max);
  }

  private static int lowerBound(int[] a, int k) {
    int left = -1;
    int right = a.length;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (k < a[mid]) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return right;
  }

  private static class Box {
    public final int w;
    public final int h;

    private Box(int w, int h) {
      this.w = w;
      this.h = h;
    }
  }
}