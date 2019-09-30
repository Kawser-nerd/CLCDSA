import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
 
	static class TaskD {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			if (n % 2 == 1) {
				out.println("First");
				return;
			}
			List<Integer>[] adj = new List[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
			}
			for (int i = 0; i < n - 1; i++) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				adj[a].add(b);
				adj[b].add(a);
			}
			int[] adjLeaves = new int[n];
			for (int i = 0; i < n; i++) {
				for (int j : adj[i]) {
					if (adj[j].size() == 1) {
						++adjLeaves[i];
					}
				}
				if (adjLeaves[i] >= 2) {
					out.println("First");
					return;
				}
			}
			for (int i = 0; i < n; i++) {
				if (adj[i].size() == 1) {
					continue;
				}
				int bad = 0;
				for (int j : adj[i]) {
					if (adjLeaves[j] > 0) {
						++bad;
					}
				}
				if (bad == adj[i].size()) {
					out.println("First");
					return;
				}
			}
			out.println("Second");
		}
 
	}
 
	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;
 
		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}
 
		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}
 
		public int nextInt() {
			return Integer.parseInt(next());
		}
 
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.