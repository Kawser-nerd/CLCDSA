import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int K = scanner.nextInt();
    long sum = 0;
    for (int i = 0; i < N; i++) {
      long a = scanner.nextInt();
      sum += a * (Math.min(i + K, N) - Math.max(i - K + 1, 0) - K + 1);
    }
    System.out.println(sum);
  }
}