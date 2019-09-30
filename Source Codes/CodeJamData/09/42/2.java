import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class BaiB {

	static int m, n, f;
	static char[][] a;
	static int[][][][] F;
	static int inf;

	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(new FileReader("B-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int ntest = sc.nextInt();
		for (int test = 1; test <= ntest; ++test) {
			System.out.println(test);
			m = sc.nextInt();
			n = sc.nextInt();
			f = sc.nextInt();
			a = new char[m][];
			for (int i = 0; i < m; ++i)
				a[i] = sc.next().toCharArray();

			inf = 1000000;
			F = new int[m][n][2][n];
			RR = new int[m][n];
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					RR[i][j] = roii(i, j);
			for (int[][][] a3 : F)
				for (int[][] a2 : a3)
					for (int[] aa : a2)
						Arrays.fill(aa, -1);

			int res = go(0, 0, 0, 0);

			pw.println("Case #" + test + ": " + (res == inf ? "No" : ("Yes " + res)));
		}

		sc.close();
		pw.close();
	}

	static int roii(int i, int j) {
		while (i + 1 < m && a[i + 1][j] == '.')
			++i;
		return i;
	}

	static int[][] RR;

	static int roi(int i, int j) {
		return RR[i][j];
	}

	static int go(int i, int j, int side, int len) {
		if (i == m - 1) {
			return 0;
		}

		if (F[i][j][side][len] != -1)
			return F[i][j][side][len];

		int res = inf;

		char[] thisrow = new char[n];
		for (int t = 0; t < n; ++t) {
			if (a[i][t] == '#') {
				if (side == 0 && t <= j && (j - t + 1) <= len)
					thisrow[t] = '.';
				else if (side == 1 && t >= j && (t - j + 1) <= len)
					thisrow[t] = '.';
				else
					thisrow[t] = '#';
			} else
				thisrow[t] = '.';
		}

		int st = j;
		while (st > 0 && thisrow[st - 1] == '.' && a[i + 1][st - 1] == '#')
			--st;
		int en = j;
		while (en + 1 < n && thisrow[en + 1] == '.' && a[i + 1][en + 1] == '#')
			++en;

		// di trai
		if (st > 0 && thisrow[st - 1] == '.' && a[i + 1][st - 1] == '.') {
			int row = roi(i + 1, st - 1);
			if (row - i <= f) {
				res = Math.min(res, go(row, st - 1, 0, 0));
			}
		}

		// di phai
		if (en + 1 < n && thisrow[en + 1] == '.' && a[i + 1][en + 1] == '.') {
			int row = roi(i + 1, en + 1);
			if (row - i <= f) {
				res = Math.min(res, go(row, en + 1, 0, 0));
			}
		}

		// duc khoet
		for (int newj = st; newj <= en; ++newj) {
			// left
			if (newj > st) {
				for (int newlen = 1; newlen <= newj - st; ++newlen) {
					int row = roi(i + 1, newj - 1);
					if (row - i <= f)
						if (row == i + 1)
							res = Math.min(res, go(row, newj - 1, 0, newlen) + newlen);
						else
							res = Math.min(res, go(row, newj - 1, 0, 0) + newlen);
				}
			}
			// right
			if (newj < en) {
				for (int newlen = 1; newlen <= en - newj; ++newlen) {
					int row = roi(i + 1, newj + 1);
					if (row - i <= f)
						if (row == i + 1)
							res = Math.min(res, go(row, newj + 1, 1, newlen) + newlen);
						else
							res = Math.min(res, go(row, newj + 1, 0, 0) + newlen);
				}
			}
		}

		return F[i][j][side][len] = res;
	}
}