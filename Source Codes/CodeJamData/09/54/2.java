import java.util.*;
import java.io.*;
import java.math.*;

public class x {

  static long MOD2 = 1000000007 * 2;

  static void reverse (char [] s) {
    int a = 0, b = s.length - 1;
    while (a < b) {
      char t = s[a]; s[a] = s[b]; s[b] = t;
      ++a; --b;
    }
  }

  static int state;
  static long ccount [];

  static long tp[];

  static void addcounts (char [] L, int LZ) {
    /*for (int i = L.length - 1; i >= LZ; i--)
      System.out.print (L[i]);
    for (int i = LZ - 1; i >= 0; i--)
      System.out.print ('?');
    System.out.println ();*/
    

    int MD = L.length / 2;

    if (LZ <= MD) {

      //System.out.println ("c1");
      for (int i = MD - 1; i >= LZ; i--)
        if (L[i] != L[L.length - i - 1]) {
          ccount[state] += tp[LZ];
          return;
        }

      long v = 0;

      for (int i = LZ - 1; i >= 0; i--)
        v = (v * 10 + (L[L.length - i - 1] - '0')) % MOD2;

      ccount[state] += v;
      state = 1 - state;
      ccount[state] += tp[LZ] - v;
      //System.out.println (ccount[0] + " " + ccount[1]);

    } else {
      //System.out.println ("c2");
      
      ccount[state] += tp[L.length - LZ];

      long reg = 0;
      int rcr = MD, lcr = MD;
      if (L.length % 2 == 0) {
        reg = tp[MD - 1] + tp[MD]; 
        lcr = MD - 1;
      } else reg = tp[MD];

      reg %= MOD2;

      int vr = LZ - MD;

      long rr = (tp[vr - 1] * 5) % MOD2;
      rr = (rr * reg) % MOD2;
      ccount[1 - state] += rr;

      //System.out.println (rr);

      rr = (tp[vr - 1] * 4) % MOD2;
      rr = (rr * reg) % MOD2;
      ccount[state] += rr;

      for (int i = vr - 1; i > 0; i--) {
        --lcr;
        ++rcr;
        //System.out.println (lcr + " " + rcr);
        long creg = (tp[lcr] + tp[rcr]) - reg * 9;
        creg %= MOD2;
        creg = creg * (tp[i - 1]) % MOD2;
        //System.out.println (creg);
        ccount[state] += 9 * creg;
        ccount[state] %= MOD2;
        reg += tp[lcr] + tp[rcr];
        reg %= MOD2;
      }
    }

    ccount[0] %= MOD2;
    ccount[1] %= MOD2;

  }


  public static void main (String args []) throws Exception {
    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    //long [] 

    /*BigInteger [] tp = new BigInteger [110];
    tp[0] = BigInteger.ONE;
    for (int i = 1; i < 110; i++) tp[i] = tp[i - 1].multiply (BigInteger.valueOf (10));
    */

    tp = new long [110];
    tp[0] = 1;

    for (int i = 1; i < 110; i++)
      tp[i] = (tp[i - 1] * 10) % MOD2;

    for (int tt = 1; tt <= t; tt++) {
      /*BigInteger L = in.nextBigInteger ();
      BigInteger R = in.nextBigInteger ();
      */

      char [] L = in.next ().toCharArray ();
      char [] R = in.next ().toCharArray ();

      /*int myl = Integer.parseInt (new String (L));
      int myr = Integer.parseInt (new String (R));


      int ref = 0;

      boolean [] z = new boolean [myr + 1];
      int zsum [] = new int [myr + 1];

      for (int i = myl; i <= myr; i++) {
        String s = "" + i;
        char [] ttt = s.toCharArray ();
        reverse (ttt);
        if (new String (ttt).equals (s)) z[i] = true;
        zsum[i] = zsum [i - 1];
        if (z[i]) ++zsum[i];
        //if (z[i]) System.out.println (i);
      }

      long sans = 0;

      for (int i = myl; i <= myr; i++) {
        for (int j = i; j <= myr; j++) {
          int ccnt = zsum[j] - zsum[i - 1];
          /*for (int k = i; k <= j; k++)
            if (z[k]) ++ccnt;*/
          /*if (ccnt % 2 == 0) ++sans;
        }
      }

      System.out.println (sans);*/



            


      reverse (L);
      reverse (R);

      /*int LLen = L.toString ().length ();
      int RLen = R.toString ().length ();
      int LZ = 0, RZ = 0;
      */

      state = 0;

      ccount = new long [2];
      ccount[0] = 1;

      int k = L.length + 1;
      if (L.length == R.length) {
        k--;
        for (int i = L.length - 1; i >= 0; i--)
          if (L[i] == R[i]) k = i; else break;
      }

      int LZ = 0;

      addcounts (L, 0);

      while (LZ < k - 1) {
        ++L[LZ];
        if (L[LZ] > '9') {
          L[LZ] = '0';
          ++LZ;
        } else addcounts (L, LZ);
      }


      if (L.length < R.length) {
        int LL = L.length + 1;
        while (LL < R.length) {
          L = new char[LL];
          for (L[LL - 1] = '1';L[LL - 1] <= '9'; L[LL - 1]++)
            addcounts (L, LL - 1);
          ++LL;
        }

        L = new char [R.length];
        Arrays.fill (L, '0');
      
        LZ = L.length - 1;
        L[LZ] = '1';

      } else if (k > 0) ++L[k - 1];


      while (LZ >= 0) {
        while (L[LZ] < R[LZ]) {
          addcounts (L, LZ);
          ++L[LZ];
        }
        --LZ;
      }
      if (k > 0) addcounts (R, 0);

      long ans = 0;

      ccount[0] %= MOD2;
      ccount[1] %= MOD2;

      ans += (ccount[0] * (ccount[0] - 1)) % MOD2;
      ans += (ccount[1] * (ccount[1] - 1)) % MOD2;

      ans %= MOD2;

      ans /= 2;

      System.out.println ("Case #" + tt + ": " + ans);


    };
  };
};
