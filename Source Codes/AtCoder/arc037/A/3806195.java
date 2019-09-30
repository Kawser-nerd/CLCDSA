import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] m = new int[N];
    for (int i = 0; i < N; i++) {
      m[i] = sc.nextInt();
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (m[i] < 80) {
        ans += 80 - m[i];
      }
    }
    System.out.println(ans);
  }
}