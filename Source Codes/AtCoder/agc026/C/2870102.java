import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    String str = scanner.next();
    char[] S = str.toCharArray();

    long count = 0;
    for (int i = 0; i < 1 << N; i++) {
      List<Character> a = new ArrayList<>();
      List<Character> b = new ArrayList<>();
      int num = i;
      for (int j = 0; j < N; j++) {
        int bit = num & 1;
        if (bit == 0) {
          a.add(S[j]);
        } else {
          b.add(S[j]);
        }
        num >>= 1;
      }

      Collections.reverse(a);
      Collections.reverse(b);
      char[] aa = toCharArray(a);
      char[] bb = toCharArray(b);
      count += count(S, aa, bb);
    }

    System.out.println(count);
  }

  private static char[] toCharArray(List<Character> list) {
    char[] res = new char[list.size()];
    for (int i = 0; i < list.size(); i++) {
      res[i] = list.get(i);
    }
    return res;
  }

  private static long count(char[] s, char[] a, char[] b) {
    int n = s.length / 2;
    long[][] dp = new long[a.length + 1][b.length + 1];
    dp[0][0] = 1;
    for (int j = 0; j < b.length + 1; j++) {
      for (int i = 0; i < a.length + 1; i++) {
        if (i > 0 && s[n + i + j - 1] == a[i - 1]) {
          dp[i][j] += dp[i - 1][j];
        }
        if (j > 0 && s[n + i + j - 1] == b[j - 1]) {
          dp[i][j] += dp[i][j - 1];
        }
      }
    }
    return dp[a.length][b.length];
  }
}