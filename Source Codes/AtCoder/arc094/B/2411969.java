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

    long ab = Math.multiplyExact(a, b);
    long i = findUpperRoot(ab);
    if (i == 0) return 0;
    long j = (ab - 1) / i;

    long res = Math.multiplyExact(i, 2);
    if (i == j) res--;
    if (i >= a) res--;

    return res;
  }

  private static long findUpperRoot(long n) {
    long ll = 0;
    long ul = (long) Math.sqrt(n) + 1;
    while (Math.addExact(ll, 1) < ul) {
      long mid = Math.addExact(ll, ul) / 2;
      if (Math.multiplyExact(mid, mid) < n) {
        ll = mid;
      } else {
        ul = mid;
      }
    }
    return ll;
  }
}