import java.io.*;
import java.util.*;

public class B {

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	String get() throws Exception {
		int n = nextInt();
		int t1 = nextInt();
		int t12 = nextInt();
		int t2 = nextInt();
		int t23 = nextInt();
		int t3 = nextInt();
		int t13 = nextInt();
		if (t1 == t23)
			if (t1 + t23 == n)
				return build("RG", t1);

		if (t2 == t13)
			if (t2 + t13 == n)
				return build("YV", t2);

		if (t3 == t12)
			if (t3 + t12 == n)
				return build("BO", t3);

		int vt1 = t1;
		int vt2 = t2;
		int vt3 = t3;

		String rR = build("RG", t23) + "R";
		t1 -= t23;
		String rY = build("YV", t13) + "Y";
		t2 -= t13;
		String rB = build("BO", t12) + "B";
		t3 -= t12;
		//System.err.println(rR + " " + rY + " " + rB);
		if (vt1 > 0 && t1 <= 0)
			return "IMPOSSIBLE";
		if (vt2 > 0 && t2 <= 0)
			return "IMPOSSIBLE";
		if (vt3 > 0 && t3 <= 0)
			return "IMPOSSIBLE";
		String s = solveSimple(t1, t2, t3);
		if (s.equals("IMPOSSIBLE"))
			return s;
		if (t23 != 0)
			s = s.replaceFirst("R", rR);
		if (t13 != 0)
			s = s.replaceFirst("Y", rY);
		if (t12 != 0)
			s = s.replaceFirst("B", rB);
		return s;
	}

	String build(String rep, int q) {
		StringBuilder x = new StringBuilder("");
		for (int i = 0; i < q; i++)
			x.append(rep);
		return x.toString();
	}

	String solveSimple(int r, int y, int b) {
		if (r + y < b)
			return "IMPOSSIBLE";
		if (r + b < y)
			return "IMPOSSIBLE";
		if (b + y < r)
			return "IMPOSSIBLE";

		StringBuilder ans = new StringBuilder("");
		int max = Math.max(r, Math.max(y, b));
		int first = (r == max ? 0 : y == max ? 1 : 2);
		int last = first;
		if (first == 0) {
			ans.append("R");
			r--;
			last = 0;
		}

		if (first == 1) {
			ans.append("Y");
			y--;
			last = 1;
		}

		if (first == 2) {
			ans.append("B");
			b--;
			last = 2;
		}

		while (r + y + b != 0) {
			boolean canr = last != 0;
			boolean cany = last != 1;
			boolean canb = last != 2;

			max = Math.max(r, Math.max(y, b));

			if (first == 0 && r == max && canr) {
				ans.append("R");
				r--;
				last = 0;
			} else if (first == 1 && y == max && cany) {
				ans.append("Y");
				y--;
				last = 1;
			} else if (first == 2 && b == max && canb) {
				ans.append("B");
				b--;
				last = 2;
			} else if (r == max && canr) {
				ans.append("R");
				r--;
				last = 0;
			} else if (y == max && cany) {
				ans.append("Y");
				y--;
				last = 1;
			} else if (b == max && canb) {
				ans.append("B");
				b--;
				last = 2;
			} else {
				int adjr = r * 2 + first == 0 ? 1 : 0;
				int adjy = y * 2 + first == 1 ? 1 : 0;
				int adjb = b * 2 + first == 2 ? 1 : 0;

				if (canr && cany) {
					if (adjr > adjy) {
						ans.append("R");
						r--;
						last = 0;
					} else {
						ans.append("Y");
						y--;
						last = 1;
					}
				} else if (canr && canb) {
					if (adjr > adjb) {
						ans.append("R");
						r--;
						last = 0;
					} else {
						ans.append("B");
						b--;
						last = 2;
					}
				} else if (canb && cany) {
					if (adjb > adjy) {
						ans.append("B");
						b--;
						last = 2;
					} else {
						ans.append("Y");
						y--;
						last = 1;
					}
				}
			}

		}

		return ans.toString();
	}

	void solve() throws Exception {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.println("Case #" + (i + 1) + ": " + get());
		}
	}

	void run() {
		try {
			Locale.setDefault(Locale.US);
			final String className = this.getClass().getName().toLowerCase();
			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) {
		new B().run();
	}

}
