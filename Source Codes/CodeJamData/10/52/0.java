import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "B-large";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	static class Node implements Comparable<Node> {
		int i, val;

		public Node(int i, int val) {
			super();
			this.i = i;
			this.val = val;
		}

		public int compareTo(Node o) {
			return val - o.val;
		}
		
		
	}

	void solve() throws IOException {
		long l = nextLong();
		int n = nextInt();
		int[] b = new int[n];
		for (int i = 0; i < n; ++i) {
			b[i] = nextInt();
		}
		Arrays.sort(b);
		int bMax = b[--n];
		int[] d = new int[bMax];
		Arrays.fill(d, 1000000000);
		d[0] = 0;
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		pq.add(new Node(0, 0));
		while (!pq.isEmpty()) {
			Node node = pq.poll();
			int u = node.i;
			if (d[u] != node.val) {
				continue;
			}
			for (int i = 0; i < n; ++i) {
				int v = u + b[i];
				int len = 1;
				while (v >= bMax) {
					v -= bMax;
					len--;
				}
				if (len < 0) {
					throw new AssertionError();
				}
				if (d[v] > d[u] + len) {
					d[v] = d[u] + len;
					pq.add(new Node(v, d[v]));
				}
			}
		}
		if (d[(int) (l % bMax)] == 1000000000) {
			out.println("IMPOSSIBLE");
		} else {
			out.println(l / bMax + d[(int) (l % bMax)]);
		}
	}

	Solution() throws IOException {
		in = new BufferedReader(new FileReader(f + ".in"));
		out = new PrintWriter(f + ".out");
		
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			System.out.println("Test #" + (test + 1));
			out.print("Case #" + (test + 1) + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
