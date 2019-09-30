import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "D";
	// final String filename = problem + "-sample";

	// final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";
	int MAX = 201;

	public void solve() throws Exception {
		int[] balance = new int[MAX];
		int S = iread();
		N = iread();
		keyCount = new int[MAX];
		for (int i = 0; i < S; i++) {
			int x = iread();
			keyCount[x]++;
			balance[x]++;
		}
		chests = new Chest[N];
		for (int i = 0; i < N; i++) {
			chests[i] = new Chest();
			chests[i].openBy = iread();
			balance[chests[i].openBy]--;
			S = iread();
			for (int j = 0; j < S; j++) {
				int x = iread();
				balance[x]++;
				chests[i].inside.add(x);
			}
		}
		for (int i = 0; i < MAX; i++)
			if (balance[i] < 0) {
				out.write("IMPOSSIBLE");
				return;
			}
		_key = new boolean[MAX];
		_opened = new boolean[MAX];

		if (!check()) {
			out.write("IMPOSSIBLE");
			return;
		}
		int[] ans = new int[N];
		cycle: for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!chests[j].opened && keyCount[chests[j].openBy] > 0) {
					keyCount[chests[j].openBy]--;
					for (Integer x : chests[j].inside)
						keyCount[x]++;
					chests[j].opened = true;
					if (check()) {
						ans[i] = j + 1;
						continue cycle;
					}
					keyCount[chests[j].openBy]++;
					for (Integer x : chests[j].inside)
						keyCount[x]--;
					chests[j].opened = false;
				}
			}
			System.out.println("FAIL");
		}
		for (int i = 0; i < N; i++) {
			if (i != 0) {
				out.write(" ");
			}
			out.write(ans[i] + "");
		}
	}

	boolean[] _key, _opened;

	public boolean check() {
		for (int i = 0; i < MAX; i++) {
			_key[i] = keyCount[i] > 0;
		}
		for (int i = 0; i < N; i++)
			_opened[i] = chests[i].opened;
		boolean flag = true;
		while (flag) {
			flag = false;
			for (int i = 0; i < N; i++) {
				if (!_opened[i] && _key[chests[i].openBy]) {
					_opened[i] = true;
					for (Integer x : chests[i].inside)
						_key[x] = true;
					flag = true;
				}
			}
		}
		for (int i = 0; i < N; i++)
			if (!_opened[i])
				return false;
		return true;
	}

	int N;
	int[] keyCount;
	int[] opened;
	Chest[] chests;

	class Chest {
		boolean opened;
		int openBy;
		ArrayList<Integer> inside = new ArrayList<Integer>();
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
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