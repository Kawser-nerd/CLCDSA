import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    long[] t = new long[n];
    long[] a = new long[n];
    for (int i = 0; i < n; i++) {
      t[i] = s.nextLong();
      a[i] = s.nextLong();
    }
    long ct = t[0];
    long ca = a[0];
    for (int i = 1; i < n; i++) {
      long kt = ct / t[i] + (ct % t[i] > 0 ? 1 : 0);
      long ka = ca / a[i] + (ca % a[i] > 0 ? 1 : 0);
      long k = Math.max(kt, ka);
      ct = k * t[i];
      ca = k * a[i];
    }
    System.out.println(ct + ca);
  }
}