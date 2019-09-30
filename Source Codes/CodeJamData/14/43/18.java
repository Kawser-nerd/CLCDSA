import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;
import static java.lang.System.*;

public class C {
  public static String[] parts(BufferedReader br) throws Exception {
    String line = br.readLine();
    if (line == null) return null;
    return line.trim().split("\\s+");
  }
  
  public static void main(String args[]) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(in));
    
    int cas = parseInt(br.readLine());
    for(int z=1;z<=cas;z++) {
      String[] ss = parts(br);
      int w = parseInt(ss[0]);
      int h = parseInt(ss[1]);
      int b = parseInt(ss[2]);
      
      int n = b+2;
      House[] hs = new House[n];
      for(int i=0;i<b;i++) {
        ss = parts(br);
        int x0 = parseInt(ss[0]);
        int y0 = parseInt(ss[1]);
        int x1 = parseInt(ss[2])+1;
        int y1 = parseInt(ss[3])+1;
        hs[i] = new House(x0, y0, x1, y1);
      }
      hs[b] = new House(-1,-INF, 0, INF);
      hs[b+1] = new House(w, -INF, w+1, INF);
      
      int ans = 0;
      boolean[] vis = new boolean[n];
      PriorityQueue<Pair> q = new PriorityQueue<Pair>();
      q.add(new Pair(b, 0));
      while(!q.isEmpty()) {
        Pair p = q.poll();
        // out.println(">>> " +p);
        int u = p.u;
        int cd = p.v;
        if (vis[u]) continue;
        vis[u] = true;
        if (u == b+1) {
          ans = cd;
        }
        for (int v=0;v<n;v++) {
          if (vis[v]) continue;
          int d = dist(hs, u, v);
          q.add(new Pair(v, cd+d));
        }
      }
      
      out.println("Case #"+z+": "+ ans);
    }
  }
  
  static int dist(House[] arr, int u, int v) {
    House hu = arr[u];
    House hv = arr[v];
    
    int ans = 0;
    
    if (hu.x0 >= hv.x1 && hu.y0 >= hv.y1) {
      ans = max(hu.x0 - hv.x1, hu.y0 - hv.y1);
    } else if (hu.x0 >= hv.x1 && hu.y1 <= hv.y0) {
      ans = max(hu.x0 - hv.x1, hv.y0 - hu.y1);
    } else if (hu.x1 <= hv.x0 && hu.y0 >= hv.y1) {
      ans = max(hv.x0 - hu.x1, hu.y0 - hv.y1);
    } else if (hu.x1 <= hv.x0 && hu.y1 <= hv.y0) {
      ans = max(hv.x0 - hu.x1, hv.y0 - hu.y1);
    } else if (hu.x0 >= hv.x1) {
      ans = hu.x0 - hv.x1;
    } else if (hu.x1 <= hv.x0) {
      ans = hv.x0 - hu.x1;
    } else if (hu.y0 >= hv.y1) {
      ans = hu.y0 - hv.y1;
    } else { // if hu.y1 <= hv.y0
      ans = hv.y0 - hu.y1;
    }
    
    return ans;
  }
  
  static int diff(int x0, int y0, int x1, int y1) {
    return max(x0-x1, y0-y1);
  }
  
  static class Pair implements Comparable<Pair> {
    int u, v;
    
    Pair(int a, int b) {
      u = a;
      v = b;
    }
    
    public int compareTo(Pair p) {
      if (v != p.v) return v - p.v;
      return u - p.u;
    }
    
    public String toString() {
      return "("+u+","+v+")";
    }
  }
  
  static final int INF = 100000009;
  
  static class House {
    int x0, y0, x1, y1;
    
    House(int a, int b, int c, int d) {
      x0 = a;
      y0 = b;
      x1 = c;
      y1 = d;
    }
  }
}
