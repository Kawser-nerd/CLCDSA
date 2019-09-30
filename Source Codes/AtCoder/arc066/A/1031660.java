import java.util.*;

public class Main {
  private static boolean isPossible(int n, int[] counter) {
    if (n % 2 == 0) {
      for (int i = 1; i < n; i += 2) {
        if (counter[i] != 2) {
          return false;
        }
      }
      for (int i = 0; i < n; i += 2) {
        if (counter[i] != 0) {
          return false;
        }
      }
      return true;
    } else {
      if (counter[0] != 1) {
        return false;
      }
      for (int i = 1; i < n; i += 2) {
        if (counter[i] != 0) {
          return false;
        }
      }
      for (int i = 2; i < n; i += 2) {
        if (counter[i] != 2) {
          return false;
        }
      }
      return true;
    }
  }

  private static long solve(int n, int[] counter) {
    if (!isPossible(n, counter)) {
      return 0;
    }
    long output = 1;
    for (int i = 0; i < n/2; i++) {
      output *= 2;
      output %= 1000000007;
    }
    return output;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = Integer.parseInt(s.next());
    int[] counter = new int[n];
    for (int i = 0; i < n; i++) {
      counter[Integer.parseInt(s.next())]++;
    }
    System.out.println(solve(n, counter));
  }
}