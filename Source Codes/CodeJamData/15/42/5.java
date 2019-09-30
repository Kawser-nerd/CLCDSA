import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	final int ITER = 100;

	class O implements Comparable<O> {
		double r, c;

		public O(double r, double c) {
			super();
			this.r = r;
			this.c = c;
		}

		@Override
		public int compareTo(O o) {
			return Double.compare(c, o.c);
		}

	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			double vol = in.nextDouble();
			double needC = in.nextDouble();
			O[] a = new O[n];
			double[] r = new double[n];
			double[] c = new double[n];
			for (int i = 0; i < n; i++) {
				a[i] = new O(in.nextDouble(), in.nextDouble());
			}
			Arrays.sort(a);
			for (int i = 0; i < n; i++) {
				r[i] = a[i].r;
				c[i] = a[i].c;
			}
			double sumC = 0, sumR = 0;
			for (int i = 0; i < n; i++) {
				sumC += c[i] * r[i];
				sumR += r[i];
			}
			boolean allBigger = true, allSmaller = true;
			for (int i = 0; i < n; i++) {
				if (c[i] >= needC) {
					allSmaller = false;
				}
				if (c[i] <= needC) {
					allBigger = false;
				}
			}
			if (allBigger || allSmaller) {
				out.println("IMPOSSIBLE");
				continue;
			}
			double curC = sumC / sumR;
			if (curC >= needC) {
				double left = 0, right = n;
				for (int it = 0; it < ITER; it++) {
					double mid = (left + right) / 2;
					sumC = 0;
					sumR = 0;
					for (int i = 0; i < n; i++) {
						double pr = 1.0;
						if (i > mid) {
							pr = 0;
						} else {
							if (i + 1 <= mid) {
								pr = 1;
							} else {
								pr = mid - i;
							}
						}
						sumC += c[i] * pr * r[i];
						sumR += r[i] * pr;
					}
					curC = sumC / sumR;
					if (curC <= needC + 1e-12) {
						left = mid;
					} else {
						right = mid;
					}
				}
				double mid = (left + right) / 2;
				sumC = 0;
				sumR = 0;
				for (int i = 0; i < n; i++) {
					double pr = 1.0;
					if (i > mid) {
						pr = 0;
					} else {
						if (i + 1 <= mid) {
							pr = 1;
						} else {
							pr = mid - i;
						}
					}
					sumC += c[i] * pr * r[i];
					sumR += r[i] * pr;
				}
				double needTime = vol / sumR;
				out.println(needTime);
			} else {
				double left = 0, right = n;
				for (int it = 0; it < ITER; it++) {
					double mid = (left + right) / 2;
					sumC = 0;
					sumR = 0;
					for (int i = 0; i < n; i++) {
						double pr = 1.0;
						if (i > mid) {
							pr = 1;
						} else {
							if (i + 1 <= mid) {
								pr = 0;
							} else {
								pr = i + 1 - mid;
							}
						}
						sumC += c[i] * pr * r[i];
						sumR += r[i] * pr;
					}
					curC = sumC / sumR;
					if (curC >= needC - 1e-12) {
						right = mid;
					} else {
						left = mid;
					}
				}
				double mid = (left + right) / 2;
				sumC = 0;
				sumR = 0;
				for (int i = 0; i < n; i++) {
					double pr = 1.0;
					if (i > mid) {
						pr = 1;
					} else {
						if (i + 1 <= mid) {
							pr = 0;
						} else {
							pr = i + 1 - mid;
						}
					}
					sumC += c[i] * pr * r[i];
					sumR += r[i] * pr;
				}
				double needTime = vol / sumR;
				out.println(needTime);
			}
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("B.in"));
			out = new PrintWriter(new File("B.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
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

	public static void main(String[] args) {
		new B().run();
	}
}