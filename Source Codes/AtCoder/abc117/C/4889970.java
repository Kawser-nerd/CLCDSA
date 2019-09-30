import java.util.Arrays;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] x = new int[M];
    for (int i = 0; i < M; i++) {
      x[i] = sc.nextInt();
    }
    Main abc117C = new Main();
    System.out.println(abc117C.solve(N, x));
  }

  public int solve(int N, int[] x) {
    Arrays.sort(x);
    int[] diffs = new int[x.length - 1];
    for (int i = 0; i < x.length - 1; i++) {
      diffs[i] = x[i + 1] - x[i];
    }
    Arrays.sort(diffs);
    int ans = 0;
    for (int i = 0; i < diffs.length - N + 1; i++) {
      ans += diffs[i];
    }
    return ans;
  }
}