import java.util.*;
import java.awt.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int[] A = new int[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }

    long ans = 0;
    int prev_a = -1;

    for (int i = N-1; i >= 0; i--) {
      if (A[i] >= prev_a - 1 && A[i] <= i) {
        if (A[i] > prev_a - 1) {
          ans += A[i];
        }
        prev_a = A[i];
      } else {
        ans = -1;
        break;
      }
    }

    System.out.println(ans);
  }
}