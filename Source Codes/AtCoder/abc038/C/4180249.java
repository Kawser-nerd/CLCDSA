import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) a[i] = scanner.nextInt();

    long count = N;
    int l = 0;
    while (l < N) {
      int r = l + 1;
      while (r < N && a[r] > a[r - 1]) {
        count += r - l;
        r++;
      }
      l = r;
    }
    System.out.println(count);
  }
}