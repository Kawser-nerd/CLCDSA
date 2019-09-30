import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int A[] = new int[N+1];
    long ans = 0;
    A[0] = -1;
    for (int i=1; i<=N; i++) {
      A[i] = sc.nextInt();
      if (A[i] - A[i-1] > 1) {
        ans = -1;
        break;
      }
      if (A[i] == 0) {
        continue;
      }
      if (A[i] == 1 || A[i] - A[i-1] == 1) {
        ans++;
      } else {
        ans += A[i];
      }
    }
    System.out.println(ans);
  }
}