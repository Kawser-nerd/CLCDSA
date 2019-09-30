import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    long N = scanner.nextInt();
    long K = scanner.nextInt();

    System.out.println(((K - 1) * (N - K) * 6 + (N - 1) * 3 + 1) / (double) (N * N * N));
  }
}