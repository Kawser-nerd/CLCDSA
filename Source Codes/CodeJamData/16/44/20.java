import java.util.Arrays;
import java.util.Scanner;

public class D {

	static Scanner sc = new Scanner(System.in);
	static int N;
	static boolean[][] g;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print("Case #" + i + ": ");
			System.out.println(solve());
		}
	}

	static int rec(boolean[] usedP, boolean[] usedM, boolean[][] map) {
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j] && !g[i][j]) ++ans;
				if (!map[i][j] && g[i][j]) return 1000000;
			}
		}
		// single
		for (int i = 0; i < N; ++i) {
			if (usedP[i]) continue;
			for (int j = 0; j < N; ++j) {
				if (usedM[j]) continue;
				boolean[][] nmap = new boolean[N][];
				for (int k = 0; k < N; ++k) {
					nmap[k] = map[k].clone();
				}
				for (int k = 0; k < N; ++k) {
					if (k != j) nmap[i][k] = false;
					if (k != i) nmap[k][j] = false;
				}
				usedP[i] = true;
				usedM[j] = true;
				ans = Math.min(ans, rec(usedP, usedM, nmap));
				usedP[i] = false;
				usedM[j] = false;
			}
		}

		// double
		if (N == 4 && !usedP[0] && !usedP[1] && !usedP[2] && !usedP[3]) {
			for (int i = 1; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					for (int k = j + 1; k < N; ++k) {
						boolean[][] nmap = new boolean[N][N];
						nmap[0][j] = nmap[0][k] = true;
						nmap[i][j] = nmap[i][k] = true;
						for (int l = 1; l < N; ++l) {
							if (l != i) {
								for (int l2 = 0; l2 < N; ++l2) {
									if (l2 != j && l2 != k) {
										nmap[l][l2] = true;
									}
								}
							}
						}
						usedP[0] = true;
						usedP[i] = true;
						usedM[j] = true;
						usedM[k] = true;
						ans = Math.min(ans, rec(usedP, usedM, nmap));
						usedP[0] = false;
						usedP[i] = false;
						usedM[j] = false;
						usedM[k] = false;
					}
				}
			}
		}

		return ans;
	}

	static int solve() {
		N = sc.nextInt();
		g = new boolean[N][N];
		for (int i = 0; i < N; ++i) {
			char[] row = sc.next().toCharArray();
			for (int j = 0; j < N; ++j) {
				g[i][j] = row[j] == '1';
			}
		}
		boolean[][] map = new boolean[N][N];
		for (boolean[] a : map) {
			Arrays.fill(a, true);
		}
		return rec(new boolean[N], new boolean[N], map);
	}
}
