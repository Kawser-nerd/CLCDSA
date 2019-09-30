import java.io.*;
import java.util.*;
 
public class Main {
 
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	List<Integer>[] g;
	int[] b;
	int k;
	
	int dfs(int v, int p) {
		int depth = 0;
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			depth = Math.max(depth, dfs(u, v) + 1);
		}
		
		if (depth == k - 1) {
			b[v] = 0;
			return -1;
		}
		return depth;
	}
 
	void solve() throws IOException {
		int n = nextInt();
		k = nextInt();
		int[] a = new int[n];
		
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}
		
		b = a.clone();
		b[0] = 0;
		
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 1; i < n; i++) {
			g[b[i]].add(i);
		}
		
		dfs(0, -1);
		
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				ret++;
			}
		}
		
		out.println(ret);
	}
 
	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		Thread t = new Thread(null, new Runnable() {
 
			@Override
			public void run() {
				try {
					solve();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
		}, "lul", 1 << 26);
		
		t.start();
		try {
			t.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		out.close();
	}
 
	public static void main(String[] args) throws IOException {
		new Main();
	}
 
	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}
 
	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}
 
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
 
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
 
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.