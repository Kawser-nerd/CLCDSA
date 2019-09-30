import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Integer.signum;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
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
	
	static void solve() throws Exception {
//		System.err.println("TEST");
		int n = nextInt();
		int m = nextInt();
		int d = nextInt();
		boolean wall[][] = new boolean[n][m];
		int ci = -1, cj = -1;
		for (int i = 0; i < n; i++) {
			String s = in.readLine();
			for (int j = 0; j < m; j++) {
				if (s.charAt(j) == 'X') {
					ci = i;
					cj = j;
				}
				wall[i][j] = s.charAt(j) == '#';
			}
		}
		int ans = 0;
		int djMax = 0;
		for (int di = -d; di <= d; di++) {
			if (di <= 0) {
				while (di * di + djMax * djMax <= d * d) {
					++djMax;
				}
				--djMax;
			} else {
				while (di * di + djMax * djMax > d * d) {
					--djMax;
				}
			}
			p: for (int dj = -djMax; dj <= djMax; dj++) {
				if (di == 0 && dj == 0) {
					continue;
				}
//				System.err.println("TRACE " + di + " " + dj);
				int i = 0, j = 0;
				int cci = ci, ccj = cj;
				boolean fi = false, fj = false;
				while (true) {
//					System.err.print("AT (" + i + " " + j + ") REALLY (" + (fi ? cci - i : cci + i) + " " + (fj ? ccj - j : ccj + j) + ")");
					int diff = abs((2 * i + signum(di)) * dj) - abs((2 * j + signum(dj)) * di);
					if (diff > 0) {
						int nj = j + signum(dj);
//						System.err.println(" GO 0 " + signum(dj));
						if (wall(wall, cci, ccj, fi, fj, i, nj)) {
							ccj = flip(ccj, fj, j, nj);
							fj = !fj;
//							System.err.println("VERTICAL WALL");
						}
						j = nj;
					} else if (diff < 0) {
						int ni = i + signum(di);
//						System.err.println(" GO " + signum(di) + " 0");
						if (wall(wall, cci, ccj, fi, fj, ni, j)) {
							cci = flip(cci, fi, i, ni);
							fi = !fi;
//							System.err.println("HORIZONTAL WALL");
						}
						i = ni;
					} else {
						int ni = i + signum(di);
						int nj = j + signum(dj);
//						System.err.println(" GO " + signum(di) + " " + signum(dj));
						if (wall(wall, cci, ccj, fi, fj, ni, nj)) {
							if (wall(wall, cci, ccj, fi, fj, ni, j)) {
								if (wall(wall, cci, ccj, fi, fj, i, nj)) {
									cci = flip(cci, fi, i, ni);
									fi = !fi;
									ccj = flip(ccj, fj, j, nj);
									fj = !fj;
//									System.err.println("GOOD CORNER");
								} else {
									cci = flip(cci, fi, i, ni);
									fi = !fi;
//									System.err.println("HORIZONTAL WALL");
								}
							} else {
								if (wall(wall, cci, ccj, fi, fj, i, nj)) {
									ccj = flip(ccj, fj, j, nj);
									fj = !fj;
//									System.err.println("VERTICAL WALL");
								} else {
//									System.err.println("BAD CORNER");
									continue p;
								}
							}
						}
						i = ni;
						j = nj;
					}
					int ri = fi ? cci - i : cci + i;
					int rj = fj ? ccj - j : ccj + j;
					if (i == di && j == dj) {
						if (ri == ci && rj == cj) {
//							System.err.println("IMAGE " + di + " " + dj);
							++ans;
						} else {
//							System.err.println("NOTHING " + di + " " + dj);
						}
						break;
					}
					if (ri == ci && rj == cj && i * dj == j * di) {
//						System.err.println("BAD PERSON");
						continue p;
					}
				}
			}
		}
		printCase();
		out.println(ans);
	}
	
	static boolean wall(boolean wall[][], int ci, int cj, boolean fi, boolean fj, int i, int j) {
		return wall[fi ? ci - i : ci + i][fj ? cj - j : cj + j];
	}
	
	static int flip(int c, boolean f, int x, int nx) {
		return f ? c - x - nx : c + x + nx;
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