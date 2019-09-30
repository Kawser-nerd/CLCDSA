import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) a[i] = scanner.nextInt();

    long count = 0;
    int r = 0;
    for (int l = 0; l < N; l++) {
      if (r < l) r = l;
      while (r < N - 1 && a[r + 1] > a[r]) r++;
      count += r - l + 1;
    }
    System.out.println(count);
  }
}