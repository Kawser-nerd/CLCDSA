import java.io.*;
import java.util.*;
import java.math.*;

public class C_quick implements Runnable {

	public static void main(String[] args) {
		new Thread(new C_quick()).run();
	}

	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader(FILENAME + ".in"));
			out = new PrintWriter(FILENAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;

	PrintWriter out;

	StringTokenizer st;

	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
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

	private static final String FILENAME = "C-small";
	
	int[] answ = new int[]{
			005,
			027,
			143,
			751,
			935,
			607,
			903,
			991,
			335,
			047,
			943,
			471,
			055,
			447,
			463,
			991,
			95,
			607,
			264,
			151,
			855,
			527,
			743,
			351,
			135,
			407,
			903,
			791,
			135,
			647
	};

	public void solve() throws IOException {
		int testsn = nextInt();
		for (int test = 0; test < testsn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int n = nextInt();
			double a = 3 + Math.sqrt(5);
			BigDecimal ab = new BigDecimal("5.236067977499789696409173668731276235440618359611525724270897245410520925638");
			BigDecimal ans = new BigDecimal(1);
			ans.setScale(10000, BigDecimal.ROUND_FLOOR);
			for (int i = 0; i < n; i++) {
				ans = ans.multiply(ab);
			}
			String s = ans.toString();
			//String s = answ[n - 1] + ".";
			int p = s.indexOf(".");
			String r = s.substring(Math.max(0, p - 3), p);
			while (r.length() < 3) {
				r = "0" + r;
			}
			out.println(r);
		}
	}
}
