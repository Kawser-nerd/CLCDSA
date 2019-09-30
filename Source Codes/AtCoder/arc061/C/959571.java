import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    void solve() throws IOException {
        int n = ni();
        int m = ni();

        int[] p = new int[m];
        int[] q = new int[m];
        int[] c = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = ni() - 1;
            q[i] = ni() - 1;
            c[i] = ni();
        }

        HashMap<Long, Integer> map = new HashMap<>();
        ArrayList<Integer> s = new ArrayList<>();
        int idx = 0;
        for (int i = 0; i < m; i++) {
            long pc = iitol(p[i], c[i]);
            if (!map.containsKey(pc)) {
                s.add(p[i]);
                map.put(pc, idx);
                idx++;
            }
            long qc = iitol(q[i], c[i]);
            if (!map.containsKey(qc)) {
                s.add(q[i]);
                map.put(qc, idx);
                idx++;
            }
        }

        UnionFind uf = new UnionFind(idx);
        for (int i = 0; i < m; i++) {
            uf.union(map.get(iitol(p[i], c[i])), map.get(iitol(q[i], c[i])));
        }

        ArrayList<ArrayList<Integer>> groups = uf.groups();
        ArrayList<ArrayList<Integer>> G = new ArrayList<>();
        for (int i = 0; i < n + groups.size(); i++) {
            G.add(new ArrayList<>());
        }

        for (int i = 0; i < groups.size(); i++) {
            for (int x : groups.get(i)) {
                G.get(n + i).add(s.get(x));
                G.get(s.get(x)).add(n + i);
            }
        }

        ArrayDeque<Pair> Q = new ArrayDeque<>();
        Q.add(new Pair(0, 0));
        boolean[] used = new boolean[n + groups.size()];
        while (!Q.isEmpty()) {
            Pair t = Q.poll();
            if (t.x == n - 1) {
                out.println(t.y / 2);
                return;
            }
            if (used[t.x]) continue;
            used[t.x] = true;
            for (int next : G.get(t.x)) {
                Q.add(new Pair(next, t.y + 1));
            }
        }

        out.println(-1);
    }

    public class Pair {
    	int x, y;

    	public Pair(int x, int y) {
    		this.x = x;
    		this.y = y;
    	}
    }

    long iitol(int a, int b) {
        return (long) a << 32 | b;
    }

    class UnionFind {
    	private int[] parent;
    	public UnionFind(int size) {
    		parent = new int[size];
    		Arrays.fill(parent, -1);
    	}
    	public boolean union(int x,int y) {
    		x = root(x);
    		y = root(y);
    		if (x!=y) {
    			if (parent[y] < parent[x]) {
    				int tmp = y;
    				y = x;
    				x = tmp;
    			}
    			parent[x] += parent[y];
    			parent[y] = x;
    			return true;
    		}
    		return false;
    	}
    	public boolean isConnected(int x,int y) {
    		return root(x)==root(y);
    	}
    	public int root(int x) {
    		return parent[x] < 0 ? x : (parent[x] = root(parent[x]));
    	}
    	public int size(int x) {
    		return -parent[root(x)];
    	}
    	public ArrayList<ArrayList<Integer>> groups() {
    		int n = parent.length;
    		ArrayList<ArrayList<Integer>> g = new ArrayList<>();
    		HashMap<Integer,Integer> hm = new HashMap<>();
    		for(int i=0;i<n;i++) {
    			int r = root(i);
    			if (!hm.containsKey(r)) {
    				hm.put(r, g.size());
    				g.add(new ArrayList<>());
    			}
    			g.get(hm.get(r)).add(i);
    		}
    		return g;
    	}
    	public String toString() {
    		return Arrays.toString(parent);
    	}
    }

    String ns() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    int ni() throws IOException {
        return Integer.parseInt(ns());
    }

    long nl() throws IOException {
        return Long.parseLong(ns());
    }

    double nd() throws IOException {
        return Double.parseDouble(ns());
    }

    String[] nsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = ns();
        }
        return res;
    }

    int[] nia(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ni();
        }
        return res;
    }

    long[] nla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nl();
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        Main main = new Main();
        main.solve();
        out.close();
    }
}