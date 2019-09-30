import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    String S = sc.next();
    String T = sc.next();
    long L = lcm(N, M);
    HashMap<Long, Character> map = new HashMap<>();
    for (int i = 0; i < N; i++) {
      if (!map.containsKey((L / N) * i)) {
        map.put((L / N) * i, S.charAt(i));
      }
    }
    for (int i = 0; i < M; i++) {
      if (map.containsKey((L / M) * i)) {
        if (map.get((L / M) * i) != T.charAt(i)) {
          System.out.println(-1);
          return;
        }
      }
    }
    System.out.println(L);
  }

  public static int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }

  public static long lcm(int a, int b) {
    return (long) a / gcd(a, b) * b;
  }
}