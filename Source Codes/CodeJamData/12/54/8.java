import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		new D().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;

	public void run() {
		for (File inf : (new File(".")).listFiles()) {
			if (inf.getName().startsWith("D-") && inf.getName().endsWith(".in")) {
				System.out.println("Processing " + inf.getName() + ":");
				try {
					br = new BufferedReader(new FileReader(inf));
					File ouf = new File(inf.getName().replaceAll("\\.in",
							".out"));
					out = new PrintWriter(ouf);
					st = null;
					eof = false;
					solve();
				} catch (Throwable e) {
					e.printStackTrace();
					System.exit(-1);
				} finally {
					out.close();
				}
			}
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String map = "oi-eas-tbg";
	
	void solve() throws IOException {
		int testCount = nextInt();
		for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
			System.out.println(testNumber + " / " + testCount);
			out.print("Case #" + testNumber + ": ");
			int k = nextInt();
			assert k == 2;
			String s = nextToken();
			
			ArrayList<Integer>[] g = new ArrayList[26];			
			
			HashMap<Character, Integer> hm = new HashMap<>();
			for (char c = 'a'; c <= 'z'; ++c) {
				hm.put(c, hm.size());
				int j = map.indexOf(c);
				g[c - 'a'] = new ArrayList<>();
				g[c - 'a'].add(hm.get(c));
				if (j >= 0) {
					hm.put((char)('0' + j), hm.size());
					g[c - 'a'].add(hm.get((char)('0' + j)));
				}
			}			
	
			deg = new int[hm.size()];
			
			
			HashSet<Integer> used = new HashSet<>();
			
			G = new boolean[hm.size()][hm.size()];
			u = new boolean[hm.size()];
			Arrays.fill(u, true);
			
			int ans = 0;
			for (int i = 0; i + 1 < s.length(); ++i) {
				ArrayList<Integer> st = g[s.charAt(i) - 'a'];
				ArrayList<Integer> fi = g[s.charAt(i + 1) - 'a'];
				
				for (int a : st) {
					for (int b : fi) {
						int ff = a * 100 + b;
						if (!used.contains(ff)) {
							used.add(ff);
							deg[a]++;
							deg[b]--;
							++ans;
							G[a][b] = true;
							u[a] = false;
							u[b] = false;
						}
					}
				}
			}
//
//			System.err.println(Arrays.toString(deg));
			
			for (int v : deg) {
				ans += Math.max(v, 0);
			}
			
			
			for (int i = 0; i < u.length; ++i) {
				if (!u[i] && deg[i] != 0) {
					dfs(i);
				}
			}
			
			for (int j = 0; j < u.length; ++j) {
				if (!u[j]) {
					++ans;
					dfs(j);
				}
			}
			
			
			out.println(ans);
			
			out.flush();
		}
	}

	
	boolean[][] G;
	int[] deg;
	
	boolean[] u;
	
	boolean dfs(int i) {
		u[i] = true;
		boolean ans = deg[i] != 0;
		for (int j = 0; j < G[i].length; ++j) {
			if (!u[j] && G[i][j]) {
				ans |= dfs(j);
			}
		}
		return ans;
	}
	
	
}
