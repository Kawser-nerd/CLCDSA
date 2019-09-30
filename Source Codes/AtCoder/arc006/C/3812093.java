import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] w = new int[N];
    int[] y = new int[N];
    for (int i = 0; i < N; i++) {
      w[i] = sc.nextInt();
    }
    for (int i = 0; i < N; i++) {
      y[i] = 100001;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (w[i] <= y[j]) {
          y[j] = w[i];
          break;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (y[i] != 100001) {
        ans++;
      }
    }
    System.out.println(ans);
  }
}