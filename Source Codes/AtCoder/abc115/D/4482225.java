import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  static long[] size;
  static long[] patty;

  public static void main(String[] args) {

    int N = sc.nextInt();
    long X = sc.nextLong();

    size = new long[N+1];
    patty = new long[N+1];

    size[0] = 1;
    patty[0] = 1;
    for (int i=1; i<=N; i++) {
      size[i] = size[i-1] * 2 + 3;
      patty[i] = patty[i-1] * 2 + 1;
    }

    System.out.println(f(N, X));
  }

  static long f(int n, long x) {
    if (n == 0) return 1;
    if (x == 1) return 0;
    if (x <= (size[n]-1)/2) {
      return f(n-1, x-1);
    } else if (x == (size[n]-1)/2 + 1) {
      return patty[n-1] + 1;
    } else {
      return patty[n-1] + 1 + f(n-1, x-(size[n]-1)/2-1);
    }
  }
  
}