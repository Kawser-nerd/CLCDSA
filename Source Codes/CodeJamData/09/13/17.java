import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;

public class C {
	
// 	private static String PNAME = "C-test";
//	private static String PNAME = "C-small-attempt0";
	private static String PNAME = "C-large";
 	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(PNAME + ".in"));
		PrintStream out = new PrintStream(PNAME + ".out");
		Scanner in = new Scanner(br);
		
		int TC = in.nextInt();
		
		for (int tc = 1; tc <= TC; tc++) {
			int c = in.nextInt();
			int n = in.nextInt();
			out.println("Case #" + tc + ": " + solve(c, n));
		}
		br.close();
		out.close();
	}

	private static double solve(int c, int n) {
		for (int i = 0; i < memo.length; i++) 
			memo[i] = -1;
		return calc(c, n, c);
	}

	// n <= c
	private static double calc(int c, int n, int need) {
		if (need == 0) return 0;
		if (memo[need] != -1) return memo[need];
		double ret = 1;
		int have = c - need;
		for (int good = 1; good <= Math.min(n, need); good++) {
			int bad = n - good;
			double p = choose(need, good);
			p *= choose(have, bad);
			p /= choose(c, n);
			ret += p * calc(c, n, need - good);
		}
		if (have >= n) {
			double p = choose(have, n) * 1.0 / choose(c, n);
			ret /= 1 - p;
		}
		memo[need] = ret;
		return ret;
	}

	// choose(40, 20) = 137846528820 < 10^12
	private static long choose(int n, int k) {
		long ret = 1;
		for (int i = 0; i < k; i++) {
			ret *= n - i;
			ret /= i + 1;
		}
		return ret;
	}

	static double[] memo = new double[64];

}
