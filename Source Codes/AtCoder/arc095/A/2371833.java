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
    int[] b = Arrays.copyOf(a, a.length);
    Arrays.sort(b);
    int mid = b[n / 2 - 1];
    int mid1 = b[n / 2];
    for (int i = 0; i < n; i++) {
      if (a[i] <= mid) System.out.println(mid1);
      else System.out.println(mid);
    }
  }
}