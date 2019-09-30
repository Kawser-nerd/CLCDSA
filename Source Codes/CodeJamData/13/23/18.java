import java.io.FileInputStream;
import java.util.*;
import java.math.*;

public class Main {
  static int[][] dp;
  static HashSet<String> dict = new HashSet<String>();
  static int maxLen = 10;
  static char[] arr;
  
  static void init() throws Exception {
    Scanner scan = new Scanner(new FileInputStream("garbled_email_dictionary.txt"));
    for (int i = 0; i < 521196; i++) {
      String word = scan.nextLine();
      dict.add(word);
    }
    scan.close();
    
    dp = new int[4001][5];
  }
  
  static boolean check(char[] temp) {
    return dict.contains(new String(temp));
  }
  
  static boolean check(char[] temp, int a) {
    char ca = temp[a];
    boolean res = false;
    for (char c1 = 'a'; c1 <= 'z'; c1++) {
      if (c1 == ca) {
        continue;
      }
      temp[a] = c1;
      if (check(temp)) {
        res = true;
        break;
      }
    }
    temp[a] = ca;
    return res;
  }
  
  static boolean check(char[] temp, int a, int b) {
    char ca = temp[a];
    boolean res = false;
    for (char c1 = 'a'; c1 <= 'z'; c1++) {
      if (c1 == ca) {
        continue;
      }
      temp[a] = c1;
      if (check(temp, b)) {
        res = true;
        break;
      }
    }
    temp[a] = ca;
    return res;
  }
  
  public static void main(String[] args) throws Exception {
    init();
    Scanner scan = new Scanner(System.in);
    int taskCount = scan.nextInt();
    scan.nextLine();
    for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
      arr = scan.nextLine().toCharArray();
      int N = arr.length;
      for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 5; j++) {
          dp[i][j] = Integer.MAX_VALUE;
        }
      }
      dp[0][0] = 0;
      for (int i = 1; i <= N; i++) {
        for (int j = Math.max(0, i - maxLen); j < i; j++) {
          char[] temp = new char[i - j];
          for (int k = 0, m = j; k < temp.length; k++, m++) {
            temp[k] = arr[m];
          }
          boolean pass = check(temp);
          for (int k = 0; k < 5; k++) {
            if (dp[j][k] == Integer.MAX_VALUE) {
              continue;
            }
            if (pass) {
              int nk = Math.max(0, k - temp.length);
              dp[i][nk] = Math.min(dp[i][nk], dp[j][k]);
            } else {
              for (int m = k; m < temp.length; m++) {
                if (check(temp, m)) {
                  int nk = Math.max(0, 5 + m - temp.length);
                  dp[i][nk] = Math.min(dp[i][nk], dp[j][k] + 1);
                }
                for (int n = m + 5; n < temp.length; n++) {
                  if (check(temp, m, n)) {
                    int nk = Math.max(0, 5 + n - temp.length);
                    dp[i][nk] = Math.min(dp[i][nk], dp[j][k] + 2);
                  }
                }
              }
            }
          }
        }
      }
      
      int res = N;
      for (int i = 0; i < 5; i++) {
        res = Math.min(res, dp[N][i]);
      }
      System.out.println(String.format("Case #%d: %d", taskIndex, res));
    }
  }
}
