import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		Random rng = new Random();
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = nextInt();
		}
		Arrays.sort(a);
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		
		int bad = n;
		for (int i = 0; i < n; i++) {
			if (a[i] <= i) {
				bad = i;
				break;
			}
		}
		
		bad--;
		
		int right = a[bad] - bad - 1;
		int up = 0;
		for (int i = bad + 1; i < n; i++) {
			if (a[i] > bad) {
				up++;
			} else {
				break;
			}
		}
		
		out.println((right | up) % 2 == 0 ? "Second" : "First");
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}