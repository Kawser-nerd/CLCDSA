import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextDouble();
		}
		
		int m = nextInt();
		long k = nextLong();
		
		int[] b = new int[m];
		
		for (int i = 0; i < m; i++) {
			b[i] = nextInt() - 1;
		}
		
		int[] perm = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			perm[i] = i;
		}
		
		for (int pos : b) {
			pos--;
			int tmp = perm[pos];
			perm[pos] = perm[pos + 1];
			perm[pos + 1] = tmp;
		}
		
		int[] res = pow(perm, k);
		
		double[] deltas = new double[n - 1];
		for (int i = 0; i < n - 1; i++) {
			int idx = res[i];
			deltas[i] = a[idx + 1] - a[idx];
		}
		
		double tmp = a[0];
		out.println(tmp);
		for (double d : deltas) {
			tmp += d;
			out.println(tmp);
		}
	}
	
	int[] mult(int[] a, int[] b) {
		int[] c = new int[a.length];
		for (int i = 0; i < a.length; i++) {
//			c[i] = b[a[i]]; // or???
			c[i] = a[b[i]];
		}
		return c;
	}
	
	int[] pow(int[] p, long k) {
		int[] ret = new int[p.length];
		for (int i = 0; i < p.length; i++) {
			ret[i] = i;
		}
		
		for (; k > 0; k >>= 1) {
			if ((k & 1) == 1) {
				ret = mult(ret, p);
			}
			p = mult(p, p);
		}
		return ret;
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