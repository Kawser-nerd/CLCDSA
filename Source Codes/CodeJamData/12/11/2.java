import java.io.*;
import java.util.*;

public class PasswordProblem {

	void solve() throws Exception {
		int a = nextInt();
		int b = nextInt();
		double[] p = new double[a];
		for (int i = 0; i < a; i++) {
			p[i] = nextDouble();
		}
		double[] prob = p.clone();
		for (int i = 1; i < a; i++) {
			prob[i] = prob[i - 1] * prob[i];
		}
		
		double ans = b + 2;
		for (int i = a - 1; i >= 0; i--) {
			double curAns = (a - i - 1) + (b - i - 1) + 1 + (1 - prob[i]) * (b + 1);
			ans = Math.min(ans, curAns);
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("PasswordProblem").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new PasswordProblem().run();
	}

}
