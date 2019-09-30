import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long M = sc.nextLong();
    int[] A = new int[N + 1];
    for (int i = 1; i <= N; i++) {
      A[i] = sc.nextInt();
    }
    long[] B = new long[N + 1];
    B[0] = 0;
    for (int i = 1; i <= N; i++) {
      B[i] = B[i - 1] + A[i];
    }
    TreeMap<Long, Long> map = new TreeMap<>();
    for (int i = 0; i <= N; i++) {
      long key = B[i] % M;
      if (map.containsKey(key)) {
        map.put(key, map.get(key) + 1);
      } else {
        map.put(key, 1L);
      }
    }
    long ans = 0;
    for (Long value : map.values()) {
      if (1L < value) {
        ans += value * (value - 1) / 2;
      }
    }
    System.out.println(ans);
  }
}