import java.io.*;
import java.util.*;
import java.math.*;

public class Stup {

	public static void main(String[] args) {
		new Stup().run();
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

	String FNAME = "notes";

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 1; test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int low = nextInt();
			int high = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			int ans = -1;
			for (int t = low; t <= high; t++) {
				boolean good = true;
				for (int i = 0; good && i < a.length; i++) {
					good &= (a[i] % t == 0) || (t % a[i] == 0);
				}
				if (good) {
					ans = t;
					break;
				}
			}
			if (ans < 0) {
				out.println("NO");
			} else {
				out.println(ans);
			}
		}
	}
}
