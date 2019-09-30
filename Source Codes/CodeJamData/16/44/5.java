import java.util.*;
import static java.lang.Math.*;

public class D {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int zz = 1; zz <= T; zz++) {
      int N = in.nextInt();
      parent = new int[N * 2];
      int count = 0;
      for (int i = 0; i < parent.length; i++)
        parent[i] = i;
      for (int i = 0; i < N; i++) {
        String S = in.next();
        for (int j = 0; j < N; j++) {
          if (S.charAt(j) == '1') {
            merge(i+N, j);
            count++;
          }
        }
      }
      HashMap<Integer, Integer> groups = new HashMap<Integer, Integer>();
      int[][] G = new int[2*N][2];
      for (int i = 0; i < parent.length; i++) {
        if (!groups.containsKey(find(i)))
          groups.put(find(i), groups.size());
        G[groups.get(find(i))][i < N ? 0 : 1]++;
      }
      int a = 0;
      int b = 0;
      int at = 0;
      int[][] H = new int[groups.size()][2];
      for (int i = 0; i < groups.size(); i++) {
        if (G[i][0] == 1 && G[i][1] == 0) {
          a++;
        } else if (G[i][0] == 0 && G[i][1] == 1) {
          b++;
        } else {
          H[at][0] = G[i][0];
          H[at][1] = G[i][1];
          at++;
        //    System.out.println("\t"+G[i][0]+" "+G[i][1]);
        }
      }
      //System.out.println(a+" "+b);
      int[][][] cost = new int[a+1][b+1][1<<at];
      int[][][] ans = new int[a+1][b+1][1<<at];
      for (int aa = 0; aa <= a; aa++) {
        for (int bb = 0; bb <= b; bb++) {
          for (int s = 0; s < (1 << at); s++) {
            ans[aa][bb][s] = 10000000;
            int x = aa;
            int y = bb;
            for (int i = 0; i < at; i++) {
              if (((1<<i) & s) != 0) {
                x += H[i][0];
                y += H[i][1];
              }
            }
            if (x == y)
              cost[aa][bb][s] = x*x;
            else
              cost[aa][bb][s] = -1;
            //System.out.println("cost: "+aa+" "+bb+" "+s+" "+cost[aa][bb][s]);
          }
        }
      }
      ans[0][0][0] = 0;
      for (int aa = 0; aa <= a; aa++) {
        for (int bb = 0; bb <= b; bb++) {
          for (int s = 0; s < (1 << at); s++) {
            for (int da = 0; da <= aa; da++) {
              for (int db = 0; db <= bb; db++) {
                for (int ds = s; ; ds = (ds-1) & s) {
                  int c = cost[da][db][ds];
                  if (c != -1) {
                    //System.out.println((aa-da)+" "+(bb-db)+" "+(s-ds));
                    ans[aa][bb][s] = min(ans[aa][bb][s], c + ans[aa-da][bb-db][s-ds]);
                  }
                  if (ds == 0) {
                    break;
                  }
                }
              }
            }
          }
        }
      }
      System.out.format("Case #%d: %d\n", zz, ans[a][b][(1<<at)-1] - count);

    }
  }
  static int find(int p) {
    if (parent[p] != p)
      parent[p] = find(parent[p]);
    return parent[p];
  }
  static void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    parent[pa] = pb;
  }
  static int[] parent;
}
