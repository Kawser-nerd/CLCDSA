import java.io.*;
import java.util.*;

public class Lottery {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int a = in.nextInt() - 1, b = in.nextInt() - 1, k = in.nextInt() - 1;

		int[] as = digits(a);
		int[] bs = digits(b);
		int[] ks = digits(k);

		long[][][][] dp = new long[31][2][2][2];

		dp[30][0][0][0] = 1;

		for (int bit = 29; bit >= 0; bit--) {
			for (int was1 = 0; was1 < 2; was1++) {
				for (int was2 = 0; was2 < 2; was2++) {
					for (int was3 = 0; was3 < 2; was3++) {
						long val = dp[bit + 1][was1][was2][was3];
						if (val == 0) {
							continue;
						}

						for (int bit1 = 0; bit1 < 2; bit1++) {
							for (int bit2 = 0; bit2 < 2; bit2++) {
								int bit3 = bit1 & bit2;

								if (ok(bit, was1, bit1, as) && ok(bit, was2, bit2, bs)
										&& ok(bit, was3, bit3, ks)) {

									dp[bit][newState(bit, was1, bit1, as)][newState(bit, was2,
											bit2, bs)][newState(bit, was3, bit3, ks)] += val;
								}
							}
						}
					}
				}
			}
		}

		long result = 0;
		for (int was1 = 0; was1 < 2; was1++) {
			for (int was2 = 0; was2 < 2; was2++) {
				for (int was3 = 0; was3 < 2; was3++) {
					result += dp[0][was1][was2][was3];
				}
			}
		}
		out.println(result);
	}

	private boolean ok(int pos, int was, int bit, int[] a) {
		if (was == 1) {
			return true;
		}
		return bit <= a[pos];
	}

	private int newState(int pos, int was, int bit, int[] a) {
		if (was == 1) {
			return 1;
		}
		return (bit < a[pos]) ? 1 : 0;
	}

	private int[] digits(int a) {
		int[] d = new int[30];
		for (int i = 0; i < 30; i++) {
			d[i] = a % 2;
			a >>>= 1;
		}
		return d;
	}

	void run() {
		try {
			in = new FastScanner("input.txt");
			out = new PrintWriter("output.txt");
			int T = in.nextInt();
			for (int i = 1; i <= T; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", i);
				solve();
				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
						+ " ms");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
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

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Lottery().run();
	}
}
