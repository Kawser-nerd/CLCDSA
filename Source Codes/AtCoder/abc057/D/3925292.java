import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    long[] v = new long[N];
    long[] cv = new long[N];
    for (int i = 0; i < N; i++) v[i] = scanner.nextLong();

    Arrays.sort(v);
    reverse(v);
    for (int i = 0; i < N; i++) {
      cv[i] = v[i];
      if (i > 0) cv[i] += cv[i - 1];
    }
    HashMap<Long, Integer> freq = new HashMap<>();
    for (int i = 0; i < N; i++) freq.put(v[i], freq.getOrDefault(v[i], 0) + 1);
    int[] iv = new int[N];
    int inum = 1;
    iv[0] = 1;
    for (int i = 1; i < N; i++) {
      if (v[i] == v[i - 1]) inum++;
      else inum = 1;
      iv[i] = inum;
    }

    long[][] C = choose(N);
    int imax = 1;
    long smax = 0;
    long count = 0;
    for (int i = A; i <= B; i++) {
      long s = cv[i - 1];
      // if (s/i > smax/imax)
      if (s * imax > smax * i) {
        imax = i;
        smax = s;
        count = C[freq.get(v[i - 1])][iv[i - 1]];
      } else if (s * imax == smax * i) {
        count += C[freq.get(v[i - 1])][iv[i - 1]];
      }
    }
    System.out.println(smax * 1.d / imax);
    System.out.println(count);
  }

  private static void reverse(long[] a) {
    int i = 0;
    int j = a.length - 1;
    while (i < j) {
      swap(a, i, j);
      i++;
      j--;
    }
  }

  private static void swap(long[] a, int i, int j) {
    long tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }

  public static long[][] choose(int n) {
    long[][] C = new long[n + 1][n + 1];
    for (int i = 0; i <= n; i++) C[i][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
      }
    }
    return C;
  }
}