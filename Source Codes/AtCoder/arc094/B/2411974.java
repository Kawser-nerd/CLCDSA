import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int q = scanner.nextInt();
    for (int i = 0; i < q; i++) {
      long a = scanner.nextLong();
      long b = scanner.nextLong();
      System.out.println(solve(a, b));
    }
  }

  private static long solve(long a, long b) {
    if (a > b) return solve(b, a);

    if (a == b) return 2 * a - 2;
    if (a + 1 == b) return 2 * a - 2;

    long ab = a * b;
    long c = findUpperRoot(ab);
    if (c * (c + 1) >= ab) return 2 * c - 2;
    return 2 * c - 1;
  }

  private static long findUpperRoot(long n) {
    long ll = 0;
    long ul = (long) Math.sqrt(n) + 1;
    while (ll + 1 < ul) {
      long mid = (ll + ul) / 2;
      if (mid * mid < n) {
        ll = mid;
      } else {
        ul = mid;
      }
    }
    return ll;
  }
}