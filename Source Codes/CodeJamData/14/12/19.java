import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				"B-large.in")));
		writer = new PrintWriter("B-large.out");
		banana();
		reader.close();
		writer.close();
	}

	static void banana() throws IOException {
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			writer.print("Case #" + (t + 1) + ": ");
			solve();
		}
	}

	static int n;
	static boolean[] used;
	static ArrayList<ArrayList<Integer>> g;

	static int dfs(int curr) {
		used[curr] = true;
		ArrayList<Integer> cal = g.get(curr);
		ArrayList<Integer> cand = new ArrayList<Integer>();
		for (int next : cal) {
			if (used[next] == false) {
				cand.add(dfs(next));
			}
		}
		if (cand.size() == 0 || cand.size() == 1) {
			return 1;
		}
		Collections.sort(cand);
		return cand.get(cand.size() - 2) + cand.get(cand.size() - 1) + 1;
	}

	static void solve() throws IOException {
		n = nextInt();
		g = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			g.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < n - 1; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			g.get(a).add(b);
			g.get(b).add(a);
		}

		used = new boolean[n];
		int mn = 1000000;
		for (int start = 0; start < n; start++) {
			Arrays.fill(used, false);
			int cand = n - dfs(start);
			//writer.println("CAND: " + cand);
			if (cand < mn)
				mn = cand;
		}
		writer.println(mn);
	}
}