import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "A";
	// final String filename = problem + "-sample";

//	final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		int N = iread(), D = iread();
		int S0 = iread(), As = iread(), Cs = iread(), Rs = iread();
		int M0 = iread(), Am = iread(), Cm = iread(), Rm = iread();

		child = new ArrayList[N];
		for (int i = 0; i < N; i++)
			child[i] = new ArrayList<Integer>();
		parent = new int[N];
		parent[0] = -1;
		Pair[] pairs = new Pair[N];
		int S = S0;
		for (int i = 0; i < N; i++) {
			pairs[i] = new Pair(S, i);
			S = (int) ((S * (long) As + Cs) % Rs);
		}
		Arrays.sort(pairs);
		int M = M0;
		for (int i = 1; i < N; i++) {
			M = (int) ((M * (long) Am + Cm) % Rm);
			parent[i] = M % i;
			child[M % i].add(i);
		}
		connected = new boolean[N];
		exist = new boolean[N];

		int ans = 0;
		numConnected = 0;
		int j = 0;
		for (int i = 0; i < N; i++) {
			while (j < N && pairs[j].key - D <= pairs[i].key) {
				int x = pairs[j].value;
				exist[x] = true;
				if (parent[x] == -1 || connected[parent[x]])
					dfs(x, true);
				j++;
			}
			if (numConnected > ans)
				ans = numConnected;
			int x = pairs[i].value;
			dfs(x, false);
			exist[x] = false;
		}
		out.write(ans + "");
	}

	ArrayList<Integer>[] child;
	boolean[] connected, exist;
	int numConnected;

	public void dfs(int x, boolean value) {
		if (!exist[x])
			return;
		if (connected[x] == value)
			return;
		if (value)
			numConnected++;
		else
			numConnected--;
		connected[x] = value;
		for (int i = 0; i < child[x].size(); i++)
			dfs(child[x].get(i), value);
	}

	int[] parent;

	class Pair implements Comparable<Pair> {
		int key, value;

		public Pair(int key, int value) {
			super();
			this.key = key;
			this.value = value;
		}

		@Override
		public int compareTo(Pair o) {
			return key - o.key;
		}
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
//		new Thread(new Main()).start();
		 new Thread(null, new Main(), "1", 1<<27).start();
	}
}