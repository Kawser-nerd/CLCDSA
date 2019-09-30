import java.util.*;

public class z {
  public static void main (String args []) {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int i = 1; i <= t; i++) {
      int n = in.nextInt ();
      long [] A = new long [n];
      long [] B = new long [n];
      for (int j = 0; j < n; j++)
        A[j] = in.nextInt ();
      for (int j = 0; j < n; j++)
        B[j] = in.nextInt ();
      Arrays.sort (A);
      Arrays.sort (B);

      long ans = 0;

      for (int j = 0; j < n; j++)
        ans += A[j] * B[n - j - 1];

      System.out.println ("Case #" + i + ": " + ans);
    };
  };
};