import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemCLarge {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		ans = new int[T+1];
		a = new BigInteger[T+1];
		b = new BigInteger[T+1];
		for (int cn = 1 ; cn <= T ; cn++) {
			String A = in.next();
			String B = in.next();
			a[cn] = new BigInteger(A);
			b[cn] = new BigInteger(B);
		}
		solve();
		
		for (int cn = 1 ; cn <= T ; cn++) {
			out.println(String.format("Case #%d: %d", cn, ans[cn]));
		}
		out.flush();
	}
	
	
	static BigInteger[] a, b;
	static int[] ans;
	
	private static void dfs(String x, BigInteger[] a, BigInteger[] b) {
		if (x.length() >= 71) {
			return;
		}
		BigInteger xi = new BigInteger(x);
		BigInteger xi2 = BigInteger.ONE.multiply(xi).multiply(xi);
		
		if (x.charAt(0) != '0') {
			if (xi2.toString().equals(new StringBuffer(xi2.toString()).reverse().toString())) {
			} else {
				return;
			}
			for (int i = 1 ; i < a.length ; i++) {
				if (a[i].compareTo(xi2) <= 0 && xi2.compareTo(b[i]) <= 0) {
					ans[i]++;
				}
			}
		}
		if (x.equals("3")) {
			return;
		}
		dfs("0" + x + "0", a, b);
		dfs("1" + x + "1", a, b);
		dfs("2" + x + "2", a, b);
	}


	private static void solve() {
		dfs("0", a, b);
		dfs("1", a, b);
		dfs("2", a, b);
		dfs("3", a, b);
		dfs("00", a, b);
		dfs("11", a, b);
		dfs("22", a, b);
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
