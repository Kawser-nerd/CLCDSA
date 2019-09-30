import java.io.*;
import java.util.*;

public class Main {

	int[][] go = new int[N][];
	boolean[] stop = new boolean[N];
	static final int N = 1_000_000;

	int sz = 0;

	int newNode() {
		go[sz] = new int[] { -1, -1 };
		return sz++;
	}
	
	long getVal(long maxL) {
		if (maxL < 0) {
			throw new AssertionError();
		}
		return Long.lowestOneBit(maxL);
	}

	void submit() {
		int root = newNode();

		int n = nextInt();
		long l = nextLong();

		for (int i = 0; i < n; i++) {
			int v = root;
			String s = nextToken();
			for (char c : s.toCharArray()) {
				int dig = c - '0';
				if (go[v][dig] == -1) {
					go[v][dig] = newNode();
				}
				v = go[v][dig];
			}
			stop[v] = true;
		}

		int[] que = new int[sz];
		int[] depth = new int[sz];
		int qh = 0, qt = 0;

		depth[qt] = 0;
		que[qt++] = root;

		long xor = 0;

		while (qh < qt) {
			int nowD = depth[qh];
			int v = que[qh++];
			
			if (stop[v]) {
				continue;
			}
			for (int i = 0; i < 2; i++) {
				if (go[v][i] == -1) {
					xor ^= getVal(l - nowD);
				} else {
					depth[qt] = nowD + 1;
					que[qt++] = go[v][i];
				}
			}
		}
		
		out.println(xor == 0 ? "Bob" : "Alice");
	}

	int mex(HashSet<Integer> set) {
		int ret = 0;
		while (set.contains(ret)) {
			ret++;
		}
		return ret;
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
		// stress();
		// test();
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