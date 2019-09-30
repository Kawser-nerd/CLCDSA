import java.util.*;
import java.io.*;

public class Main {

	void solve() {
		int r = in.nextInt(), c = in.nextInt();
		char[][] a = new char[r][c];
		for (int i = 0; i < r; i++) {
			a[i] = in.nextToken().toCharArray();
		}
		
		int ans = Math.max(r, c);
		int[][] eq = new int[r - 1][];
		int[][] notEq = new int[r - 1][];
		for (int i = 0; i < r - 1; i++) {
			eq[i] = getEq(a[i], a[i + 1], true);
			notEq[i] = getEq(a[i], a[i + 1], false);
		}
		int[] lcp = new int[r - 1];
		int[] left = new int[r - 1], right = new int[r - 1], stack = new int[r];
		
		for (int pos = 0; pos < c; pos++) {
			for (int i = 0; i < r - 1; i++) {
				lcp[i] = Math.max(eq[i][pos], notEq[i][pos]) - pos;
			}
			int head;
			head = 1;
			stack[0] = -1;
			for (int i = 0; i < r - 1; i++) {
				while (head > 1 && lcp[i] <= lcp[stack[head - 1]]) {
					head--;
				}
				left[i] = stack[head - 1] + 1;
				stack[head++] = i;
			}
			head = 1;
			stack[0] = r - 1;
			for (int i = r - 2; i >= 0; i--) {
				while (head > 1 && lcp[i] <= lcp[stack[head - 1]]) {
					head--;
				}
				right[i] = stack[head - 1] - 1;
				stack[head++] = i;
			}
			
			for (int i = 0; i < r - 1; i++) {
				int dist = right[i] - left[i] + 1;
				ans = Math.max(ans, lcp[i] * (dist + 1));
			}
		}
		
		out.println(ans);
	}
	
	int[] getEq(char[] a, char[] b, boolean flag) {
		int[] result = new int[a.length];
		for (int i = 0; i < a.length; ) {
			if ((a[i] == b[i]) != flag) {
				result[i] = i;
				i++;
				continue;
			}
			int j = i;
			while (j < a.length && ((a[j] == b[j]) == flag)) {
				j++;
			}
			for (int t = i; t < j; t++) {
				result[t] = j;
			}
			
			i = j;
		}
		return result;
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}