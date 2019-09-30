import java.io.*;
import java.util.*;

/**
 * @author nik
 */
public class B {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("B-large.in"));
    PrintWriter out = new PrintWriter("b.out");
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int s = in.nextInt();
      int m = in.nextInt();
      int[][] dirs = {{-1,-1}, {-1,0},{0,1},{1,1},{1,0},{0,-1}};
      DisjointSet set = new DisjointSet();
      boolean[] e = new boolean[8];
      boolean ring = false, bridge = false, fork = false;
      Data[] next = new Data[6];
      int res = -1;
      for (int i = 1; i <= m; i++) {
        int x = in.nextInt();
        int y = in.nextInt();
        if (res != -1) continue;
        int xy = x*(2*s)+y;
        Data d0 = set.find(xy);
        e[0] = x == 1;
        e[1] = y == x + s-1;
        e[2] = y == 2*s-1;
        e[3] = x == 2*s-1;
        e[4] = x == y + s-1;
        e[5] = y == 1;
        e[6] = e[0];
        e[7] = e[1];
        for (int k = 1; k <= 6; k++) {
          if (e[k] && !e[k-1] && !e[k+1]) d0.border |= 1 << k;
          if (e[k] && e[k+1]) d0.corner |= 1 << k;
        }
        for (int d = 0; d < 6; d++) {
          next[d] = null;
          int x1 = x + dirs[d][0];
          int y1 = y + dirs[d][1];
          if (x1 < 1 || x1 > 2*s-1 || y1 < 1 || y1 > 2*s-1 || x1 > y1 + s-1 || y1 > x1+s-1) {
            continue;
          }
          int xy1 = x1*(2*s)+y1;
          if (set.isEmpty(xy1)) {
            continue;
          }
          Data d1 = set.find(xy1);
          d0.corner |= d1.corner;
          d0.border |= d1.border;
          next[d] = d1;
        }

        int bc = 0, cc = 0;
        for (int d = 1; d <= 6; d++) {
          if ((d0.border & (1<<d)) != 0) bc++;
          if ((d0.corner & (1<<d)) != 0) cc++;
        }
        if (bc >= 3) fork = true;
        if (cc >= 2) bridge = true;

        for (int d1 = 0; d1 < 6; d1++) {
          if (next[d1] != null) {
            for (int d2 = d1+1; d2 < 6; d2++) {
              if (next[d1] == next[d2]) {
                boolean empty = false;
                for (int d = d1+1; d <= d2-1; d++) {
                  if (next[d] == null) empty = true;
                }
                if (empty) {
                  empty = false;
                  for (int d = d2+1; d <= d1+5; d++) {
                    if (next[d%6] == null) empty = true;
                  }
                  if (empty) ring = true;
                }
              }
            }
          }
        }
        Data nextD = d0;
        for (int j = 0; j < 6; j++) {
          if (next[j] != null) {
            set.unify(nextD.i, next[j].i);
            nextD = set.find(nextD.i);
          }
        }
        nextD.border = d0.border;
        nextD.corner = d0.corner;
        for (int j = 0; j < 6; j++) {
          if (next[j] != null) {
            if (set.find(next[j].i) != nextD) {
              throw new AssertionError();
            }
          }
        }
        if (ring || bridge || fork) {
          res = i;
        }
      }

      String ans;
      if (res == -1) ans = "none";
      else {
        StringBuilder buf = new StringBuilder();
        if (bridge) buf.append("bridge");
        if (fork) {
          if (buf.length() > 0) buf.append('-');
          buf.append("fork");
        }
        if (ring) {
          if (buf.length() > 0) buf.append('-');
          buf.append("ring");
        }
        buf.append(" in move ").append(res);
        ans = buf.toString();
      }
      out.println("Case #"+t+": "+ans);
    }
    out.close();
    in.close();
  }

  private static final class Data {
    public int i,r,p;
    public byte border;
    public byte corner;
  }

  public static final class DisjointSet {
    private Map<Integer, Data> data = new HashMap<Integer, Data>();

    public DisjointSet() {
    }

    public void unify(int i, int j) {
      Data di = get(i), dj = get(j);
      if (di.r > dj.r) {
        dj.p = i;
      }
      else {
        di.p = j;
        if (di.r == dj.r) {
          dj.r++;
        }
      }
    }

    public boolean isEmpty(int xy) {
      return !data.containsKey(xy);
    }

    private Data get(int i) {
      Data x = data.get(i);
      if (x == null) {
        x = new Data();
        x.i = i;
        x.p = i;
        data.put(i, x);
      }
      return x;
    }

    public Data find(int i) {
      int j = i;
      Data dj = get(j);
      while (j != dj.p) {
        j = dj.p;
        dj = get(j);
      }
      int k = i;
      Data dk = get(k);
      while (k != dk.p) {
        int t = dk.p;
        dk.p = j;
        k = t;
        dk = get(k);
      }
      return dj;
    }
  }
}
