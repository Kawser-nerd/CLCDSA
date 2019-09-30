import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] A = new int[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }
    int ans = 1;
    int d = 0;
    for (int i = 1; i < N; i++) {
      if (d == 0) {
        if (A[i - 1] < A[i]) {
          d = 1;
        } else if (A[i - 1] > A[i]) {
          d = -1;
        }
      } else if (d > 0) {
        if (A[i - 1] > A[i]) {
          ans++;
          d = 0;
        }
      } else if (d < 0) {
        if (A[i - 1] < A[i]) {
          ans++;
          d = 0;
        }
      }
    }
    System.out.println(ans);
  }
}