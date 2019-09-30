import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int p = in.nextInt();
			int[] e = new int[p];
			int[] f = new int[p];
			for (int i = 0; i < p; i++) {
				e[i] = in.nextInt();
			}
			for (int i = 0; i < p; i++) {
				f[i] = in.nextInt();
			}
			f[0]--;
			long sum = 0;
			for (int i = 0; i < p; i++) {
				sum += f[i];
			}
			int cnt = 1;
			while (1L << cnt < sum) {
				cnt++;
			}
			int[] all = new int[cnt];
			int cur = 0;
			int[] summ = new int[1 << cnt];
			{
				int i = 0;
				while (cur < cnt) {
					if (f[i] > 0) {
						all[cur++] = e[i];
						for (int st = 0; st < 1 << (cur - 1); st++) {
							summ[st | (1 << (cur - 1))] = summ[st]
									+ all[cur - 1];
							int le = 0, ri = p;
							int need = summ[st] + all[cur - 1];
							while (ri - le > 1) {
								int mid = (le + ri) >>> 1;
								if (e[mid] <= need) {
									le = mid;
								} else {
									ri = mid;
								}
							}
							f[le]--;
						}
					} else {
						i++;
					}
				}
			}
			for (int i = 0; i < cnt; i++) {
				out.print(all[i]);
				if (i != cnt - 1) {
					out.print(" ");
				} else {
					out.println();
				}
			}
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("D.in"));
			out = new PrintWriter(new File("D.out"));

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
		new D().run();
	}
}