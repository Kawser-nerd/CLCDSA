import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int solve(int[] p) {
		int n = p.length;
		int[] in = new int[n];
		for (int x : p) {
			in[x]++;
		}
		
		int[] vis = new int[n];
		Arrays.fill(vis, -1);
		boolean[] onCycle = new boolean[n];
		
		for (int i = 0; i < n; i++) {
			int v = i;
			while (vis[v] == -1) {
				vis[v] = i;
				v = p[v];
			}
			
			if (vis[v] != i) {
				continue;
			}
			
			onCycle[v] = true;
			for (int u = p[v]; u != v; u = p[u]) {
				onCycle[u] = true;
			}
		}
		
		for (int i = 0; i < n; i++) {
			if ((!onCycle[i] && in[i] > 1) || (onCycle[i] && (in[i] < 1 || in[i] > 2))) {
				return 0;
			}
		}
		
		int[] lenIn = new int[n];
		
		for (int i = 0; i < n; i++) {
			if (!onCycle[i] && in[i] == 0) {
				int cnt = 0, v = i;
				while (!onCycle[v]) {
					cnt++;
					v = p[v];
				}
				lenIn[v] = cnt;
			}
		}
		
		int ans = 1;
		
		for (int i = 0; i < n; i++) {
			if (lenIn[i] != 0) {
				int v = p[i], len = 1;
				while (lenIn[v] == 0) {
					v = p[v];
					len++;
				}
				if (len < lenIn[v]) {
					return 0;
				}
				if (len > lenIn[v]) {
					ans = 2 * ans % P;
				}
			}
		}
		
		int[] cnt = new int[n + 1];
		for (int i = 0; i < n; i++) {
			if (onCycle[i]) {
				boolean justCycle = lenIn[i] == 0;
				int v = p[i], len = 1;
				onCycle[v] = false;
				while (v != i) {
					justCycle &= lenIn[v] == 0;
					v = p[v];
					len++;
					onCycle[v] = false;
				}
				if (justCycle) {
					cnt[len]++;
				}
			}
		}
		
		for (int len = 1; len <= n; len++) {
			ans = (int)((long)ans * go(len, cnt[len]) % P);
		}
		
		return ans;
		
	}
	
	int go(int len, int cnt) {
		int[] dp = new int[cnt + 1];
		dp[0] = 1;
		int mult = len % 2 == 1 && len > 1 ? 2 : 1;
		for (int i = 1; i <= cnt; i++) {
			dp[i] = mult * dp[i - 1] % P;
			if (i > 1) {
				dp[i] += (int)((long)dp[i - 2] * (i - 1) % P * len % P);
				if (dp[i] >= P) {
					dp[i] -= P;
				}
			}
		}
		return dp[cnt];
	}
	
	static final int P = 1_000_000_007;
	static final Random rng = new Random();
	
	void test() {
		int n = 9;
		for (int i = 0; i < Integer.MAX_VALUE; i++) {
			int[] a = new int[n];
			for (int j = 0; j < n; j++) {
				a[j] = rng.nextInt(n);
			}
			if (solve(a) != stupid(a)) {
				throw new AssertionError(Arrays.toString(a));
			}
			System.err.println(i);
		}
		
//		int[] a = {2, 0, 1, 2, 3};
//		System.err.println(solve(a));
//		System.err.println(stupid(a));
	}

	int stupid(int[] need) {
		int n = need.length;
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		int cnt = 0;

		do {
			boolean good = true;
			for (int i = 0; i < n; i++) {
				good &= (p[i] == need[i] || p[p[i]] == need[i]);
			}
			if (good) {
				System.err.println(Arrays.toString(p));
			}
			cnt += good ? 1 : 0;
		} while (nextPermutation(p));
		
		return cnt;
	}

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 2;
		while (ptr >= 0 && a[ptr] > a[ptr + 1]) {
			ptr--;
		}
		if (ptr < 0) {
			return false;
		}

		for (int i = ptr + 1, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		for (int i = ptr + 1;; i++) {
			if (a[ptr] < a[i]) {
				int tmp = a[ptr];
				a[ptr] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	void submit() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}
		
		out.println(solve(a));
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);

		submit();
//		test();
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
}