import java.io.*;
import java.util.*;


public class Main {
  private static class Tuple {
    public final int a;
    public final long b;
    public Tuple(int a, long b) {
      this.a = a;
      this.b = b;
    }
  }
  public static void main(String[] args) throws Throwable {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    long K = scanner.nextLong();
    Tuple[] ab = new Tuple[N];
    for (int i = 0; i < N; i++) {
      int a = scanner.nextInt();
      int b = scanner.nextInt();
      ab[i] = new Tuple(a, b);
    }
    Arrays.sort(ab, (x, y) -> Integer.compare(x.a, y.a));

    int lastA = -1;
    long k = 0;
    for (int i = 0; k < K && i < N; i++) {
      k += ab[i].b;
      lastA = ab[i].a;
    }

    System.out.println(lastA);
  }
}