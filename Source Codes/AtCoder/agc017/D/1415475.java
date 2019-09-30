import java.util.*;

public class Main {
  static ArrayList[] edge;
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    edge = new ArrayList[N + 1];
    for(int i = 1; i < N + 1; i++) {
      edge[i] = new ArrayList<Integer>();
    }
    for(int i = 0; i < N - 1; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      edge[x].add(y);
      edge[y].add(x);
    }
    String ans = "Alice";
    if(dfs(1, 0) == 0) ans = "Bob";
    System.out.println(ans);
  }

  public static int dfs(int v, int p) {
    ArrayList<Integer> list = edge[v];
    int ret = 0;
    for(int i = 0; i < list.size(); i++) {
      int u = list.get(i);
      if(u != p) {
        ret = (ret ^ (dfs(u, v) + 1));
      }
    }
    return ret;
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.