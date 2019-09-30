import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int x = sc.nextInt();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) {
      a[i] = sc.nextInt();
    }
    Arrays.sort(a);
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
      if (a[i] <= x) {
        x -= a[i];
        ans++;
      }
    }
    if (a[N - 1] == x) {
      ans++;
    }
    System.out.println(ans);
  }
}