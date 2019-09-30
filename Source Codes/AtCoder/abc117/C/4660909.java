import java.util.Arrays;
import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    int[] x = new int[m];
    for (int i = 0; i < m; i++) {
      x[i] = scanner.nextInt();
    }
    if (n >= m) {
      System.out.println(0);
      return;
    }
    Arrays.sort(x);
    int[] d = new int[m - 1];
    for (int i = 0; i < m - 1; i++) {
      d[i] = x[i + 1] - x[i];
    }
    Arrays.sort(d);
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
      sum += d[d.length - i - 1];
    }
    System.out.println(x[m - 1] - x[0] - sum);
  }

}