import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;
	
	public void solve() throws IOException {
		int p = in.nextInt();
		int[] e = new int[p];
		int[] f = new int[p];
		TreeMap<Integer, Integer> toIdx = new TreeMap<>();
		for (int i = 0; i < p; i++) {
			e[i] = in.nextInt();
			toIdx.put(e[i], i);
		}
		int sum = 0;
		for (int i = 0; i < p; i++) {
			f[i] = in.nextInt();
			sum += f[i];
		}
		int n = 0;
		while ((1 << n) < sum)
			n++;
		
		f[0]--;
		int pt = 0;
		int[] set = new int[n];
		for (int i = 0; i < n; i++) {
			while (pt < p && f[pt] == 0)
				pt++;
			set[i] = e[pt];
			
			int countProfiles = 1 << i;
			for (int pr = 0; pr < countProfiles; pr++) {
				int curSum = set[i];
				for (int j = 0; j < i; j++) {
					if (((pr >> j) & 1) != 0) {
						curSum += set[j];
					}
				}
				int idx = toIdx.get(curSum);
				f[idx]--;
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(set[i] + " ");
		}
		out.println();
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.out.println(i);
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
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

	public static void main(String[] arg) {
		new A().run();
	}
}