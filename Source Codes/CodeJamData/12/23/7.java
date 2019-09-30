import java.util.*;
import java.math.*;
import java.io.*;

public class C {

	private void solve() throws Exception {
		int n = nextInt();
		int[] vals = new int[n];
		for (int i = 0; i < n; ++i) {
			vals[i] = nextInt();
		}
		Map<Integer, Integer> sumSets = new HashMap<Integer, Integer>();
		for (int mask = 1; mask < (1 << n); ++mask) {
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				if ((mask & (1 << i)) > 0) {
					sum += vals[i];
				}
			}
			if (sumSets.containsKey(sum)) {
				int otherMask = sumSets.get(sum);
				out.println();
				for (int i = 0; i < n; ++i) {
					if ((otherMask & (1 << i)) > 0) {
						out.print(vals[i] + " ");
					}
				}
				out.println();
				for (int i = 0; i < n; ++i) {
					if ((mask & (1 << i)) > 0) {
						out.print(vals[i] + " ");
					}
				}
				out.println();
				return;
			}
			sumSets.put(sum, mask);
		}
		out.println("Impossible");
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

	private C(String name) {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter("output.txt"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new C("c").run();
	}
}
