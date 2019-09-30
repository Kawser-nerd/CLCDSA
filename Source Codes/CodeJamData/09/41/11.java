import java.util.*;
import java.io.*;

public class x {
  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      int n = in.nextInt ();
      char [][] s = new char [n][];
      for (int i = 0; i < n; i++)
        s[i] = in.next ().toCharArray ();
      int [] l = new int [n];

      for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--) {
          l[i] = j;
          if (s[i][j] == '1') break;
        }

      int ans = 0;

      for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = i; j < n; j++)
          if (l[j] <= i) {
            k = j; break;
          }
          ans += k - i;
          for (int j = k; j > i; j--)
            l[j] = l[j - 1];
      }

      System.out.println ("Case #" + tt + ": " + ans);
    };
  };
};