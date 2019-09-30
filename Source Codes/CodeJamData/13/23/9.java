import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws FileNotFoundException{
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.build();
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			out.format("Case #%d: ", i + 1);
			solver.solve(in, out);
		}
		
		out.close();
	}
}

class Solver {
	Vertex root;
	class Vertex {
		Map<Character, Vertex> edges;
		int d;
		boolean leaf;
		public Vertex(int d) {
			edges = new HashMap<Character, Solver.Vertex>();
			this.d = d;
			this.leaf = false;
		}
		public Vertex goTo(char c) {
			if (edges.containsKey(c))
				return edges.get(c);
			return root;
		}
		public void set(char c, Vertex dest) {
			edges.put(c, dest);
		}
	}
	int maxl = 0;
	public void build() throws FileNotFoundException{
		InputReader in = new InputReader(new FileInputStream("garbled_email_dictionary.txt"));
		root = new Vertex(0);
		while (true) {
			try {
				String s = in.next();
				if (s == null)
					break;
				maxl = Math.max(maxl, s.length());
				Vertex cur = root;
				for (int i = 0; i < s.length(); i++) {
					char c = s.charAt(i);
					if (cur.goTo(c) == root) {
						cur.set(c, new Vertex(cur.d + 1));
					}
					cur = cur.goTo(c);
				}
				cur.leaf = true;
			} catch (Exception e) {
				break;
			}
		}
	}
	private final static int INF = 1000000000;
	StringBuffer sb;
	int cr = 0;
	int[][] dp;
	boolean dfs(Vertex v) {
		if (v.d == sb.length()) {
			return v.leaf;
		}
		char c = sb.charAt(v.d);
		if (c != '?') {
			if (v.goTo(c) == root)
				return false;
			return dfs(v.goTo(c));
		}
		for (Vertex dest : v.edges.values()) {
			if (dfs(dest))
				return true;
		}
		return false;
	}
	void search1 (int sp, int cnt, int p, int dpv) {
		if (sp == sb.length()) {
			if (dfs(root))
				dp[cnt][p] = Math.min(dp[cnt][p], dpv + cr);
			return;
		}
		if (p == 0) {
			cr++;
			char wc = sb.charAt(sp);
			sb.setCharAt(sp, '?');
			search1(sp + 1, cnt, 4, dpv);
			sb.setCharAt(sp, wc);
			cr--;
			search1(sp + 1, cnt, 0, dpv);
		} else
			search1(sp + 1, cnt, p - 1, dpv);
	}
	void search (int cnt, int p, int dpv) {
		search1(0, p, cnt, dpv);
	}
	public void solve(InputReader in, PrintWriter out) {
		String s = in.next();
		dp = new int[s.length() + 1][5];
		for (int i = 0; i < s.length() + 1; i++) {
			for (int j = 0; j < 5; j++) {
				dp[i][j] = INF;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < s.length() + 1; i++) {
			for (int j = 0; j < 5; j++) {
				if (dp[i][j] == INF)
					continue;
				for (int l = 1; l <= maxl && i + l <= s.length(); ++l) {
					sb = new StringBuffer(s.substring(i, i + l));
					search(j, i + l, dp[i][j]);
				}
			}
		}
		int ans = INF;
		for (int j = 0; j < 5; j++) {
			ans = Math.min(ans, dp[s.length()][j]);
		}
		out.println(ans);
		
		
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
