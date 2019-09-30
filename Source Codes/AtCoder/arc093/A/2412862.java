import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int[] a = new int[n + 2];
    a[0] = 0;
    a[n + 1] = 0;
    long s = 0;
    for (int i = 0; i < n; i++) {
      a[i + 1] = scanner.nextInt();
      s += Math.abs(a[i + 1] - a[i]);
    }
    s += Math.abs(a[n + 1] - a[n]);
    s -= Math.abs(a[1] - a[0]);
    for (int i = 1; i <= n; i++) {
      if (i > 1) s += Math.abs(a[i - 1] - a[i - 2]);
      s += Math.abs(a[i + 1] - a[i - 1]);
      if (i > 1) s -= Math.abs(a[i] - a[i - 2]);
      s -= Math.abs(a[i + 1] - a[i]);
      System.out.println(s);
    }
  }
}