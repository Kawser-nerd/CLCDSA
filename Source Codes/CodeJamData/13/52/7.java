import java.io.*;
import java.util.*;

public class B implements Runnable {
	public static void main(String[] args) throws IOException {
		new Thread(new B()).start();
	}

	public BufferedReader br;

	public StringTokenizer in;

	public PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}

		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	int[] x, y;

	int area(int a, int b, int c) {
		return (x[b] - x[a]) * (y[c] - y[a]) - (y[b] - y[a]) * (x[c] - x[a]);
	}

	boolean intersect_1(int a, int b, int c, int d) {
		if (a > b) {
			int q = a;
			a = b;
			b = q;
		}
		if (c > d) {
			int q = c;
			c = d;
			d = q;
		}
		return Math.max(a, c) <= Math.min(b, d);
	}

	boolean intersect(int a, int b, int c, int d) {
		if (a == c || a == d || b == c || b == d)
			return false;
		return intersect_1(x[a], x[b], x[c], x[d])
				&& intersect_1(y[a], y[b], y[c], y[d])
				&& area(a, b, c) * area(a, b, d) <= 0
				&& area(c, d, a) * area(c, d, b) <= 0;
	}

	boolean[] take;
	int[] p;
	int[] pMax;
	int max;

	public void permutation(int k) {
		if (k == p.length) {
			for (int i = 0; i < p.length; i++) {
				for (int j = 0; j < p.length; j++) {
					if (intersect(p[i], p[(i + 1) % p.length], p[j], p[(j + 1)
							% p.length])) {
						return;
					}
				}
			}

			int sum = 0;
			for (int i = 0; i < p.length; i++) {
				sum += area(0, p[i], p[(i + 1) % p.length]);
			}

			if (sum > max) {
				max = sum;
				pMax = Arrays.copyOf(p, p.length);
			}

			return;
		}

		for (int i = 0; i < take.length; i++) {
			if (take[i])
				continue;
			take[i] = true;
			p[k] = i;
			permutation(k + 1);
			take[i] = false;
		}
	}

	public void solve() throws IOException {
		int n = nextInt();

		x = new int[n];
		y = new int[n];
		for (int i = 0; i < x.length; i++) {
			x[i] = nextInt();
			y[i] = nextInt();
		}

		take = new boolean[n];
		p = new int[n];

		max = 0;

		permutation(0);
		for (int i = 0; i < pMax.length; i++) {
			out.print(pMax[i] + " ");
		}
		out.println();
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println("Finish " + i + " test!");
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
