import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int x = s.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = s.nextInt();
    }
    long sum = 0;
    if (a[0] > x) {
      sum += a[0] - x;
      a[0] = x;
    }
    for (int i = 1; i < n; i++) {
      if (a[i] + a[i-1] > x) {
        sum += a[i] + a[i-1] - x;
        a[i] = x - a[i-1];
      }
    }
    System.out.println(sum);
  }
}