import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int A[] = new int[N+1];
    // diff[i] = | A[i] - A[i-1] |
    int diff[] = new int[N+2];
    // diff2[i] = | A[i+1] - A[i-1] |
    int diff2[] = new int[N+1];
    long sum = 0;
    A[0] = 0;
    for (int i=1;i<=N; i++) {
      A[i] = sc.nextInt();
      diff[i] = Math.abs(A[i] - A[i-1]);
      sum += diff[i];
      if (i>1) {
        diff2[i-1] = Math.abs(A[i] - A[i-2]);
      }
    }
    diff[N+1] = Math.abs(A[N]);
    sum += diff[N+1];
    diff2[N] = Math.abs(A[N-1]);

    for (int i=1; i<=N; i++) {
      long tmp = sum;
      tmp -= diff[i];
      tmp -= diff[i+1];
      tmp += diff2[i];
      System.out.println(tmp);
    }
  }
}