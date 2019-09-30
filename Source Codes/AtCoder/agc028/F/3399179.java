import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static void solve() throws Exception {
		int n = scanInt();
		char map[][] = new char[n][];
		for (int i = 0; i < n; i++) {
			map[i] = scanString().toCharArray();
		}
		int sum[][] = new int[n][n];
		int maxI[][] = new int[n][n];
		int curProfilesD[][] = new int[n][n];
		int curProfilesR[][] = new int[n][n];
		int prevProfilesD[][] = new int[n][n];
		int prevProfilesR[][] = new int[n][n];
		long ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j] == '#') {
					continue;
				}
				int value = map[i][j] - '0';
				if (i == n - 1 || map[i + 1][j] == '#') {
					if (j == n - 1 || map[i][j + 1] == '#') {
						sum[i][j] = value;
						maxI[i][j] = i;
						for (int k = i + 1; k < n; k++) {
							curProfilesD[j][k] = n;
						}
						for (int k = i; k < n; k++) {
							curProfilesR[j][k] = j + 1;
						}
					} else {
						int psum = sum[i][j + 1];
						sum[i][j] = value + psum;
						ans += value * psum;
						maxI[i][j] = maxI[i][j + 1];
						for (int k = i + 1; k < n; k++) {
							curProfilesD[j][k] = curProfilesD[j + 1][k];
						}
						for (int k = i; k < n; k++) {
							curProfilesR[j][k] = curProfilesR[j + 1][k];
						}
					}
				} else {
					if (j == n - 1 || map[i][j + 1] == '#') {
						int psum = sum[i + 1][j];
						sum[i][j] = value + psum;
						ans += value * psum;
						maxI[i][j] = maxI[i + 1][j];
						curProfilesD[j][i + 1] = j;
						for (int k = i + 2; k < n; k++) {
							curProfilesD[j][k] = prevProfilesD[j][k];
						}
						curProfilesR[j][i] = j + 1;
						for (int k = i + 1; k < n; k++) {
							curProfilesR[j][k] = prevProfilesR[j][k];
						}
					} else {
						int psum = sum[i][j + 1] + sum[i + 1][j];
						for (int k = i + 1; k < n; k++) {
							if (curProfilesD[j + 1][k] < prevProfilesR[j][k]) {
								psum -= sum[k][curProfilesD[j + 1][k]];
								k = maxI[k][curProfilesD[j + 1][k]];
							}
						}
						sum[i][j] = value + psum;
						ans += value * psum;
						maxI[i][j] = max(maxI[i][j + 1], maxI[i + 1][j]);
						curProfilesD[j][i + 1] = j;
						for (int k = i + 2; k < n; k++) {
							curProfilesD[j][k] = min(prevProfilesD[j][k], curProfilesD[j + 1][k]);
						}
						curProfilesR[j][i] = curProfilesR[j + 1][i];
						for (int k = i + 1; k < n; k++) {
							curProfilesR[j][k] = max(curProfilesR[j + 1][k], prevProfilesR[j][k]);
						}
					}
				}
//				System.err.println(i + " " + j + " " + ans + " " +
//					Arrays.toString(Arrays.copyOfRange(curProfilesD[j], i + 1, n)) + " " +
//					Arrays.toString(Arrays.copyOfRange(curProfilesR[j], i, n)));
			}
			int t[][] = prevProfilesD;
			prevProfilesD = curProfilesD;
			curProfilesD = t;
			t = prevProfilesR;
			prevProfilesR = curProfilesR;
			curProfilesR = t;
		}
		out.print(ans);
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
}