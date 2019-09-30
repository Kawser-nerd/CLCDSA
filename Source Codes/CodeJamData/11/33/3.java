import java.io.*;
import java.math.BigInteger;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.BIPUSH;

import static java.lang.Math.*;
import static java.util.Arrays.fill;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

//	String inputFile = "sample.txt";
//	String inputFile = "input/C-small-attempt0.in";
	String inputFile = "input/C-large.in";
	
	String outputFile = "output.txt";
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
	
		for (int testCase = 1, testCount = nextInt(); testCase <= testCount; testCase++) {
			solve(testCase);
		}
		
		out.close();
	}

	/* Solving */
	long INF = Long.MAX_VALUE / 7L;
	
	int N;
	long L;
	long H;
	BigInteger bH;
	long[] notes;
	
	long ans;
	long[] gcd;
	
	void solve(int testCase) throws IOException {
		System.out.println(testCase);
		
		/* Input */
		N = nextInt();
		L = nextLong();
		H = nextLong();
		bH = BigInteger.valueOf(H);
		notes = new long [N];
		for (int i = 0; i < N; i++)
			notes[i] = nextLong();
		
		/* Solution */
		ans = INF;
		sort(notes);
		gcd = new long [N + 1];
		for (int i = N - 1; i >= 0; i--)
			gcd[i] = gcd(notes[i], gcd[i + 1]);
		long lgcd = gcd[0];
		for (long cand = 1L; cand * cand <= lgcd; cand++) {
			if (lgcd % cand == 0L) {
				updateAnswer(cand);
				updateAnswer(lgcd / cand);
			}
		}
		
		long lcm = 1L;
		BigInteger nlcm = BigInteger.ONE;
		for (int i = 0; i < N; i++) {
			BigInteger cval = BigInteger.valueOf(notes[i]);
			nlcm = nlcm.multiply(cval).divide(nlcm.gcd(cval));
			BigInteger bgcd = BigInteger.valueOf(gcd[i + 1]);
			if (nlcm.compareTo(bgcd) > 0) continue;
			
			lcm = nlcm.longValue();
			long cgcd = gcd[i + 1];
			if (cgcd % lcm != 0L) continue;
			long mul = cgcd / lcm;
			BigInteger bmul = BigInteger.valueOf(mul);
			
			for (long K = 1L; K * K <= mul; K++) {
				if (mul % K == 0) {
					check(K, bmul, lcm);
					check(mul / K, bmul, lcm);
				}
			}
		}
		
		if (nlcm.compareTo(bH) <= 0) {
			long l = nlcm.longValue();
			long K = (L + l - 1L) / l;
			updateAnswer(K * l);
		}
		
		/* Output */
		out.print("Case #" + testCase + ": ");
		out.println(ans == INF ? "NO" : ans);
		
	}
	
	void check(long k, BigInteger bmul, long lcm) {
		BigInteger bcand = BigInteger.valueOf(k).multiply(BigInteger.valueOf(lcm));
		if (bcand.compareTo(bH) <= 0)
			updateAnswer(k * lcm);
	}

	void updateAnswer(long cand) {
		if (L <= cand && cand <= H)
			ans = min(ans, cand);
	}

	long gcd(long a, long b) {
		while (a > 0L && b > 0L)
			if (a > b)
				a %= b;
			else
				b %= a;
		return a + b;
	}

	/*************************************************************** 
	 * Input 
	 **************************************************************/
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
