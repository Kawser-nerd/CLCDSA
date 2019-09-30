import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long[] a = new long[n];
    for(int i = 0; i < n; i++) {
      a[i] = sc.nextLong();
    }
    long[] sum = new long[n];
    sum[0] = a[0];
    for(int i = 1; i < n; i++) {
      sum[i] = sum[i - 1] + a[i]; 
    }
    long ans = Long.MAX_VALUE;
    for(int i = 0; i < n - 1; i++) {
      long x = sum[i];
      long y = sum[n - 1] - sum[i];
      ans = Math.min(ans, Math.abs(x - y));
    }
    System.out.println(ans);
  }
}