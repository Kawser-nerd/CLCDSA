import java.util.*;
import java.io.*;
import java.math.BigInteger;
import static java.lang.Math.*;

public class Sol implements Runnable {
	final int N = 10000 + 5;
	int n;

	void solve() throws Exception {
		n = nextInt();
		int [] a = new int[N];
		for (int i = 0; i < n; i++) {
			int u = nextInt();
			a[u - 1]++;
			a[u]--;
		}

		ArrayList <Integer> plus = new ArrayList <Integer> ();	
		ArrayList <Integer> minus = new ArrayList <Integer> ();
		for (int i = 0; i < N; i++) {
			if (a[i] > 0) {
				for (int j = 0; j < a[i]; j++) {
					plus.add(i);
				}
			} else
			if (a[i] < 0) {
				for (int j = 0; j < -a[i]; j++) {
					minus.add(i);
				}
			}
		}
		
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < plus.size(); i++) {
			if (minus.get(i) < plus.get(i)) throw new AssertionError();
			ans = min(ans, minus.get(i) - plus.get(i)); 	
		}	

		if (ans == Integer.MAX_VALUE) {
			ans = 0;
		}
		
		out.printf("Case #%d: %d\n", testNumber + 1, ans);	
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
