import java.io.*;
import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "D";
//	final String filename = problem + "-sample";

	 final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	// final String filename= problem+"-large";

	public void solve() throws Exception {
		ArrayList<Pair> p = new ArrayList<Pair>();

		int M = iread();
		long[] keys = new long[M];
		long[] values = new long[M];
		for (int i = 0; i < M; i++) {
			keys[i] = lread();
		}
		for (int i = 0; i < M; i++) {
			values[i] = lread();
		}
		long NN = 0;
		for (int i = 0; i < M; i++) {
			p.add(new Pair(keys[i], values[i]));
			NN += values[i];
		}
		int N = 0;
		while ((1L << N) < NN)
			N++;
		Collections.sort(p);
		long[] ans = new long[N];
		TreeMap<Long, Long> sequence = new TreeMap<Long, Long>();
		TreeMap<Long, Long> sequence2 = new TreeMap<Long, Long>();
		for (int i = 0; i < p.size(); i++)
			sequence.put(p.get(i).key, p.get(i).value);
		int cur = 0;
		long zeros = 0;
		long zeros0 = p.get(0).value;
		while ((1 << zeros) < zeros0)
			zeros++;
		c1: for (int k = 0; k < N;) {
			cycle: for (; cur < M; cur++) {
				long add = p.get(cur).key;
				if (add == 0) {
					while (zeros > 0) {
						ans[k++] = 0;
						zeros--;
					}
					continue;
				}
				sequence2.clear();
				if (add < 0) {
					boolean first = true;
					for (Long x : sequence.keySet()) {
						if (first && x >= 0) {
							continue cycle;
						}
						first = false;
						long val = sequence.get(x);
						if (sequence2.containsKey(x))
							val -= sequence2.get(x);
						if (val > 0) {
							if (!sequence.containsKey(x - add)) {
								continue cycle;
							}
							sequence2.put(x - add, val);
						} else if (val < 0)
							continue cycle;
					}
				} else if (add > 0) {
					for (Long x : sequence.keySet()) {
						long val = sequence.get(x);
						if (sequence2.containsKey(x - add))
							val -= sequence2.get(x - add);
						if (val > 0) {
							if (!sequence.containsKey(x + add)) {
								continue cycle;
							}
							sequence2.put(x, val);
						} else if (val < 0)
							continue cycle;
					}
				}
				TreeMap seq = sequence2;
				sequence2 = sequence;
				sequence = seq;
				ans[k++] = add;
				continue c1;
			}
		}
		for (int i = 0; i < N; i++)
			out.write(" " + ans[i]);
	}

	class Pair implements Comparable<Pair> {
		long key;
		long value;
		boolean mark;

		public Pair(long key, long value) {
			super();
			this.key = key;
			this.value = value;
		}

		@Override
		public int compareTo(Pair o) {
			return Long.compare(key, o.key);
		}
	}

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