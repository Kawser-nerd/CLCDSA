import java.io.*;
import java.util.*;

public class Osmos {
	public static void main(String[] args) {
		new Osmos().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

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

	String FNAME = "a";

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + (test) + ": ");
			int x = nextInt();
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			Arrays.sort(a);
			int[] b = new int[n + 1];
			Arrays.fill(b, Integer.MAX_VALUE / 2);
			b[0] = 0;
			for (int i = 0; i + 1 < b.length; i++) {
				int add = 0;
				while (x <= a[i] && x > 1) {
					add++;
					x = 2 * x - 1;
				}
				if (x > a[i]) {
					b[i + 1] = b[i] + add;
					x += a[i];
				}
			}
			int ans = Integer.MAX_VALUE / 2;
			for (int i = 0; i < b.length; i++) {
				ans = Math.min(ans, b[i] + (n - i));
			}
			out.println(ans);
		}
	}
}
