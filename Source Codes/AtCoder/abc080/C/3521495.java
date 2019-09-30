import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] f = new int[N];
    for (int i = 0; i < N; i++) {
      int n = 0;
      for (int j = 0; j < 10; j++) {
        n = n << 1;
        n += scanner.nextInt();
      }
      f[i] = n;
    }
    int[][] p = new int[N][11];
    for (int i = 0; i < N; i++) for (int j = 0; j < 11; j++) p[i][j] = scanner.nextInt();

    int max = Integer.MIN_VALUE;
    for (int i = 1; i < 1 << 10; i++) {
      int b = 0;
      for (int j = 0; j < N; j++) b += p[j][Integer.bitCount(f[j] & i)];
      if (b > max) max = b;
    }
    System.out.println(max);
  }
}