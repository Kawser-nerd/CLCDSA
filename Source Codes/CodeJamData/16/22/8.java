import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;

	char[] s, t;
	String sAns, tAns;
	long diff;

	void go(int id, int cmp) {
		if (id == s.length) {
			String sCur = new String(s);
			String tCur = new String(t);
			long sNum = Long.parseLong(sCur);
			long tNum = Long.parseLong(tCur);
			long curDiff = Math.abs(sNum - tNum);
			if (curDiff < diff || curDiff == diff && sCur.compareTo(sAns) < 0
					|| curDiff == diff && sCur.compareTo(sAns) == 0 && tCur.compareTo(tAns) < 0) {
				diff = curDiff;
				sAns = sCur;
				tAns = tCur;
			}
			return;
		}
		char wasS = s[id];
		char wasT = t[id];
		if (cmp == 0) {
			ArrayList<Integer> sVars = new ArrayList<>(), tVars = new ArrayList<>();
			if (s[id] == '?') {
				for (int i = 0; i < 10; i++) {
					sVars.add(i);
				}
			} else {
				sVars.add(s[id] - '0');
			}
			if (t[id] == '?') {
				for (int i = 0; i < 10; i++) {
					tVars.add(i);
				}
			} else {
				tVars.add(t[id] - '0');
			}
			boolean wasEq = false;
			for (int si : sVars) {
				for (int ti : tVars) {
					if (si == ti) {
						if (wasEq) {
							continue;
						}
						wasEq = true;
					}
					s[id] = (char) (si + '0');
					t[id] = (char) (ti + '0');
					go(id + 1, Integer.compare(si, ti));
				}
			}
		} else {
			if (s[id] == '?') {
				if (cmp < 0) {
					s[id] = '9';
				} else {
					s[id] = '0';
				}
			}
			if (t[id] == '?') {
				if (cmp < 0) {
					t[id] = '0';
				} else {
					t[id] = '9';
				}
			}
			go(id + 1, cmp);
		}
		s[id] = wasS;
		t[id] = wasT;
	}

	public void solve() throws IOException {
		s = in.next().toCharArray();
		t = in.next().toCharArray();
		sAns = tAns = null;
		diff = Long.MAX_VALUE / 2;
		go(0, 0);
		out.println(sAns + " " + tAns);
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