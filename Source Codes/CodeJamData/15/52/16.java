import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int N = cin.nextInt();
      int K = cin.nextInt();

      int M = N - K + 1;
      int sum[] = new int[M];
      for(int i=0; i<M; ++i) {
        sum[i] = cin.nextInt();
      }

      int min[] = new int[K];
      int max[] = new int[K];
      int cur[] = new int[K];

      for(int i=1; i<M; ++i) {
        int diff = sum[i] - sum[i - 1];
        int index = (i - 1) % K;
        cur[index] += diff;
        min[index] = Math.min(min[index], cur[index]);
        max[index] = Math.max(max[index], cur[index]);
      }

      int ret = 0;
      int pos = 0;
      for(int i=0; i<K; ++i) {
        ret = Math.max(ret, max[i] - min[i]);
        if( ret == max[i] - min[i] ) { pos = i; }
      }

      int Up = 0;
      int Dn = 0;
      for(int i=0; i<K; ++i) {
        Up += max[pos] - max[i];
        Dn += min[pos] - min[i];
      }

      // System.err.println(Up + " " + Dn);
      boolean fit = false;
      int rep = 0;
      for(int i=Math.min(Up, Dn); i<=Math.max(Up, Dn); ++i) {
        fit |= ((sum[0] - i) % K == 0);
        ++rep;
        if( rep >= K ) { break; }
      }

      if( fit == false ) { ++ret; }

      System.out.println("Case #" + C + ": " + ret);

    }

  }

}
