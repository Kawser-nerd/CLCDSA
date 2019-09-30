import java.util.*;
import static java.lang.Math.*;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            int N = in.nextInt();
            in.nextLine();
            HashMap<String, Integer> hm = new HashMap<String, Integer>();
            ArrayList<Integer> a = new ArrayList<Integer>();
            ArrayList<Integer> b = new ArrayList<Integer>();
            HashMap<Integer, Boolean> typea = new HashMap<Integer, Boolean>();
            HashMap<Integer, Boolean> typeb = new HashMap<Integer, Boolean>();
            for (int i = 0; i < N; i++) {
                String[] p = in.nextLine().split(" ");
                for (String s : p) {
                    int id1 = get(hm, s);
                    if (i == 0)
                        typea.put(id1, true);
                    else {
                        if (!typea.containsKey(id1))
                            typea.put(id1, false);
                    }
                    if (i == 1)
                        typeb.put(id1, true);
                    else {
                        if (!typeb.containsKey(id1))
                            typeb.put(id1, false);
                    }

                    if (i <= 1)
                        continue;

                    for (String t : p) {
                        int id2 = get(hm, t);
                        if (id1 == id2)
                            continue;
                        a.add(id1);
                        b.add(id2);
                    }
                }
            }
            //System.out.println(hm);
            //System.out.println(typea);
            //System.out.println(typeb);
            int[][] G = new int[hm.size()*2+2][hm.size()*2+2];
            int st = G.length-2;
            int en = G.length-1;
            for (int i = 0; i < hm.size(); i++) {
                G[2*i][2*i+1] = 1;
                if (typea.get(i)) {
                    G[st][2*i] = INF;
                }
                if (typeb.get(i)) {
                    G[2*i+1][en] = INF;
                }
            }
            /*for (int i = 0; i < G.length; i++)
                System.out.println(Arrays.toString(G[i]));*/
            for (int i = 0; i < a.size(); i++) {
                int id1 = a.get(i);
                int id2 = b.get(i);
                G[2*id1+1][2*id2] = INF;
                G[2*id2+1][2*id1] = INF;
            }

            int ans = maxf(G, st, en);
            System.out.format("Case #%d: %d\n", zz, ans);
        }
    }
    static int maxf(int[][] G, int st, int en) {
        int flow = 0;
        boolean[] V = new boolean[G.length];
        while (true) {
            Arrays.fill(V, false);
            int nf = dfs(st, en, INF, V, G);
            if (nf == 0) {
                break;
            }
            flow += nf;
        }
        return flow;
    }
    static int dfs(int at, int en, int flow, boolean[] V, int[][] G) {
        //System.out.println("dfs: "+at+" "+en+" "+flow);
        if (V[at])
            return 0;
        V[at] = true;
        if (at == en)
            return flow;
        for (int i = 0; i < G.length; i++) {
            if (G[at][i] == 0) {
                continue;
            }
            int f = dfs(i, en, min(flow, G[at][i]), V, G);
            if (f != 0) {
                G[at][i] -= f;
                G[i][at] += f;
                return f;
            }
        }
        return 0;
    }
    static int INF = 1_000_000_000;
    static int get(HashMap<String, Integer> hm, String s) {
        if (!hm.containsKey(s))
            hm.put(s, hm.size());
        return hm.get(s);
    }
}
