import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int C = sc.nextInt();
    int K = sc.nextInt();
    int[] T = new int[N];
    for (int i = 0; i < N; i++) {
      T[i] = sc.nextInt();
    }
    Arrays.sort(T);
    int ans = 1;
    int count = 1;
    int from = T[0];
    int to = T[0] + K;
    for (int i = 1; i < N; i++) {
      if (from <= T[i] && T[i] <= to && count < C) {
        from = T[i];
        count++;
      } else {
        ans++;
        count = 1;
        from = T[i];
        to = T[i] + K;
      }
    }
    System.out.println(ans);
  }
}