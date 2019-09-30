import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] A = new long[N];
    long[] B = new long[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextLong();
      B[i] = sc.nextLong();
    }
    long ans = 0;
    for (int i = N - 1; i >= 0; i--) {
      A[i] += ans;
      long tmp = 0;
      if (A[i] % B[i] != 0) {
        tmp = B[i] - (A[i] % B[i]);
      }
      ans += tmp;
    }
    System.out.println(ans);
  }
}