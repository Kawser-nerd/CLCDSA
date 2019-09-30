import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;
	static final int INF = Integer.MAX_VALUE / 5;
	
	Node root;
	
	class Node {
		char parSymb;
		Node child;
		Node sibling;
		boolean end;

		public Node(char parSymb, Node sibling) {
			this.parSymb = parSymb;
			this.sibling = sibling;
		}

		Node() {
		}

		Node go(char c) {
			for (Node res = child; ; res = res.sibling) {
				if (res == null || res.parSymb == c)
					return res;
			}
		}
		
		void add(String s) {
			if (s.isEmpty()) {
				end = true;
				return;
			}
			Node to = go(s.charAt(0));
			if (to == null) {
				child = to = new Node(s.charAt(0), child);
			}
			to.add(s.substring(1));
		}
		
		void update(int pos, int dist, int val) {
			if (end) {
				dp[pos][dist] = Math.min(dp[pos][dist], val);
			}
			if (pos == s.length())
				return;
			for (Node to = child; to != null; to = to.sibling) {
				if (to.parSymb == s.charAt(pos)) {
					to.update(pos + 1, Math.min(dist + 1, 5), val);
				} else {
					if (dist == 5) {
						to.update(pos + 1, 1, val + 1);
					}
				}
			}
		}
	}
	
	void preCalc() throws IOException {
		root = new Node();
		br = new BufferedReader(new FileReader("dict.txt"));
		String s;
		while ((s = br.readLine()) != null) {
			root.add(s);
		}
		br.close();
		System.err.println("precalc done");
	}
	
	int[][] dp;
	String s;

	void solve() throws IOException {
		s = nextToken();
		dp = new int[s.length() + 1][6];
		
		for (int i = 0; i <= s.length(); i++)
			Arrays.fill(dp[i], INF);
		
		dp[0][5] = 0;
		
		for (int i = 0; i < s.length(); i++)
			for (int j = 1; j <= 5; j++)
				if (dp[i][j] != INF) {
					root.update(i, j, dp[i][j]);
				}
		
		int ans = INF;
		for (int i = 1; i <= 5; i++)
			ans = Math.min(ans, dp[s.length()][i]);
		out.println(ans);
	}

	C() throws IOException {
		preCalc();
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("C-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("C-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("C-large.in"));
			out = new PrintWriter("C-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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
}