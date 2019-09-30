import java.io.*;
import java.util.*;

public class Main {

	int[] head;
	int[] next;
	int[] to;
	
	void addEdge(int v, int u, int idx) {
		to[idx] = u;
		next[idx] = head[v];
		head[v] = idx;
	}
	
	int dfs(int v, int p) {
		int ret = 0;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u != p) {
				ret ^= dfs(u, v) + 1;
			}
		}
		return ret;
	}
	
	void submit() {
		int n = nextInt();
		head = new int[n];
		Arrays.fill(head, -1);
		next = new int[2 * n - 2];
		to = new int[2 * n -2];
		
		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			addEdge(v, u, 2 * i);
			addEdge(u, v, 2 * i + 1);
		}
		
		int ret = dfs(0, -1);
		out.println(ret == 0 ? "Bob" : "Alice");
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}