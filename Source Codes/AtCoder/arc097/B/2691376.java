import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int p[] = new int[N+1];
    for (int i=1; i<=N; i++) {
      p[i] = sc.nextInt();
    }

    DS ds = new DS(N+1);
    for (int i=1; i<=M; i++) {
      ds.union(sc.nextInt(), sc.nextInt());
    }

    int ans = 0;
    for (int i=1; i<=N; i++) {
      if (p[i] == i) {
        ans++;
      } else if (ds.root(i) == ds.root(p[i])) {
        ans++;
      }
    }
    System.out.println(ans);
  }

  static class DS {
    int[] parent;
    int[] counter;

    DS(int n) {
      parent = new int[n];
      counter = new int[n];
      Arrays.fill(counter, 1);
      Arrays.setAll(parent, i -> i);
    }

    int root(int a) {
      if (parent[a] == a) {
        return a;
      } else {
        return parent[a] = root(parent[a]);
      }
    }

    void union(int i, int j) {
      int ri = root(i);
      int rj = root(j);
      if (ri == rj) {
        return;
      }
      if (counter[rj] < counter[ri]) {
        // swap ri and rj to avoid infinite loop (ex. A -> B -> C -> A)
        int s = ri;
        ri = rj;
        rj = s;
      }
      parent[ri] = rj;
      counter[rj] += counter[ri];
    }
  }
}