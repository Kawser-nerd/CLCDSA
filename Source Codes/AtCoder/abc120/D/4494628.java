import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Scanner;

public class Main {

  static int mod = 1000000007;

  public static void main(String[] args) throws FileNotFoundException {

//    Scanner cin = new Scanner(new FileReader("input.txt"));
    Scanner cin = new Scanner(System.in);

    int island = cin.nextInt();
    int bridge = cin.nextInt();
    UnionFind UF = new UnionFind(island);

    int[][] connect = new int[bridge][2];

    for (int i=0;i<bridge;i++) {
      int a = cin.nextInt();
      int b = cin.nextInt();
      connect[i][0] = a-1;
      connect[i][1] = b-1;
    }
    long[] res = new long[bridge+1];
    res[bridge] = (long)island*(island-1)/2;
    for (int i=bridge - 1;i>=0;i--) {

      if (UF.find(connect[i][0])==UF.find(connect[i][1]))
        res[i] = res[i+1];
      else {
        res[i] = res[i+1] - (long)UF.size(connect[i][0])*UF.size(connect[i][1]);
        UF.union(connect[i][0], connect[i][1]);
      }

    }

    for (int i=1;i<res.length;i++ ) {
      System.out.println(res[i]);
    }

  }

  //TODO: UnionFind?????
  public static class UnionFind {
    int[] par;
    int[] rank;
    int[] size;

    UnionFind(int n) {
      par = new int[n];
      rank = new int[n];
      size = new int[n];
      for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
        size[i] = 1;
      }
    }

    int find(int x) {
      if (par[x] == x) {
        return x;
      }
      return par[x] = find(par[x]);
    }

    void union(int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) {
        return;
      }
      if (rank[x] < rank[y]) {
        par[x] = y;
        size[y] += size[x];
      } else {
        par[y] = x;
        size[x] += size[y];
        if (rank[x] == rank[y]) {
          rank[x]++;
        }
      }
    }

    boolean same(int x, int y) {
      return find(x) == find(y);
    }

    int size(int x) {
      return size[find(x)];
    }
  }


}