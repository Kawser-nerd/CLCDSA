import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	long solve() throws IOException {

		long ans = 0;
		int n = ni();
		int a[] = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();

		if (a[0] != 0)
			return -1;

		for (int i = 1; i < n; i++)
			if (a[i] - a[i - 1] > 1)
				return -1;

		for (int i = n - 1; i >= 0; i--) {
			ans += a[i];
			if (a[i] > 0) {
				while (i > 0 && a[i] - a[i - 1] == 1)
					i--;
			}
		}

		return ans;
	}

	String ns() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine(), " ");
		}
		return tok.nextToken();
	}

	int ni() throws IOException {
		return Integer.parseInt(ns());
	}

	long nl() throws IOException {
		return Long.parseLong(ns());
	}

	double nd() throws IOException {
		return Double.parseDouble(ns());
	}

	String[] nsa(int n) throws IOException {
		String[] res = new String[n];
		for (int i = 0; i < n; i++) {
			res[i] = ns();
		}
		return res;
	}

	int[] nia(int n) throws IOException {
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = ni();
		}
		return res;
	}

	long[] nla(int n) throws IOException {
		long[] res = new long[n];
		for (int i = 0; i < n; i++) {
			res[i] = nl();
		}
		return res;
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		tok = new StringTokenizer("");
		Main main = new Main();
		out.println(main.solve());
		out.close();
	}
}