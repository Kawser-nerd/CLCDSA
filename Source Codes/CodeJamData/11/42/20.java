import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}

	}

	int[][] mass;
	int[][] sumMass;
	Pair[][] vect;
	Pair[][] sumVect;

	int getSumMass(int x1, int y1, int x2, int y2) {
		int res = sumMass[x1][y1] + sumMass[x2 + 1][y2 + 1]
				- sumMass[x1][y2 + 1] - sumMass[x2 + 1][y1];
		return res - mass[x1][y1] - mass[x1][y2] - mass[x2][y1] - mass[x2][y2];
	}

	Pair getSumVect(int x1, int y1, int x2, int y2) {
		Pair a = sumVect[x1][y1];
		Pair b = sumVect[x1][y2 + 1];
		Pair c = sumVect[x2 + 1][y1];
		Pair d = sumVect[x2 + 1][y2 + 1];
		Pair res = new Pair(a.x - b.x - c.x + d.x, a.y - b.y - c.y + d.y);
		res.x -= vect[x1][y1].x + vect[x1][y2].x + vect[x2][y1].x
				+ vect[x2][y2].x;
		res.y -= vect[x1][y1].y + vect[x1][y2].y + vect[x2][y1].y
				+ vect[x2][y2].y;
		return res;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		nextInt(); // rly?
		mass = new int[n][m];
		for (int i = 0; i < n; i++) {
			char[] tmp = nextToken().toCharArray();
			for (int j = 0; j < m; j++)
				mass[i][j] = tmp[j] - '0';
		}

		sumMass = new int[n + 1][m + 1];

		for (int i = n - 1; i >= 0; i--)
			for (int j = m - 1; j >= 0; j--)
				sumMass[i][j] = mass[i][j] + sumMass[i + 1][j]
						+ sumMass[i][j + 1] - sumMass[i + 1][j + 1];

		// now calc vectors

		vect = new Pair[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				vect[i][j] = new Pair(i * mass[i][j], j * mass[i][j]);

		sumVect = new Pair[n + 1][m + 1];

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				if (i < n && j < m)
					;
				else
					sumVect[i][j] = new Pair(0, 0);

		for (int i = n - 1; i >= 0; i--)
			for (int j = m - 1; j >= 0; j--) {
				Pair a = sumVect[i + 1][j];
				Pair b = sumVect[i][j + 1];
				Pair c = sumVect[i + 1][j + 1];
				Pair d = vect[i][j];
				sumVect[i][j] = new Pair(a.x + b.x - c.x + d.x, a.y + b.y - c.y
						+ d.y);
			}

		// ended calc

		// for (int i = 0; i < n; i++)
		// System.err.println(Arrays.toString(mass[i]));
		//
		// for (int i = 0; i < n + 1; i++)
		// System.err.println(Arrays.toString(sumMass[i]));
		//
		// for (int i = 0; i < n; i++)
		// System.err.println(Arrays.toString(vect[i]));
		//
		// for (int i = 0; i < n + 1; i++)
		// System.err.println(Arrays.toString(sumVect[i]));

		for (int sz = Math.min(n, m); sz >= 3; sz--) {

			for (int x = 0; x <= n - sz; x++)
				for (int y = 0; y <= m - sz; y++) {

					Pair actSum = getSumVect(x, y, x + sz - 1, y + sz - 1);
					actSum.x *= 2;
					actSum.y *= 2;
					int actSumMass = getSumMass(x, y, x + sz - 1, y + sz - 1);

					Pair expSum = new Pair(actSumMass * (2 * x + sz - 1),
							actSumMass * (2 * y + sz - 1));


					if (actSum.x == expSum.x && actSum.y == expSum.y) {
						out.println(sz);
						return;
					}
				}

		}

		out.println("IMPOSSIBLE");

	}

	void preCalc() throws IOException {
	}

	void gcjSolve() throws IOException {
		preCalc();
		int tests = nextInt();
		for (int i = 1; i <= tests; i++) {
			out.print("Case #" + i + ": ");
			System.err.println("Test " + i + " started");
			solve();
		}
		System.err.println("Finished!");
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		gcjSolve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

}
