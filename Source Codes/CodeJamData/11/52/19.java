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


public class B implements Runnable {

	
	
	
	private void solve() throws IOException {
		int n = nextInt();
		if (n == 0) {
			out.println(0);
			return;
		}
		int[] x = new int[10001];
		for (int i = 0; i < n; ++i) {
			++x[nextInt()];
		}
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < x.length; ++i) {
			while (x[i] > 0){
				int j = 0;
				for (j = i + 1; j < x.length && x[j] >= x[j - 1]; ++j)
					;
				min = Math.min(j - i, min);
				for (--j; j >= i; --j) {
					--x[j];
				}
			}
		}
		out.println(min);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Thread(new B()).start();
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
