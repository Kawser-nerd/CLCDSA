import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] t = new int[N + 1];
    int[] v = new int[N + 2];

    for (int i = 0; i < N; i++) t[i + 1] = scanner.nextInt() * 2 + t[i];
    for (int i = 0; i < N; i++) v[i + 1] = scanner.nextInt() * 2;

    long dist = 0;
    long cv = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = t[i - 1] + 1; j <= t[i]; j++) {
        long f = v[i];
        for (int k = 0; k < i; k++) f = Math.min(f, v[k] + j - t[k]);
        for (int k = i + 1; k <= N + 1; k++) f = Math.min(f, v[k] + t[k - 1] - j);
        dist += cv + f;
        cv = f;
      }
    }

    System.out.println(dist / 8.d);
  }
}