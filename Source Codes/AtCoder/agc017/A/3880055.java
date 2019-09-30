import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int P = sc.nextInt();
    int[] A = new int[N];
    boolean odd = false;
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
      if (A[i] % 2 == 1) {
        odd = true;
      }
    }
    long ans = 1;
    if (odd) {
      for (int i = 0; i < N - 1; i++) {
        ans *= 2;
      }
      System.out.println(ans);
    } else {
      if (P == 1) {
        System.out.println(0);
      } else {
        for (int i = 0; i < N; i++) {
          ans *= 2;
        }
        System.out.println(ans);
      }
    }
  }
}