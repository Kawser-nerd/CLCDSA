import java.util.*;
import java.io.*;
import java.awt.Point;
import static java.lang.Math.*;

public class C {
    static int not(int x) { return x%2==0?x+1:x-1; }
    static int get(int var, boolean t) { return 2*var+(t?0:1); }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tok;
    static String next() {
        while (tok == null || !tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (IOException e) {}
        }
        return tok.nextToken();
    }
    static int nextInt() { return Integer.parseInt(next()); }

    static Set<Integer> walk(int r, int c, int d, int[][] VAR, char[][] G, int depth) {
      if(depth > G.length * G[0].length * 2) { return new HashSet<Integer>(); }
      int[] dr = {-1, 0, 1, 0};
      int[] dc = {0, 1, 0, -1};
      if(!(0<=r && r<G.length && 0<=c && c<G[r].length)) { return new HashSet<Integer>(); }
      if(G[r][c]=='#') {
        return new HashSet<Integer>();
      } else if(G[r][c]=='/') {
        if(d==0) { return walk(r, c+1, 1, VAR, G, depth+1); }
        if(d==1) { return walk(r-1, c, 0, VAR, G, depth+1); }
        if(d==2) { return walk(r, c-1, 3, VAR, G, depth+1); }
        if(d==3) { return walk(r+1, c, 2, VAR, G, depth+1); }
        assert(false);
      } else if(G[r][c]=='\\') {
        if(d==0) { return walk(r, c-1, 3, VAR, G, depth+1); }
        if(d==1) { return walk(r+1, c, 2, VAR, G, depth+1); }
        if(d==2) { return walk(r, c+1, 1, VAR, G, depth+1); }
        if(d==3) { return walk(r-1, c, 0, VAR, G, depth+1); }
        assert(false);
      } else if(G[r][c]=='.') {
        return walk(r+dr[d], c+dc[d], d, VAR, G, depth+1);
      } else if(G[r][c]=='|' || G[r][c]=='-') {
        Set<Integer> ans = walk(r+dr[d], c+dc[d], d, VAR, G, depth+1);
        assert(VAR[r][c] != -1);
        ans.add(get(VAR[r][c], d==0||d==2 ? true : false));
        return ans;
      } else {
        assert(false);
      }
      assert(false);
      return new HashSet<Integer>();
    }

    public static void main(String[] args) throws Exception {
      long T = nextInt();
CAS: for(long cas=1; cas<=T; cas++) {
        int R = nextInt();
        int C = nextInt();

        char[][] G = new char[R][C];
        int n = 0;
        int[][] VAR = new int[R][C];
        for(int r=0; r<R; r++) {
          String row = next();
          for(int c=0; c<C; c++) {
            VAR[r][c] = -1;
            G[r][c] = row.charAt(c);
            if(G[r][c]=='|' || G[r][c]=='-') {
              VAR[r][c] = n;
              n++;
            }
          }
        }


        List<List<Integer>> E = new ArrayList<List<Integer>>();
        for(int i=0; i<2*n; i++) {
          E.add(new ArrayList<Integer>());
        }

        String bad = "";
        bad += "Case #" + cas + ": IMPOSSIBLE";
        /*
        bad+="\n";
        for(int r=0; r<R; r++) {
          for(int c=0; c<C; c++) {
            bad += G[r][c];
          }
          bad += "\n";
        }
        */

        for(int r=0; r<R; r++) {
          for(int c=0; c<C; c++) {
            if(G[r][c]=='.') {
              Set<Integer> up = walk(r, c, 0, VAR, G, 0);
              up.addAll(walk(r, c, 2, VAR, G, 0));
              if(up.size() > 1) { up.clear(); }

              Set<Integer> left = walk(r, c, 3, VAR, G, 0);
              left.addAll(walk(r, c, 1, VAR, G, 0));
              if(left.size() > 1) { left.clear(); }

              if(up.size()==0 && left.size()==0) {
                System.out.println(bad);
                continue CAS;
              } else if(up.size()==1 && left.size()==0) {
                int ud = up.iterator().next();
                E.get(not(ud)).add(ud);
              } else if(up.size()==0 && left.size()==1) {
                int lr = left.iterator().next();
                E.get(not(lr)).add(lr);
              } else {
                assert(up.size()==1 && left.size()==1);
                int ud = up.iterator().next();
                int lr = left.iterator().next();
                E.get(not(ud)).add(lr);
                E.get(not(lr)).add(ud);
              }
            } else if(G[r][c]=='|' || G[r][c]=='-') {
              Set<Integer> up = walk(r, c, 0, VAR, G, 0);
              up.addAll(walk(r, c, 2, VAR, G, 0));
              up.remove(get(VAR[r][c], true));

              Set<Integer> left = walk(r, c, 3, VAR, G, 0);
              left.addAll(walk(r, c, 1, VAR, G, 0));
              left.remove(get(VAR[r][c], false));
              if(up.size() > 0) {
                int me = get(VAR[r][c], true);
                E.get(me).add(not(me));
              }
              if(left.size() > 0) {
                int me = get(VAR[r][c], false);
                E.get(me).add(not(me));
              }
            }
          }
        }

        SCC.SCC(2*n, E);
        int nc = SCC.nc;
        int[] COMP = SCC.C;
        for(int i=0; i<n; i++) {
            if(COMP[get(i,false)] == COMP[get(i,true)]) {
                System.out.println(bad);
                continue CAS;
            }
        }

        List<List<Integer>> E2 = new ArrayList<List<Integer>>();
        List<List<Integer>> CON = new ArrayList<List<Integer>>();
        for(int i=0; i<nc; i++) {
            CON.add(new ArrayList<Integer>());
            E2.add(new ArrayList<Integer>());
        }
        for(int i=0; i<2*n; i++) {
            CON.get(COMP[i]).add(i);
        }
        int ans[] = new int[n];
        for(int i=0; i<n; i++) ans[i] = -1;
        int[] d = new int[nc];
        for(int i=0; i<2*n; i++) {
            for(Integer x:E.get(i)) {
                if(COMP[i] == COMP[x]) continue;
                d[COMP[i]]++;
                E2.get(COMP[x]).add(COMP[i]);
            }
        }
        LinkedList<Integer> Q = new LinkedList<Integer>();
        for(int i=0; i<nc; i++) {
            if(d[i] == 0) {
                Q.add(i);
            }
        }
        while(!Q.isEmpty()) {
            int comp = Q.poll();
            for(Integer x:CON.get(comp)) {
                if(ans[x/2] != -1) continue;
                if(x%2==0) ans[x/2] = 1;
                else ans[x/2] = 0;
            }
            for(Integer x:E2.get(comp)) {
                d[x]--;
                if(d[x] == 0)
                    Q.add(x);
            }
        }

        System.out.println("Case #" + cas + ": POSSIBLE");
        for(int r=0; r<R; r++) {
          for(int c=0; c<C; c++) {
            if(G[r][c]=='|' || G[r][c]=='-') {
              System.out.print(ans[VAR[r][c]]==1 ? '|' : '-');
            } else {
              System.out.print(G[r][c]);
            }
          }
          System.out.println();
        }
    }
  }
    static class SCC {
        //Inputs
        static int n; // # of vertices
        static List<List<Integer>> E; // Edges

        // Internal
        static int index;
        static boolean[] seen;
        static Stack<Integer> S = new Stack<Integer>();
        static int[] I;
        static int[] L;

        //Output
        static int[] C; // Maps i to component
        static int nc; //number of components

        static void SCC(int N, List<List<Integer>> edges) {
            n = N;
            E = edges;
            C = new int[n];
            L = new int[n];
            I = new int[n];
            seen = new boolean[n];
            S.clear();
            for(int i=0; i<n; i++) {
                C[i] = -1;
                L[i] = -1;
                I[i] = -1;
            }
            index = 0;
            nc = 0;

            for(int i=0; i<n; i++)
                if(I[i] == -1)
                    strong_connect(i);
        }
        static void strong_connect(int x) {
            I[x] = index;
            L[x] = index;
            seen[x] = true;
            index++;
            S.add(x);

            for(Integer y:E.get(x)) {
                if(I[y] == -1) {
                    strong_connect(y);
                    L[x] = Math.min(L[x], L[y]);
                }
                else if(seen[y]) {
                    L[x] = Math.min(L[x], I[y]);
                }
            }

            if(I[x] == L[x]) {
                int val = -1;
                do {
                    val = S.pop();
                    C[val] = nc;
                    seen[val] = false;
                } while(val != x);
                nc++;
            }
        }
    }
}
