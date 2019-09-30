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
      int a = cin.nextInt();
      int b = cin.nextInt();
      int c = cin.nextInt();
      int d = cin.nextInt();

      System.out.println("Case #" + C + ": " + solve(N, a, b, c, d));

    }

  }

  double solve(int N, long a, int b, int c, int d) {

    int arr[] = new int[N];

    long sum = 0;

    for(int i=0; i<N; ++i) {
      arr[i] = (int)( (i * a + b) % c + d );
      sum += arr[i];
    }

    long LS[] = new long[N];
    long RS[] = new long[N];
    for(int i=0; i<N; ++i) {
      LS[i] = arr[i] + (i > 0 ? LS[i - 1] : 0);
      RS[i] = arr[N - i - 1] + (i > 0 ? RS[i - 1] : 0);
    }

    long LO = 0;
    long HI = sum;

    int pow2 = 1;
    while( pow2 * 2 <= N ) { pow2 *= 2; }

    while( LO + 1 < HI ) {
      long MI = (LO + HI) / 2;
      if( possible(MI, N, pow2, LS, RS, sum) ) { HI = MI; }
      else { LO = MI; }
    }

    // System.err.println(sum + " " + HI + " " + LO);

    return (double)(sum - HI) / sum;

  }

  boolean possible(long req, int N, int pow2, long LS[], long RS[], long sum) {
    long L = getMax(LS, N, pow2, req);
    long R = getMax(RS, N, pow2, req);
    return (sum - L - R) <= req;
  }

  long getMax(long arr[], int N, int pow2, long req) {
    if( arr[0] > req ) { return 0; }
    int index = 0;
    for( ; pow2 > 0; pow2 /= 2 ) {
      if( index + pow2 >= N ) { continue; }
      if( arr[index + pow2] <= req ) { index += pow2; }
    }
    return arr[index];
  }

}
