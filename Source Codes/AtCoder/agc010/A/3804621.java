import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] A = new int[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }
    long sum = 0;
    for (int i = 0; i < N; i++) {
      sum += A[i];
    }
    if (sum % 2 == 0) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }
}