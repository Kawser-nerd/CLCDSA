import java.util.*;
import java.io.*;

public class x {
  static String [] w;
  static int [] a;
  static int j, k, n;

  static String s;

  static int [] cnt;
  static final int MOD = 10009;
  static long tot;

  static void doall (int sp, int ws) {
    if (sp < 0) {
      cnt = new int [26];
      for (int i = 0; i < j; i++) {
        String z = w[a[i]];
        for (int j = 0; j < z.length (); j++) {
          cnt[z.charAt (j) - 'a']++;
        }
      }

      //System.out.println (Arrays.toString (cnt));

      long sum = 0, mul = 1;
      for (int i = 0; i < s.length (); i++) {
        if (s.charAt (i) == '+') {
          sum += mul;
          mul = 1;
        } else
          mul = (mul * cnt[s.charAt (i) - 'a']) % MOD;
      }

      sum += mul;

      int [] f = new int [10];

      f[0] = 1;

      for (int i = 1; i <= j; i++)
        f[i] = f[i - 1] * i;

      int [] ca = new int [20];

      for (int i = 0; i < j; i++)
        ca[a[i]]++;

      int cf = f[j];

      for (int i = 0; i < n; i++)
        cf /= f[ca[i]];

      //System.out.println (sum);
      tot = (tot + sum * cf) % MOD;
    } else {
      for (int i = ws; i < n; i++) {
        a[sp] = i;
        doall (sp - 1, i);
      }
    }
  }


  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int tt = 1; tt <= t; tt++) {
      s = in.next ();
      k = in.nextInt ();
      n = in.nextInt ();
      w = new String [n];
      for (int i = 0; i < n; i++)
        w[i] = in.next ();

      System.out.print ("Case #" + tt + ":");

      a = new int [k];

      for (j = 1; j <= k; j++) {
        tot  = 0;
        doall (j - 1, 0);
        System.out.print (" " + tot);
      }

      System.out.println ();
        


    };
  };
};
