import java.io.*;
import java.util.*;
import java.math.*;

public class Space {

	public static void main(String[] args) {
		new Space().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(2635243643L);

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	String FNAME = "space";

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 1; test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int l = nextInt();
			long t = nextLong();
			int n = nextInt();
			int c = nextInt();
			long[] a = new long[c];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			ArrayList<Long> al = new ArrayList<Long>();
			long time = 0;
			for (int i = 0; i < n; i++) {
				int j = i % c;
				long left = time;
				long right = time + 2 * a[j];
				if (right > t) {
					left = Math.max(left, t);
					al.add((right - left) / 2);
				}
				time = right;
			}
			Collections.sort(al);
			for (int i = al.size() - 1; i >= 0 && l > 0; i--) {
				time -= al.get(i);
				l--;
			}
			out.println(time);
		}
	}

}
