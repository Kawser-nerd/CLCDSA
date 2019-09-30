import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static void sortBy(int a[], int v1[], int v2[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			int cv1 = v1[ca], cv2 = v2[ca];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cv1 < v1[na] || (cv1 == v1[na] && cv2 <= v2[na])) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				int aj1 = a[j + 1], aj2 = a[j + 2];
				j += (v1[aj2] > v1[aj1] || (v1[aj2] == v1[aj1] && v2[aj2] > v2[aj1])) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			int cv1 = v1[ca], cv2 = v2[ca];
			while (j != 0 && (v1[a[j]] < cv1 || (v1[a[j]] == cv1 && v2[a[j]] < cv2))) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static int n;
	static boolean can[][];
	static boolean seenI[], seenJ[];
	static int nComps;
	static int sizeI[], sizeJ[];
	static int nGroups;
	static int groupSize[], groupSizeI[], groupSizeJ[];
	static int ans[];
	static int groupSelected1[];
	static int selection1;

	static void solve() throws Exception {
		n = nextInt();
		can = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			String l = next();
			for (int j = 0; j < n; j++) {
				can[i][j] = l.charAt(j) != '0';
			}
		}
		seenI = new boolean[n];
		seenJ = new boolean[n];
		nComps = 0;
		sizeI = new int[n];
		sizeJ = new int[n];
		for (int i = 0; i < n; i++) {
			if (!seenI[i]) {
				dfs(i);
				++nComps;
			}
		}
		int compId[] = new int[nComps];
		for (int i = 0; i < nComps; i++) {
			compId[i] = i;
		}
		sortBy(compId, sizeI, sizeJ);
		nGroups = 0;
		groupSize = new int[nComps];
		groupSizeI = new int[nComps];
		groupSizeJ = new int[nComps];
		for (int i = 0; i < nComps; i++) {
			if (i == 0 || sizeI[compId[i]] != sizeI[compId[i - 1]] || sizeJ[compId[i]] != sizeJ[compId[i - 1]]) {
				groupSizeI[nGroups] = sizeI[compId[i]];
				groupSizeJ[nGroups] = sizeJ[compId[i]];
				groupSize[nGroups] = 1;
				++nGroups;
			} else {
				++groupSize[nGroups - 1];
			}
		}
		int sizeProduct = 1;
		for (int i = 0; i < nGroups; i++) {
			sizeProduct *= (groupSize[i] + 1);
		}
		ans = new int[sizeProduct];
		groupSelected1 = new int[nGroups];
		go1(0, 0, 0, 0);
		int theAns = ans[sizeProduct - 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (can[i][j]) {
					--theAns;
				}
			}
		}
		printCase();
		out.println(theAns);
	}

	static void go1(int cur, int selection, int curSizeI, int curSizeJ) {
		if (cur == nGroups) {
			int cans = curSizeI >= curSizeJ ? curSizeI * curSizeI : Integer.MAX_VALUE;
			selection1 = selection;
			cans = min(cans, go2(0, 0));
			ans[selection] = cans;
			return;
		}
		selection *= groupSize[cur] + 1;
		for (groupSelected1[cur] = 0; groupSelected1[cur] <= groupSize[cur]; groupSelected1[cur]++) {
			go1(cur + 1, selection, curSizeI, curSizeJ);
			++selection;
			curSizeI += groupSizeI[cur];
			curSizeJ += groupSizeJ[cur];
		}
	}

	static int go2(int cur, int selection) {
		if (cur == nGroups) {
			return (selection == 0 || selection == selection1 ||
				ans[selection] == Integer.MAX_VALUE || ans[selection1 - selection] == Integer.MAX_VALUE) ?
				Integer.MAX_VALUE : ans[selection] + ans[selection1 - selection];
		}
		selection *= groupSize[cur] + 1;
		int cans = Integer.MAX_VALUE;
		for (int i = 0; i <= groupSelected1[cur]; i++) {
			cans = min(cans, go2(cur + 1, selection));
			++selection;
		}
		return cans;
	}

	static void dfs(int i) {
		seenI[i] = true;
		++sizeI[nComps];
		for (int j = 0; j < n; j++) {
			if (can[i][j] && !seenJ[j]) {
				seenJ[j] = true;
				++sizeJ[nComps];
				for (int ni = 0; ni < n; ni++) {
					if (can[ni][j] && !seenI[ni]) {
						dfs(ni);
					}
				}
			}
		}
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