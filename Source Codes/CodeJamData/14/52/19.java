import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int P = cin.nextInt();
      int Q = cin.nextInt();
      int N = cin.nextInt();
      int HP[] = new int[N];
      int GOLD[] = new int[N];
      for(int i=0; i<N; ++i) {
        HP[i] = cin.nextInt();
        GOLD[i] = cin.nextInt();
      }

      System.out.println("Case #" + C + ": " + solve(P, Q, HP, GOLD, N));

    }

  }

  int solve(int P, int Q, int HP[], int GOLD[], int N) {

    int SIZE = N * 10 + 100;
    int score[] = new int[SIZE];
    score[1] = 1;

    for(int i=0; i<N; ++i) {
      int next[] = new int[SIZE];
      int turn = HP[i] / Q;
      int rest = HP[i] - Q * turn;
      if( rest == 0 ) {
        rest = Q;
        --turn;
      }
      int req = (rest + P - 1) / P;
      for(int j=0; j<SIZE; ++j) {
        if( score[j] == 0 ) { continue; }
        // skip this;
        // assert(rest > 0);
        int index = j + turn + 1;
        next[index] = Math.max(next[index], score[j]);
        // try to kill;
        if( req <= j + turn ) {
          int index2 = j + turn - req;
          next[index2] = Math.max(next[index2], score[j] + GOLD[i]);
        }
      }
      score = next;
    }

    int ret = 0;
    for(int i=0; i<SIZE; ++i) {
      ret = Math.max(ret, score[i]);
    }
    return ret - 1;

  }

}
