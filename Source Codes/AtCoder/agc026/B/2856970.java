import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt();
    for (int i = 0; i < T; i++) {
      long A = scanner.nextLong();
      long B = scanner.nextLong();
      long C = scanner.nextLong();
      long D = scanner.nextLong();
      if (solve(A, B, C, D)) {
        System.out.println("Yes");
      } else {
        System.out.println("No");
      }
    }
  }

  static boolean solve(long A, long B, long C, long D) {
    if (A < B) return false;
    if (D < B) return false;
    if (C > B) return true;

    long gcd = gcd(B, D);
    long max = ((B - 1 - (A % B)) / gcd) * gcd + (A % B);
    return max <= C;
  }

  public static long gcd(long i, long j) {
    if (i > j) return gcd(j, i);
    if (i == 0) return j;
    long r = j % i;
    return gcd(r, i);
  }
}