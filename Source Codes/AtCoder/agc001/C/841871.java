import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {
  static final int INF = Integer.MAX_VALUE;
  static int n, k;
  static List< List< Integer > > G;
  static int[][] edges;

  static int[] dist;
  static int count;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt(); k = sc.nextInt();
    G = new ArrayList< List< Integer > >(n);
    for(int i = 0; i < n; i++){
      G.add(new ArrayList< Integer >());
    }

    edges = new int[n - 1][2];
    for(int i = 0; i < n - 1; i++){
      int v = sc.nextInt() - 1, w = sc.nextInt() - 1;
      G.get(v).add(w);  G.get(w).add(v);
      edges[i][0] = v;  edges[i][1] = w;
    }

    int ans = INF;
    if(k % 2 == 0){
      int d = k / 2;
      for(int s = 0; s < n; s++){
        count = 0;
        dfsCut(s, -1, 0, d);
        ans = Math.min(ans, count);
      }
    }
    else{
      int d = (k - 1) / 2;
      for(int s = 0; s < n - 1; s++){
        count = 0;
        dfsCut(edges[s][0], edges[s][1], 0, d);
        dfsCut(edges[s][1], edges[s][0], 0, d);
        ans = Math.min(ans, count);
      }
    }

    System.out.println(ans);
  }

  private static void dfsCut(int v, int p, int d, int l){
    if(d > l){
      ++count;
    }
    for(int i = 0; i < G.get(v).size(); i++){
      int w = G.get(v).get(i);
      if(w != p){
        dfsCut(w, v, d + 1, l);
      }
    }
  }
}