import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
//	final String filename = problem + "-sample";

	// final String filename = problem + "-small-attempt0";

//	 final String filename= problem+"-small-attempt2";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		long M = lread(), F = lread();
		int N = iread();
		Food[] f = new Food[N];
		for (int i = 0; i < N; i++)
			f[i] = new Food(lread(), lread());
		Arrays.sort(f);
		long T = 1;
		long ans = 0;
		while (true) {
			long sum = F, sum2 = F * T, day = 0, day2 = 0;
			int j = -1;
			long sumprev = sum;
			if (M>0)
			for (int i = 0; i < N; i++) {
				j = i;
				long s = f[i].s + 1 - day;
				f[i].amount = Math.min(s, (M - sum2) / (f[i].p * T));
				if (f[i].amount < 0)
					f[i].amount = 0;
				sum += f[i].amount * f[i].p;
				sum2 += f[i].amount * f[i].p * T;
				day += f[i].amount;
				day2 += f[i].amount * T;
				if (f[i].amount < s) {
					long x = (M - sum2) / f[i].p;
					day2 += x;
					sum2 += x * f[i].p;
					break;
				} else 
					sumprev = sum;
			}
			ans = Math.max(ans, day2);
			if (day2<T) break;
			if (j>=0) {
				T = Math.max(T+1, M/(sumprev)-10);
			} else T++;
		}
		out.write(ans + "");
	}

	class Food implements Comparable<Food> {
		long p, s, amount;

		public Food(long p, long s) {
			super();
			this.p = p;
			this.s = s;
		}

		@Override
		public int compareTo(Food o) {
			if (p - o.p < 0)
				return -1;
			if (p - o.p > 0)
				return 1;
			return 0;
		}
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}