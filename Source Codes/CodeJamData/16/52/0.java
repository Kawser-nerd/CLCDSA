import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;

public class B {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static final Random rng = new Random(42);

	static void solve() throws Exception {
		final int ITERS = 100000;
		int n = nextInt();
		int parent[] = new int[n];
		List<Integer> childrenL[] = new List[n];
		for (int i = 0; i < n; i++) {
			childrenL[i] = new ArrayList<>();
		}
		List<Integer> rootsL = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			parent[i] = nextInt() - 1;
			if (parent[i] >= 0) {
				childrenL[parent[i]].add(i);
			} else {
				rootsL.add(i);
			}
		}
		int children[][] = new int[n][];
		for (int i = 0; i < n; i++) {
			children[i] = new int[childrenL[i].size()];
			for (int j = 0; j < children[i].length; j++) {
				children[i][j] = childrenL[i].get(j);
			}
		}
		int roots[] = new int[rootsL.size()];
		int sizes[] = new int[n];
		for (int i = 0; i < roots.length; i++) {
			roots[i] = rootsL.get(i);
			dfs(roots[i], children, sizes);
		}
		char letter[] = next().toCharArray();
		int m = nextInt();
		char words[][] = new char[m][];
		int wordsP[][] = new int[m][];
		for (int i = 0; i < m; i++) {
			char s[] = words[i] = next().toCharArray();
			int p[] = wordsP[i] = new int[words[i].length + 1];
			p[0] = -1;
			for (int j = 1, pp = -1; j < p.length; j++) {
				char cur = s[j - 1];
				while (pp >= 0 && s[pp] != cur) {
					pp = p[pp];
				}
				p[j] = ++pp;
			}
		}
		char seq[] = new char[n];
		int curSet[] = new int[n];
		int curSetSize[] = new int[n];
		int ans[] = new int[m];
		for (int it = 0; it < ITERS; it++) {
			for (int i = 0; i < roots.length; i++) {
				curSet[i] = roots[i];
				curSetSize[i] = sizes[roots[i]];
			}
			int nCurSets = roots.length;
			for (int i = 0; i < n; i++) {
				int choice = rng.nextInt(n - i);
				for (int j = 0;; j++) {
					if (j == nCurSets) {
						throw new AssertionError();
					}
					if (choice < curSetSize[j]) {
						int cur = curSet[j];
						seq[i] = letter[cur];
						curSet[j] = curSet[nCurSets - 1];
						curSetSize[j] = curSetSize[nCurSets - 1];
						--nCurSets;
						for (int k = 0; k < children[cur].length; k++) {
							curSet[nCurSets + k] = children[cur][k];
							curSetSize[nCurSets + k] = sizes[children[cur][k]];
						}
						nCurSets += children[cur].length;
						break;
					}
					choice -= curSetSize[j];
				}
			}
			for (int i = 0; i < m; i++) {
				char w[] = words[i];
				int p[] = wordsP[i];
				for (int j = 0, k = 0; j < n; j++) {
					char cur = seq[j];
					while (k >= 0 && w[k] != cur) {
						k = p[k];
					}
					if (++k == w.length) {
						++ans[i];
						break;
					}
				}
			}
		}
		printCase();
		for (int i = 0; i < m; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.printf(Locale.US, "%.4f", (double) ans[i] / ITERS);
		}
		out.println();
		System.err.println("DONE TEST " + test);
	}

	static int dfs(int cur, int children[][], int sizes[]) {
		int res = 1;
		for (int next: children[cur]) {
			res += dfs(next, children, sizes);
		}
		sizes[cur] = res;
		return res;
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}