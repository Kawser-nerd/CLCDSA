import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

	// final String filename = problem + "-small-attempt1";

	final String filename = problem + "-large";

	public void solve() throws Exception {
		int N = iread();
		int[] type = new int[N];
		int[] id = new int[N];
		int[] num = new int[N];
		P = Q = 0;
		int[] count = new int[3000];
		int[] pid = new int[3000];
		int[] qid = new int[3000];
		int[] pcnt = new int[3000];
		int[] qcnt = new int[3000];
		for (int i = 0; i < N; i++) {
			String s = readword();
			type[i] = (s.equals("E")) ? 0 : 1;
			id[i] = iread();
			if (type[i] == 0) {
				pid[P] = id[i];
				if (id[i] != 0) {
					pcnt[P] = count[id[i]];
					count[id[i]]++;
				}
				num[i] = P++;
			} else {
				qid[Q] = id[i];
				if (id[i] != 0) {
					qcnt[Q] = count[id[i]];
					count[id[i]]++;
				}
				num[i] = Q++;
			}
		}
		ss = new boolean[P][Q];
		int[] test = new int[3000];
		for (int i = 0; i < N; i++) {
			if (type[i] != 0)
				continue;
			Arrays.fill(test, -1);
			for (int j = i + 1; j < N; j++) {
				if (id[j] != 0) {
					if (test[id[j]] >= 0) {
						continue;
					}
					test[id[j]] = 1;
				}
				if (type[j] == 0) {
					if (id[i] != 0 && id[i] == id[j])
						break;
					continue;
				}

				if (id[j] == 0 || id[i] == 0 || id[j] == id[i]) {
					ss[num[i]][num[j]] = true;
				}
				if (id[i] != 0 && id[i] == id[j])
					break;
			}
		}
		M = new int[Q];
		M0 = new int[P];
		Arrays.fill(M, -1);
		Arrays.fill(M0, -1);
		was = new boolean[Math.max(P, Q)];
		int balance = P - Q;
		for (int i = 0; i < P; i++) {
			Arrays.fill(was, false);
			try_khun(i);
		}
		for (int i = 0; i < Q; i++)
			if (qid[i] == 0 || qcnt[i] == 0) {
				Arrays.fill(was, false);
				if (try_khun_(i, -2))
					balance++;
			}
		for (int i = 0; i < P; i++)
			if (pid[i] == 0 || pcnt[i] == count[pid[i]] - 1) {
				Arrays.fill(was, false);
				try_khun2_(i, -2);
			}

		for (int i = 0; i < P; i++)
			if (M0[i] == -1) {
				out.write("CRIME TIME");
				return;
			}
		for (int i = 0; i < Q; i++)
			if (M[i] == -1) {
				out.write("CRIME TIME");
				return;
			}
		out.write(balance + "");
	}

	public boolean try_khun(int x) {
		if (x == -2 || was[x])
			return false;
		was[x] = true;
		for (int y = 0; y < Q; y++) {
			if (ss[x][y] && (M[y] == -1 || try_khun(M[y]))) {
				M[y] = x;
				M0[x] = y;
				return true;
			}
		}
		return false;
	}

	public boolean try_khun2(int y) {
		if (y == -2 || was[y])
			return false;
		was[y] = true;
		for (int x = 0; x < P; x++) {
			if (ss[x][y] && (M0[x] == -1 || try_khun2(M0[x]))) {
				M[y] = x;
				M0[x] = y;
				return true;
			}
		}
		return false;
	}

	public boolean try_khun_(int y, int x) {
		if (M[y] == -1 || try_khun(M[y])) {
			M[y] = x;
			if (x >= 0)
				M0[x] = y;
			return true;
		}
		return false;
	}

	public boolean try_khun2_(int x, int y) {
		if (M0[x] == -1 || try_khun2(M0[x])) {
			M0[x] = y;
			if (y >= 0)
				M[y] = x;
			return true;
		}
		return false;
	}

	int P, Q;
	boolean[][] ss;
	boolean[] was;
	int[] M, M0;

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
//			System.out.println("test "_+test+" done");
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