import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    long K = scanner.nextLong();

    long n = 1;
    double s = 1.d;
    for (long i = 1; i <= K; i++) {
      long x = n;
      long z = 0;
      long y = 1;
      while (x > 0) {
        x /= 10;
        z = z * 10 + 9;
        y *= 10;
        long t = x * y + z;
        double ts = sunuke(t);
        if (ts < s) {
          n = t;
          s = ts;
        }
      }
      System.out.println(n);
      n++;
      s = sunuke(n);
    }
  }

  private static double sunuke(long n) {
    return (double) n / sumDigits(n);
  }

  private static long sumDigits(long i) {
    long sum = 0;
    while (i > 0) {
      sum += i % 10;
      i /= 10;
    }
    return sum;
  }

  private static long numDigits(long i) {
    long d = 0;
    while (i > 0) {
      d++;
      i /= 10;
    }
    return d;
  }
}