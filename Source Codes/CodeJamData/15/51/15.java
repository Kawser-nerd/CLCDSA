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
      int D = cin.nextInt();

      int S[] = new int[N];
      int M[] = new int[N];

      S[0] = cin.nextInt();
      int As = cin.nextInt();
      int Cs = cin.nextInt();
      int Ms = cin.nextInt();

      M[0] = cin.nextInt();
      int Am = cin.nextInt();
      int Cm = cin.nextInt();
      int Mm = cin.nextInt();

      for(int i=1; i<N; ++i) {
        S[i] = (S[i - 1] * As + Cs) % Ms;
        M[i] = (M[i - 1] * Am + Cm) % Mm;
      }

      boolean appear[] = new boolean[1000 * 1000 + 7];
      for(int i=0; i<N; ++i) {
        appear[ S[i] ] = true;
      }

      Tree tree = genTree(N, S, M);

      int max = 0;
      for(int i=Math.max(0, S[0] - D); i<=S[0]; ++i) {
        if( appear[i] ) {
          max = Math.max(max, solve(tree, i, i + D));
        }
      }

      System.out.println("Case #" + C + ": " + max);

    }

  }

  int solve(Tree tree, int min, int max) {
    return tree.nodes - tree.count(min, max);
  }

  Tree genTree(int N, int S[], int M[]) {

    Tree trees[] = new Tree[N];
    for(int i=0; i<N; ++i) {
      trees[i] = new Tree(S[i]);
      if( i > 0 ) {
        int parent = M[i] % i;
        trees[parent].child.add(trees[i]);
      }
    }

    for(int i=N-1; i>=0; --i) {
      trees[i].update();
    }

    return trees[0];

  }

  class Tree {

    int score;
    int nodes;
    List<Tree> child;

    Tree(int score) {
      this.score = score;
      this.nodes = 0;
      child = new ArrayList<Tree>();
    }

    void update() {
      this.nodes = 1;
      for(Tree tree : child) {
        this.nodes += tree.nodes;
      }
    }

    int count(int min, int max) {
      if( min <= score && score <= max ) {
        int ret = 0;
        for( Tree tree : child ) {
          ret += tree.count(min, max);
        }
        return ret;
      }
      else {
        return nodes;
      }
    }

  }

}
