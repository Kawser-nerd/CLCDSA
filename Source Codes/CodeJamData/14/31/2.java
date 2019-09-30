import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class SolA {

	public static void main(String[] args) {
		try {
			new SolA().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine(), " \n\t/");
			} catch (IOException e) {
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
	
	String FNAME = "A-large";
	
	boolean compare(long a, long b, long c, long d) {
		BigInteger t1 = BigInteger.valueOf(a).multiply(BigInteger.valueOf(d));
		BigInteger t2 = BigInteger.valueOf(c).multiply(BigInteger.valueOf(b));
		return t1.compareTo(t2) >= 0;
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			long p = nextLong();
			long q = nextLong();
			long d = BigInteger.valueOf(p).gcd(BigInteger.valueOf(q)).longValue();
			p /= d;
			q /= d;
//			out.print (p + "/" + q + " : " + 1.0 * p / q + " ");
			if (Long.bitCount(q) != 1 || p > q || q > (1l << 40)) {
				out.println("impossible");
			} else {
				int ans = 1;
				long pp = 1;
				long qq = 2;
				while (!compare(p, q, pp, qq)) {
					qq *= 2;
					ans++;
				}
				out.println(ans);
			}
		}
	}
}
