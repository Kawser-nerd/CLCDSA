/**
 * Created at 10:25 on 2019/03/05
 */

import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int N = sc.nextInt();
    int M = sc.nextInt();
    String S = sc.next();
    String T = sc.next();

    int g = gcd(N, M);
    long L = lcm(N, M, g);
    int intervalS = (int)(L / M);
    int intervalT = (int)(L / N);

    for (int i=0; i<g; i++) {
      if (S.charAt(intervalS*i) != T.charAt(intervalT*i)) {
        System.out.println(-1);
        return;
      }
    }

    System.out.println(L);

  }

  static long lcm(long a, long b, long g) {
    return a * b / g;
  }

  static int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
  }

}