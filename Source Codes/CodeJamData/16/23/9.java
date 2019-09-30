import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;
	int[] mt;
	boolean[] used;

	boolean dfs(int v) {
		if (used[v]) {
			return false;
		}
		used[v] = true;
		for (int u : g[v]) {
			if (mt[u] == -1 || dfs(mt[u])) {
				mt[u] = v;
				return true;
			}
		}
		return false;
	}

	public void solve() throws IOException {
		int t = in.nextInt();
		TreeMap<String, Integer> left = new TreeMap<>(), right = new TreeMap<>();
		int lc = 0, rc = 0;
		String[] sl = new String[t];
		String[] sr = new String[t];
		for (int i = 0; i < t; i++) {
			sl[i] = in.next();
			sr[i] = in.next();
			if (!left.containsKey(sl[i])) {
				left.put(sl[i], lc++);
			}
			if (!right.containsKey(sr[i])) {
				right.put(sr[i], rc++);
			}
		}
		g = new ArrayList[lc];
		for (int i = 0; i < lc; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < t; i++) {
			int lId = left.get(sl[i]);
			int rId = right.get(sr[i]);
		//	System.err.println(lId + " " + rId);
			g[lId].add(rId);
		}
		mt = new int[rc];
		used = new boolean[lc];
		Arrays.fill(mt, -1);
		int ans = lc + rc;
		for (int i = 0; i < lc; i++) {
			Arrays.fill(used, false);
			if (dfs(i)) {
				ans--;
			}
		}
		out.println(Math.max(0, t - ans));
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tn = in.nextInt();
			for (int i = 0; i < tn; i++) {
				System.err.println(i);
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new C().run();
	}
}