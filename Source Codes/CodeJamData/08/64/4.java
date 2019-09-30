import java.util.*;

public class D {

  public static void main(String args[]) {
    (new D()).exec();
  }

  void exec() {

    Scanner cin = new Scanner(System.in);

    int y = cin.nextInt();
    for(int z=0; z<y; ++z) {
      int n = cin.nextInt();
      int t[][] = new int[n][2];
      for(int i=0; i<n-1; ++i) {
        t[i][0] = cin.nextInt();
        t[i][1] = cin.nextInt();
      }
      int m = cin.nextInt();
      int u[][] = new int[m][2];
      for(int i=0; i<m-1; ++i) {
        u[i][0] = cin.nextInt();
        u[i][1] = cin.nextInt();
      }
      System.out.println("Case #" + (z + 1) + ": " + (sub(t, u, n, m) ? "YES" : "NO"));
    }

  }

  boolean sub(int a[][], int b[][], int n, int m) {

    int cand[] = new int[m];
    return perm(cand, 0, m, n, new boolean[n], a, b);

  }

  boolean perm(int cand[], int check, int m, int n, boolean used[], int a[][], int b[][]) {

    if( check == m ) {
      return test(cand, a, b, n, m);
    }

    for(int i=0; i<n; ++i) {
      if( used[i] ) { continue; }
      used[i] = true;
      cand[check] = i;
      boolean cur = perm(cand, check + 1, m, n, used, a, b);
      if( cur ) { return true; }
      used[i] = false;
    }

    return false;

  }

  boolean test(int cand[], int a[][], int b[][], int n, int m) {

    for(int i=0; i<m-1; ++i) {
      boolean match = false;
      for(int j=0; j<n-1; ++j) {
        int s = cand[ b[i][0] - 1 ] + 1;
        int e = cand[ b[i][1] - 1 ] + 1;
        if( a[j][0] == s && a[j][1] == e ) { match = true; break; }
        if( a[j][0] == e && a[j][1] == s ) { match = true; break; }
      }
      if( !match ) { return false; }
    }

    return true;

  }

}
