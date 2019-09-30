import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int[] A = new int[N+2];
    int sum = 0;

    for (int i = 1; i <= N; i++) {
      A[i] = sc.nextInt();
      sum += Math.abs(A[i] - A[i-1]);
    }

    sum += Math.abs(A[N]);

    for (int i = 1; i <= N; i++) {
      int ans = sum;
      ans = ans - Math.abs(A[i] - A[i-1]) - Math.abs(A[i] - A[i+1]) + Math.abs(A[i+1] - A[i-1]);
      System.out.println(ans);
    }
  }
}