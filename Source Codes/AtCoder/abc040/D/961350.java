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
        ArrayList<ArrayList<Pair>> G1 = new ArrayList<>();
        for (int i = 0; i <= 200000; i++) {
            G1.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int a = ni() - 1;
            int b = ni() - 1;
            int y = ni();

            G1.get(y).add(new Pair(a, b));
        }

        int q = ni();
        ArrayList<ArrayList<Pair>> G2 = new ArrayList<>();
        for (int i = 0; i <= 200000; i++) {
            G2.add(new ArrayList<>());
        }
        for (int i = 0; i < q; i++) {
            int v = ni() - 1;
            int w = ni();
            G2.get(w).add(new Pair(i, v));
        }

        UnionFind uf = new UnionFind(n);
        int[] sum = new int[q];

        for (int i = 200000; i >= 0; i--) {
            for (Pair p : G2.get(i)) {
                sum[p.x] = uf.size(p.y);
            }
            for (Pair p : G1.get(i)) {
                uf.union(p.x, p.y);
            }
        }

        for (int x : sum) {
            out.println(x);
        }
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

    public class Pair {
    	int x, y;

    	public Pair(int x, int y) {
    		this.x = x;
    		this.y = y;
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