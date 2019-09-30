import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Pair {
		final int i, j;

		Pair(int i, int j) {
			this.i = i;
			this.j = j;
		}
	}
	
	static void solveTest() throws Exception {
//		System.err.println("---- New test");
		int n = nextInt();
		int m = nextInt();
		int u[] = new int[m];
		for (int i = 0; i < m; i++) {
			u[i] = nextInt() - 1;
		}
		int v[] = new int[m];
		for (int i = 0; i < m; i++) {
			v[i] = nextInt() - 1;
		}
		int nlinks[] = new int[n];
		fill(nlinks, 2);
		for (int i = 0; i < m; i++) {
			++nlinks[u[i]];
			++nlinks[v[i]];
		}
		int links[][] = new int[n][];
		for (int i = 0; i < n; i++) {
			links[i] = new int[nlinks[i]];
			links[i][0] = (i + 1) % n;
			links[i][1] = (i + n - 1) % n;
		}
		for (int i = 0; i < m; i++) {
			links[u[i]][--nlinks[u[i]]] = v[i];
			links[v[i]][--nlinks[v[i]]] = u[i];
		}
		for (int i = 0; i < n; i++) {
			sort(links[i]);
		}
		boolean visited[][] = new boolean[n][];
		for (int i = 0; i < n; i++) {
			visited[i] = new boolean[links[i].length];
		}
		int ansVal = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < visited[i].length; j++) {
				if (visited[i][j]) {
					continue;
				}
				int ii = i;
				int jj = j;
				int len = 0;
				do {
					visited[ii][jj] = true;
					++len;
					int iiNew = links[ii][jj];
					int jjNew = binarySearch(links[iiNew], ii);
					if (jjNew < 0) {
						throw new AssertionError();
					}
					jjNew = (jjNew + 1) % links[iiNew].length;
					ii = iiNew;
					jj = jjNew;
				} while (ii != i || jj != j);
				ansVal = min(ansVal, len);
			}
		}
		int ans[] = new int[n];
		fill(ans, -1);
		List<Pair> pairs = new ArrayList<Pair>();
		ans[0] = 0;
		ans[1] = 1;
		pairs.add(new Pair(1, 0));
		boolean colors[] = new boolean[ansVal];
		do {
			Pair pair = pairs.remove(pairs.size() - 1);
			int i = pair.i;
			int j = pair.j;
//			System.err.println("Coloring room from " + (i + 1) + " towards " + (links[i][j] + 1));
			fill(colors, false);
			colors[ans[i]] = true;
			colors[ans[links[i][j]]] = true;
//			if (links[i][j] == (i + 1) % n || visited[i][j]) {
//				continue;
//			}
			int ii = i;
			int jj = j;
			int pos = 0;
			int iter = 0;
			int pcol = -1;
			do {
				if (iter > 1) {
					if (ans[ii] >= 0) {
						throw new AssertionError();
					}
					while (pos < ansVal && colors[pos]) {
						++pos;
					}
					if (pos < ansVal) {
						ans[ii] = pos;
						colors[pos] = true;
					} else {
						int col = 0;
						while (col == ans[i] || col == pcol) {
							++col;
						}
						ans[ii] = col;
					}
//					System.err.println((ii + 1) + " was assigned color " + (ans[ii] + 1));
				} else {
					if (ans[ii] < 0) {
						throw new AssertionError();
					}
//					System.err.println((ii + 1) + " already has color " + (ans[ii] + 1));
				}
				pcol = ans[ii];
				int iiNew = links[ii][jj];
				int jjNew = binarySearch(links[iiNew], ii);
				if (ii != i && ii != (iiNew + 1) % n) {
					pairs.add(new Pair(iiNew, jjNew));
//					System.err.println("Found new room: from " + (iiNew + 1) + " towards " + (ii + 1));
				}
				if (jjNew < 0) {
					throw new AssertionError();
				}
				jjNew = (jjNew + 1) % links[iiNew].length;
				ii = iiNew;
				jj = jjNew;
				++iter;
			} while (ii != i || jj != j);
		} while (!pairs.isEmpty());
		out.println(ansVal);
		for (int i = 0; i < n; i++) {
			if (ans[i] < 0) {
				throw new AssertionError();
			}
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans[i] + 1);
		}
		out.println();
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static char nextChar() throws IOException {
		String token = next();
		if (token.length() != 1) {
			throw new IllegalArgumentException("String \"" + token + "\" is not a single character");
		}
		return token.charAt(0);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}