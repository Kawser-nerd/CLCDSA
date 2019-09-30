import java.util.Arrays;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    final Scanner scanner = new Scanner(System.in);
    final int n = scanner.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = scanner.nextInt();
    }
    Arrays.sort(a);
    final int m = a[n - 1];
    int ans = -1;
    for (int i = 0; i < n - 1; i++) {
      int d = Math.min(a[i], m - a[i]);
      if (d > ans) ans = a[i];
    }
    System.out.println(m + " " + ans);
  }
}