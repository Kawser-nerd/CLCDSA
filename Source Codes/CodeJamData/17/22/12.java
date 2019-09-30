import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;

	class Letter implements Comparable<Letter> {
		String c;
		int cnt;
		ArrayList<String> s;

		public Letter(String c, int cnt) {
			super();
			this.c = c;
			this.cnt = cnt;
			s = new ArrayList<String>();
		}

		@Override
		public int compareTo(Letter o) {
			return Integer.compare(o.s.size(), s.size());
		}
	}

	String[] val;
	int[] next;

	void print(int head) {
		for (int e = head; e != 0; e = next[e]) {
			out.print(val[e]);
		}
		out.println();
	}

	String mul(String s, int x) {
		StringBuffer result = new StringBuffer();
		for (int i = 0; i < x; i++) {
			result.append(s);
		}
		return result.toString();
	}

	final String IMPOSSIBLE = "IMPOSSIBLE";

	boolean make(Letter lV, Letter lY) {
		if (lV.cnt != 0) {
			if (lV.cnt >= lY.cnt) {
				out.println(IMPOSSIBLE);
				return false;
			}
			lY.s.add(mul(lY.c + lV.c, lV.cnt) + lY.c);
			lY.cnt -= lV.cnt + 1;
			lV.cnt = 0;
		}
		return true;
	}

	void add(Letter lY) {
		for (int i = 0; i < lY.cnt; i++) {
			lY.s.add(lY.c);
		}
		lY.cnt = 0;
	}

	public void solve() throws IOException {
		int n = in.nextInt();
		String[] cs = new String[] { "R", "O", "Y", "G", "B", "V" };
		Letter[] lets = new Letter[cs.length];
		int cntNotZeros = 0;
		for (int i = 0; i < lets.length; i++) {
			lets[i] = new Letter(cs[i], in.nextInt());
			if (lets[i].cnt != 0) {
				cntNotZeros++;
			}
		}
		if (cntNotZeros == 1) {
			if (n > 1) {
				out.println(IMPOSSIBLE);
				return;
			}
		} else if (cntNotZeros == 2) {
			for (int i = 0; i < lets.length; i++) {
				if (lets[i].cnt != 0) {
					for (int j = i + 1; j < lets.length; j++) {
						if (lets[j].cnt != 0) {
							if (lets[i].cnt != lets[j].cnt) {
								out.println(IMPOSSIBLE);
								return;
							}
						}
					}
				}
			}
		} else {
			Letter lR = lets[0];
			Letter lO = lets[1];
			Letter lY = lets[2];
			Letter lG = lets[3];
			Letter lB = lets[4];
			Letter lV = lets[5];
			if (!make(lV, lY) || !make(lG, lR) || !make(lO, lB))
				return;
		}
		
		// FINAL STAGE
		for (Letter let : lets) {
			add(let);
		}
		Arrays.sort(lets);
		Letter[] a = new Letter[3];
		int ap = 0;
		for (int i = 0; i < lets.length; i++) {
			if (lets[i].s.size() != 0) {
				a[ap++] = lets[i];
			}
		}
		while (ap < 3) {
			a[ap++] = new Letter("Z", 0);
		}
		if (a[0].s.size() > a[1].s.size() + a[2].s.size()) {
			out.println(IMPOSSIBLE);
			return;
		}

		int head = 0;
		final int MAX_SIZE = 2000;
		next = new int[MAX_SIZE];
		val = new String[MAX_SIZE];

		head = 0;
		int cntE = 0;
		for (String ss : a[0].s) {
			next[++cntE] = head;
			head = cntE;
			val[cntE] = ss;
		}
		int cur = head;
		for (int type = 1; type < 3; type++) {
			for (String ss : a[type].s) {
				int nextNext = next[cur];
				next[cur] = ++cntE;
				next[cntE] = nextNext;
				val[cntE] = ss;
				cur = nextNext;
				if (cur == 0) {
					cur = head;
				}
			}
		}
		print(head);
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tn = in.nextInt();
			for (int i = 0; i < tn; i++) {
				System.err.println(i);
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new B().run();
	}
}