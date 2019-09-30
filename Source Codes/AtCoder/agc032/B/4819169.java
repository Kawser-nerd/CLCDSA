import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int M = N * (N - 2) / 2 + N % 2;
    System.out.println(M);
    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (j == N - i + 1 - N % 2) continue;
        System.out.printf("%d %d\n", i, j);
      }
    }
  }
}