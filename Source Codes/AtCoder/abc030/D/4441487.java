import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  private static final BigInteger TWO = BigInteger.valueOf(2);

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int a = scanner.nextInt() - 1;
    BigInteger k = scanner.nextBigInteger();
    int[] b = new int[N];
    for (int i = 0; i < N; i++) b[i] = scanner.nextInt() - 1;

    int n = 0;
    int i1 = a;
    int i2 = a;
    do {
      i1 = b[i1];
      i2 = b[b[i2]];
      n++;
    } while (i1 != i2);

    int m = 0;
    int i3 = a;
    while (i1 != i3) {
      i1 = b[i1];
      i3 = b[i3];
      m++;
    }

    int l;
    if (k.compareTo(BigInteger.valueOf(m)) < 0) {
      l = k.intValue();
    } else {
      l = m + k.subtract(BigInteger.valueOf(m)).mod(BigInteger.valueOf(n)).intValue();
    }
    while (l > 0) {
      a = b[a];
      l--;
    }
    System.out.println(a + 1);
  }
}