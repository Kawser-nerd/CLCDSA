import java.util.*;
import java.math.*;
import java.io.*;

public class b {
	
	int n;
	int[] a;

	private void solve() throws Exception {
		n = nextInt();
		a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		int lo = 0, hi = n + 1;
		while (hi - lo > 1) {
			int mid = (lo + hi) / 2;
			if (canDo(mid))
				lo = mid;
			else
				hi = mid;
		}
		out.println(lo);
	}

	private boolean canDo(int len) {
		boolean[] used = new boolean[n];
		ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < n; ++i) {
			if (used[i])
				continue;
			for (ArrayList<Integer> l : res) {
				if (l.get(l.size() - 1).intValue() == a[i] - 1) {
					l.add(a[i]);
					used[i] = true;
					break;
				}
			}
			if (!used[i]) {
				ArrayList<Integer> ne = new ArrayList<Integer>();
				used[i] = true;
				ne.add(a[i]);
				int pos = i;
				while (ne.size() < len) {
					if (pos == n)
						return false;
					if (!used[pos] && ne.get(ne.size() - 1).intValue() + 1 == a[pos]) {
						used[pos] = true;
						ne.add(a[pos]);
					}
					++pos;
				}
				if (ne.size() != len)
					throw new AssertionError();
				res.add(ne);
			}
		}
		return true;
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private b(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	private b() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			St = new StringTokenizer("");
			out = new PrintWriter(System.out);
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new b("b").run();
	}
}
