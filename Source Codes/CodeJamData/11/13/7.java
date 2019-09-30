import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  int solve(int n, int m, int d[][], int s[][]) {

    int q[] = new int[3];
    for(int i=0; i<n; ++i) {
      if( d[i][2] == 0 ) { ++q[d[i][0]]; }
    }
    for(int i=0; i<m; ++i) {
      if( s[i][2] == 0 ) { ++q[s[i][0]]; }
    }

    int c[][] = new int[n + m][3];
    for(int i=0; i<n+m; ++i) {
      for(int j=0; j<3; ++j) {
        c[i][j] = (i < n ? d[i][j] : s[i-n][j]);
      }
    }

    int ret = 0;

    ArrayList<Integer> A = new ArrayList<Integer>();
  AL:
    for(int i=0; i<n+m; ++i) {
      if( c[i][0] == 2 && c[i][2] == 0 ) {
        for(int j=0; j<A.size(); ++j) {
          int t = A.get(j);
          if( c[t][1] < c[i][1] ) {
            A.add(j, i);
            continue AL;
          }
        }
        A.add(i);
      }
    }

    ArrayList<Integer> B = new ArrayList<Integer>();
  BL:
    for(int i=0; i<n+m; ++i) {
      if( c[i][0] == 1 && c[i][2] == 0 ) {
        for(int j=0; j<B.size(); ++j) {
          int t = B.get(j);
          if( c[t][1] < c[i][1] ) {
            B.add(j, i);
            continue BL;
          }
        }
        B.add(i);
      }
    }

    ArrayList<Integer> C = new ArrayList<Integer>();
  CL:
    for(int i=0; i<n+m; ++i) {
      if( c[i][0] == 0 && c[i][2] == 0 ) {
        for(int j=0; j<C.size(); ++j) {
          int t = C.get(j);
          if( c[t][1] < c[i][1] ) {
            C.add(j, i);
            continue CL;
          }
        }
        C.add(i);
      }
    }

    for(int i=q[2]; i>=0; --i) {
      for(int j=q[1]; j>=0; --j) {
        ret = Math.max(ret, solve(n, m, c, i, j, A, B, C));
      }
    }

    return ret;

  }

  int solve(int n, int m, int c[][], int q2, int q1, ArrayList<Integer> A, ArrayList<Integer> B, ArrayList<Integer> C) {

    // small : q2 == 0;

    boolean used[] = new boolean[n + m];
    int turn = 1;
    int score = 0;
    int avail = n;

  MAIN:
    while( turn > 0 ) {

      // turn > 0;
      for(int i=0; i<Math.min(avail, n+m); ++i) {
        if( used[i] ) { continue; }
        if( c[i][2] > 0 ) {
          avail += c[i][0];
          score += c[i][1];
          turn += c[i][2] - 1;
          used[i] = true;
        }
      }

      // small;
      if( q1 > 0 ) {
        for(int i=0; i<B.size(); ++i) {
          int p = B.get(i);
          if( used[p] || avail <= p ) { continue; }
          avail += c[p][0];
          score += c[p][1];
          --turn;
          used[p] = true;
          --q1;
          continue MAIN;
        }
        break;
      }

      if( q1 > 0 || q2 > 0 ) { throw new Error("ERROR"); }

      for(int i=0; i<C.size(); ++i) {
        int p = C.get(i);
        if( used[p] || avail <= p ) { continue; }
        score += c[p][1];
        --turn;
        used[p] = true;
        if( turn == 0 ) { break; }
      }

      turn = 0;

    }

    return score;

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=1; i<=t; ++i) {

      int n = cin.nextInt();
      int d[][] = new int[n][3];
      for(int j=0; j<n; ++j) {
        for(int k=0; k<3; ++k) { d[j][k] = cin.nextInt(); }
      }

      int m = cin.nextInt();
      int s[][] = new int[m][3];
      for(int j=0; j<m; ++j) {
        for(int k=0; k<3; ++k) { s[j][k] = cin.nextInt(); }
      }

      System.out.print("Case #" + i + ": ");
      System.out.println(solve(n, m, d, s));

    }

  }

}
