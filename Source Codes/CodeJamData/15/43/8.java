import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
	// final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

	// final String filename= problem+"-small-attempt1";
	final String filename = problem + "-large";

	public void solve() throws Exception {
		int N = iread();

		HashMap<String, Integer> words = new HashMap<String, Integer>();
		ArrayList<Integer>[] sentences = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			String[] r = readword().split(" +");
			sentences[i] = new ArrayList<Integer>();
			for (int j = 0; j < r.length; j++) {
				int ind = -1;
				if (words.containsKey(r[j]))
					ind = words.get(r[j]);
				else {
					ind = words.size();
					words.put(r[j], ind);
				}
				sentences[i].add(ind);
			}
		}

		int M = words.size();
		int start = 0, end = 1;
		int K = 2;
		int[] wordsIn = new int[M], wordsOut = new int[M];
		for (int i = 0; i < M; i++) {
			wordsIn[i] = K++;
			wordsOut[i] = K++;
		}
		first = new Edge[K];
		for (int j = 0; j < sentences[0].size(); j++)
			add(start, wordsIn[sentences[0].get(j)], 1);
		for (int j = 0; j < sentences[1].size(); j++)
			add(wordsOut[sentences[1].get(j)], end, 1);
		for (int i = 0; i < M; i++) {
			add(wordsIn[i], wordsOut[i], 1);
		}
		boolean[][] g = new boolean[M][M];
		for (int i = 2; i < N; i++) {
			for (int j = 0; j < sentences[i].size(); j++) {
				for (int k = j + 1; k < sentences[i].size(); k++) {
					int x = sentences[i].get(j), y = sentences[i].get(k);
					g[x][y] = g[y][x] = true;
				}
			}
		}
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++) {
				if (i != j && g[i][j]) {
					add(wordsOut[i], wordsIn[j], 1);
				}
			}
		int ans = 0;
		was = new boolean[K];
		while (true) {
			Arrays.fill(was, false);
			int times = 0;
			while (dfs(0)) {
				ans++;
				times++;
			}
			if (times == 0)
				break;
		}
		out.write(ans + "");
	}

	boolean[] was;

	boolean dfs(int x) {
		if (x == 1) {
			return true;
		}
		was[x] = true;
		for (Edge e = first[x]; e != null; e = e.next) {
			if (e.cap > 0) {
				if (!was[e.to] && dfs(e.to)) {
					e.cap--;
					e.back.cap++;
					return true;
				}
			}
		}
		return false;
	}

	void add(int from, int to, int cap) {
		Edge e1 = new Edge(from, to, cap);
		Edge e2 = new Edge(to, from, 0);
		e1.back = e2;
		e2.back = e1;
	}

	Edge[] first;

	class Edge {
		int from, to, cap;
		Edge next, back;

		public Edge(int from, int to, int cap) {
			this.from = from;
			this.to = to;
			this.cap = cap;
			next = first[from];
			first[from] = this;
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
		String s;
		do {
			s = in.readLine();
		} while (s.length() == 0);
		return s;
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