import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static class Edge {
		final int to, len;

		Edge(int to, int len) {
			this.to = to;
			this.len = len;
		}
	}

	static List<Edge> edges[];
	static int mod, npows, pows[];
	static int mapPow[], mapAdd[], mapAddBack[];

	static void solve() throws Exception {
		int n = scanInt();
		int m = scanInt();
		int q = scanInt();
		mod = scanInt();
		edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int a = scanInt() - 1, b = scanInt() - 1, c = scanInt();
			edges[a].add(new Edge(b, c));
			edges[b].add(new Edge(a, c));
		}
		for (int i = 1, pow = 2;; i++, pow = (2 * pow) % mod) {
			if (pow == 1) {
				npows = i;
				break;
			}
		}
		pows = new int[npows + 1];
		for (int i = 0, pow = 1; i <= npows; i++, pow = (2 * pow) % mod) {
			pows[i] = pow;
		}
		mapPow = new int[n];
		mapAdd = new int[n];
		mapAddBack = new int[n];
		fill(mapPow, -1);
		dfs(0, 0, 0, 0);
		int mod2 = mod;
		int zeroAdds[] = new int[npows];
		fill(zeroAdds, -1);
		zeroAdds[0] = 0;
		for (int i = 0; i < n; i++) {
			int curPow = mapPow[i], curAdd = mapAdd[i];
			for (Edge e: edges[i]) {
				int curPow2 = (curPow + 1 + mapPow[e.to]) % npows,
				    curAdd2 = (int) (((long) (2 * curAdd + e.len) * pows[mapPow[e.to]] + mapAddBack[e.to]) % mod);
				if (zeroAdds[curPow2] >= 0) {
					mod2 = gcd(mod2, abs(zeroAdds[curPow2] - curAdd2));
				} else {
					zeroAdds[curPow2] = curAdd2;
				}
			}
		}
		if (npows > 2 && zeroAdds[1] < 0 && zeroAdds[2] < 0) {
			throw new AssertionError();
		}
		if (npows % 2 != 0 && zeroAdds[1] < 0) {
			for (int i = 3; i < npows; i += 2) {
				if (zeroAdds[i] >= 0) {
					int curPow = (i + 2) % npows,
					    curAdd = (zeroAdds[i] * 4 + zeroAdds[2]) % mod;
					if (zeroAdds[curPow] >= 0) {
						mod2 = gcd(mod2, abs(zeroAdds[curPow] - curAdd));
					} else {
						zeroAdds[curPow] = curAdd;
					}
				}
			}
		}
		if (npows > 2 || zeroAdds[1] >= 0) {
			for (int i = 0; i < npows; i++) {
				if (zeroAdds[i] < 0) {
					continue;
				}
				int curPow, curAdd;
				if (zeroAdds[1] >= 0) {
					curPow = (i + 1) % npows;
					curAdd = (2 * zeroAdds[i] + zeroAdds[1]) % mod;
				} else {
					curPow = (i + 2) % npows;
					curAdd = (4 * zeroAdds[i] + zeroAdds[2]) % mod;
				}
				if (zeroAdds[curPow] >= 0) {
					mod2 = gcd(mod2, abs(zeroAdds[curPow] - curAdd));
				} else {
					zeroAdds[curPow] = curAdd;
				}
			}
		}
		int groups[] = new int[mod2];
		fill(groups, -1);
		int ngroups = 0;
		for (int i = 0; i < mod2; i++) {
			if (groups[i] >= 0) {
				continue;
			}
			for (int j = i;;) {
				groups[j] = ngroups;
				if (zeroAdds[1] >= 0) {
					j = (2 * j + zeroAdds[1]) % mod2;
				} else if (npows > 2) {
					j = (4 * j + zeroAdds[2]) % mod2;
				}
				if (j == i) {
					break;
				}
			}
			++ngroups;
		}
		for (int qq = 0; qq < q; qq++) {
			int s = scanInt() - 1, t = scanInt() - 1, r = scanInt();
			int v1 = mapAddBack[t] % mod2;
			int v2 = (int) ((long) (r + mod - mapAdd[s]) * pows[npows - mapPow[s]] % mod2);
			out.println(groups[v1] == groups[v2] ? "YES" : "NO");
		}
	}

	static void dfs(int cur, int curPow, int curAdd, int curAddBack) {
		mapPow[cur] = curPow;
		mapAdd[cur] = curAdd;
		mapAddBack[cur] = curAddBack;
		for (Edge e: edges[cur]) {
			if (mapPow[e.to] >= 0) {
				continue;
			}
			dfs(e.to, (curPow + 1) % npows, (curAdd * 2 + e.len) % mod, (int) ((curAddBack + (long) e.len * pows[curPow]) % mod));
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.