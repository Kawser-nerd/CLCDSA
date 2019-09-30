import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    long[] A = new long[N];
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }
    System.out.println(solve(A) ? "First" : "Second");
  }

  static boolean solve(long[] A) {
    int N = A.length;
    long sum = 0;
    ArrayList<Integer> oddIdx = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      sum += A[i];
      if (A[i] % 2 == 1) {
        oddIdx.add(i);
      }
    }
    sum -= N;
    if (sum % 2 == 1) {
      return true;
    }
    if (oddIdx.size() != 1) {
      return false;
    }
    if (A[oddIdx.get(0)] == 1) {
      return false;
    }
    A[oddIdx.get(0)]--;
    long gcd = A[0];
    for (int i = 1; i < N; i++) {
      gcd = gcd(gcd, A[i]);
    }
    for (int i = 0; i < N; i++) {
      A[i] /= gcd;
    }
    return !solve(A);
  }

  static long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

}