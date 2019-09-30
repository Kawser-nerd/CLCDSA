import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{ // 

	public static void main(String args[]) {
		ConsoleScanner cin = new ConsoleScanner();
		PrintWriter cout = new PrintWriter(System.out);
		solve(cin, cout);
		cout.flush();
	}

	static long now() {
		return System.currentTimeMillis();
	}

	static void trace(Object... objects) {
		assert null != System.out.format("trace:%s\n", Arrays.deepToString(objects));
	}

	private static void solve(ConsoleScanner cin, PrintWriter cout) {
		// assert solve(1) == 1;

		int n = cin.nextInt();

		int[][] abs = new int[n - 1][];
		for (int i = 0; i < abs.length; i++)
			abs[i] = new int[] { cin.nextInt(), cin.nextInt() };

		long start = now();

		boolean ans = solve(n, abs);
		if (ans)
			cout.println("Fennec");
		else
			cout.println("Snuke");

		trace("elapsed", now() - start);
	}

	private static boolean solve(int n, int[][] abs) {
		// BFS
		int[] vis = new int[n + 1];
		Arrays.fill(vis, -1);
		int FEN = 1;
		int SNU = 2;
		int[][] adj = adjacentList(abs);
		ArrayDeque<Integer> q = new ArrayDeque<>();
		// Fennec??
		q.add(1);
		vis[1] = FEN;
		// Snuke??
		q.add(n);
		vis[n] = SNU;
		while (!q.isEmpty()) {
			int v = q.poll();
			for (int u : adj[v]) {
				if (vis[u] != -1)
					continue;
				vis[u] = vis[v];
				q.add(u);
			}
		}
		long fen = Arrays.stream(vis).filter(x -> x == FEN).count();
		long snu = Arrays.stream(vis).filter(x -> x == SNU).count();
		return fen > snu;
	}

	private static int[][] adjacentList(int[][] fromTo) {
		int mx = -1;
		for (int[] ft : fromTo)
			mx = Math.max(mx, Math.max(ft[0], ft[1]));
		int[] sz = new int[mx + 1];
		for (int[] ft : fromTo) {
			sz[ft[0]] += 1;
			sz[ft[1]] += 1;
		}
		int[][] ans = new int[mx + 1][];
		for (int i = 0; i < ans.length; i++)
			ans[i] = new int[sz[i]];
		for (int[] ft : fromTo) {
			sz[ft[0]] -= 1;
			sz[ft[1]] -= 1;
			ans[ft[0]][sz[ft[0]]] = ft[1];
			ans[ft[1]][sz[ft[1]]] = ft[0];
		}
		return ans;
	}

	static class ConsoleScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			try {
				while (!st.hasMoreElements())
					st = new StringTokenizer(br.readLine());
				return st.nextToken();
			} catch (IOException e) {
				throw new AssertionError(e);
			}
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

}