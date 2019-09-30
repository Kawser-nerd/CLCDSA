import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
	
	int n;
	int x, y;
	
	private void solve() throws Exception {
		n = nextInt();
		x = Math.abs(nextInt());
		y = nextInt();
		int sum = 0, layer = 0;
		while (sum <= n) {
			sum += getCount(layer);
			++layer;
		}
		--layer;
		sum -= getCount(layer);
		--layer;
		int targetLayer = (x + y) / 2;
		int maxH = targetLayer * 2;
		if (targetLayer <= layer) {
			out.println("1.0");
			return;
		} else if (targetLayer > layer + 1 || y == targetLayer * 2) {
			out.println("0.0");
			return;
		}
		int countLeft = n - sum;
		//System.err.println(n + " " + countLeft + " " + getCount(targetLayer));
		double[][] prob = new double[maxH + 1][maxH + 1];
		prob[0][0] = 1;
		//System.err.println(countLeft);
		for (int i = 1; i <= countLeft; ++i) {
			for (int left = 0; left < Math.min(i, maxH + 1); ++left) {
				int right = i - left - 1;
				if (right > maxH) {
					continue;
				}
				for (int it = 0; it < 2; ++it) {
					int newLeft = left + it, newRight = right + (1 - it);
					if (newLeft == maxH + 1 && newRight == maxH + 1) {
						System.err.println("!!!");
					}
					if (newLeft == maxH + 1) {
						--newLeft;
						++newRight;
					}
					if (newRight == maxH + 1) {
						++newLeft;
						--newRight;
					}
					//System.err.println(maxH + " " + newLeft + " " + newRight + " " + n);
					prob[newLeft][newRight] += prob[left][right] * 0.5;
				}
			}
		}
		double ans = 0;
		for (int left = 0; left <= Math.min(countLeft, maxH); ++left) {
			int right = countLeft - left;
			if (right > maxH) {
				continue;
			}
			if (right > y) {
				ans += prob[left][right];
			}
		}
		//out.println(ans);
		out.printf("%.10f\n", ans);
	}

	private int getCount(int layer) {
		return layer * 2 * 2 + 1;
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

	private B(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new B("B").run();
	}
}
