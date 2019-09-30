import java.io.*;
import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "D";
//	final String filename = problem + "-sample";

	 final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	// final String filename= problem+"-large";

	int N, A;
	boolean[][] a;
	boolean[] was;
	int[] ans_stupid;

	public void solve() throws Exception {
		N = iread();
		A = iread();
		a = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			String s = readword();
			for (int j = 0; j < N; j++)
				a[i][j] = s.charAt(j) == 'Y';
		}

		int[] ans = stupid();
		if (ans == null) {
			out.write(" IMPOSSIBLE");
		} else {
			for (int i = 0; i < N; i++)
				out.write(" " + ans[i]);
		}
		// out.write(df.format(res));
	}

	public int[] stupid() {
		try {
			ans_stupid = new int[N];
			was = new boolean[N];
			for (int i = 0; i < N; i++) {
				was[i] = true;
				ans_stupid[0] = i;
				dfs(i, 1);
				was[i] = false;
			}
		} catch (Exception e) {
			return ans_stupid;
		}
		return null;
	}

	void dfs(int cur, int num) {
		if (num == N) {
			if (cur == A)
				throw new IllegalArgumentException();
			return;
		}
		for (int i = 0; i < N; i++)
			if (!was[i]) {
				int j = a[cur][i] ? cur : i;
				ans_stupid[num] = i;
				was[i] = true;
				dfs(j, num + 1);
				was[i] = false;
			}
	}

	DecimalFormat df = new DecimalFormat("0.0000000000");

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ":");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}