import java.util.*;
import java.math.*;
import java.io.*;

public class b {
	
	int n, minD;
	int[] place, amount;

	private void solve() throws Exception {
		n = nextInt();
		minD = nextInt();
		place = new int[n];
		amount = new int[n];
		for (int i = 0; i < n; ++i) {
			place[i] = nextInt();
			amount[i] = nextInt();
		}
		double lo = 0, hi = 1e16;
		for (int it = 0; it < 300; ++it) {
			double mid = (lo + hi) / 2.;
			if (canDo(mid))
				hi = mid;
			else
				lo = mid;
		}
		out.printf("%.12f\n", hi);
	}

	private boolean canDo(double maxWalk) {
		double maxX = -1e30;
		for (int i = 0; i < n; ++i) {
			maxX = Math.max(maxX + minD, place[i] - maxWalk);
			maxX += (double)minD * (amount[i] - 1);
			double right = place[i] + maxWalk;
			if (Math.abs(maxX - right) > 1e-10 && maxX > right)
				return false;
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
