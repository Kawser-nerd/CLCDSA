import java.util.*;
import java.io.*;
import java.math.BigInteger;
import static java.lang.Math.*;

public class Sol implements Runnable {
	
	long ans = -1;
	
	void go(char [] c, int i) {
		if (i == c.length) {
			long x = Long.parseLong(new String(c), 2);
			if (testNumber == 2) debug(x);
			long r = Math.round(sqrt(x));
			if (r * r == x || (r + 1) * (r + 1) == x || (r - 1) * (r - 1) == x) {
				ans = x;
			}
			return;
		}
		if (c[i] == '?') {
			c[i] = '0';
			go(c, i + 1);
			c[i] = '1';
			go(c, i + 1);
			c[i] = '?';
		} else go(c, i + 1);
	}

	void solve() throws Exception {
		char [] c = in.readLine().toCharArray();
		go(c, 0);	

		out.printf("Case #%d: %s\n", testNumber + 1, Long.toBinaryString(ans));	
	}

	public static void main(String[] args) {
		new Thread(new Sol()).start();
	}

	int testNumber;
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			sTime();
			int T = nextInt();
			for (testNumber = 0; testNumber < T; testNumber++) {
				solve();
				debug("Test " + testNumber + " finished at time: " + gTime());
			}

			out.close();

		} catch (Exception e) {
			System.err.println("exception at test = " + testNumber);
			e.printStackTrace();
		}
	}

	
	StringTokenizer tokenizer = new StringTokenizer("");
	BufferedReader in;
	PrintWriter out;

	long time;
	void sTime() { time = System.currentTimeMillis(); }
	long gTime() { return System.currentTimeMillis() - time; }
	void gMemory() { debug("Memory: " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + " kb"); }
	public void debug(Object o) { System.err.println(o); }

	
	boolean seekForToken() {
		while (!tokenizer.hasMoreTokens()) {
			String s = null;
			try {
				s = in.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (s == null)
				return false;
			tokenizer = new StringTokenizer(s);
		}
		return true;
	}

	String nextToken() {
		return seekForToken() ? tokenizer.nextToken() : null;
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

	BigInteger nextBig() {
		return new BigInteger(nextToken());
	}
}
