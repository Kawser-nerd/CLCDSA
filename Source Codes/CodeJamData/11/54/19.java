import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;


public class D implements Runnable {

	
	boolean sq(long a) {
		long s = (long)Math.sqrt((double)a);
		for (; s * s < a; ++s);
		for (; s * s > a; --s);
		return s * s == a;
	}
	
	private void solve() throws IOException {
		char[] t = next().toCharArray();
		char[] u = new char[t.length];
		int cnt = 0;
		for (int i = 0; i < t.length; ++i) {
			cnt += t[i] == '?' ? 1 : 0;
		}
		int k = 0;
		long r = 0;
		for (int i = 0; i < (1 << cnt); ++i) {
			k = i;
			for (int j = 0; j < u.length; ++j) {
				if (t[j] != '?') {
					u[j] = t[j];
				} else {
					u[j] = k % 2 == 1 ? '1' : '0';
					k /= 2;
				}
			}
			r = 0;
			for (int j = 0; j < u.length; ++j) {
				r *= 2;
				r += (int)(u[j] - '0');
			}
			if (sq(r)) {
				out.println(u);
				return;
			}
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Thread(new D()).start();
	}

	private BufferedReader br;
	private StringTokenizer st;
	private PrintWriter out;
	
	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader("input.txt"));
			st = new StringTokenizer("");
			out = new PrintWriter("out.txt");

			
			int T = nextInt();
			for (int i = 1; i <= T; ++i) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();			
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
		
	}

	
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String temp = br.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
}
