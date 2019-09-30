import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();

    final int MAX = 55_555;
    final boolean[] isPrimse = new boolean[MAX + 1];
    for (int i = 2; i <= MAX; i++) isPrimse[i] = true;
    for (int i = 2; i < Math.sqrt(MAX); i++) {
      if (isPrimse[i]) {
        for (int j = 2; i * j <= MAX; j++) {
          isPrimse[i * j] = false;
        }
      }
    }
    int count = 0;
    for (int i = 2; i <= MAX && count < N; i++) {
      if (isPrimse[i] && i % 5 == 1) {
        System.out.printf("%d ", i);
        count++;
      }
    }
    System.out.println();
  }
}