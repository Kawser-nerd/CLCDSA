import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    long[] a = new long[N];
    for (int i = 0; i < N; i++) {
      a[i] = scanner.nextLong();
    }

    int l = 0;
    long sum = 0;
    long xor = 0;
    long count = 0;
    for (int r = 0; r < N; r++) {
      sum += a[r];
      xor ^= a[r];
      if (sum == xor) {
        count += r - l + 1;
        continue;
      }
      while (sum != xor) {
        sum -= a[l];
        xor ^= a[l];
        l++;
      }
      count += r - l + 1;
    }

    System.out.println(count);
  }
}