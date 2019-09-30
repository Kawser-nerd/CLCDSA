import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "A";
//	final String filename = problem + "-sample";

	 final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-attempt1";
	// final String filename= problem+"-large";

	int[] p;
	boolean[] isprime;
	int[] primediv;
	int pc;

	public void init() {
		p = new int[1000000];
		pc = 0;
		isprime = new boolean[1000000];
		primediv = new int[1000000];
		cycle: for (int i = 2; i < 1000000; i++) {
			if (primediv[i]>0) continue;
			p[pc++] = i;
			isprime[i] = true;
			if (i < 1000000 / i)
				for (int j = i * i; j < 1000000; j += i)
					primediv[j] = i;
		}
	}

	public void solve() throws Exception {
		int D = iread(), K = iread();
		int D10 = 1;
		for (int i = 0; i < D; i++)
			D10 *= 10;

		int minP = 0;
		int[] s = new int[K];
		for (int i = 0; i < K; i++) {
			s[i] = iread();
			minP = Math.max(s[i] + 1, minP);
		}
		
		if (K==1)
		{
			out.write("I don't know.");
			return;
		}

		int next = -1;
		for (long P = minP; P < D10; P++) {
			if (!isprime[(int)P])
				continue;
			cycle:for (long A=0; A<P; A++)
			{
				long B = (s[1] - s[0]*A)%P;
				if (B<0) B+=P;
				
				for (int i=1; i<K; i++)
				{
					int ss = (int)((A*s[i-1]+B)%P);
					if (ss!=s[i])
						continue cycle;
				}
				
				int next2 = (int)((A*s[K-1]+B)%P);
				if (next>=0 && next2!=next)
				{
					out.write("I don't know.");
					return;
				}
				next = next2;
			}
		}
		out.write(next + "");
	}

	long gcd(long x, long y) {
		while (x > 0 && y > 0) {
			if (x > y)
				x %= y;
			else
				y %= x;
		}
		return x + y;
	}

	public void solve_gcj() throws Exception {
		init();
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