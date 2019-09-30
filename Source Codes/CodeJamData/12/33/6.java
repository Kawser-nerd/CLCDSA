import static java.lang.Math.*;

import java.io.*;
import java.util.*;

public class C {

	final static boolean DEBUG = true;
	final int MOD = 1000000007;
	final double eps = 1e-9;
	
	public Object solve () throws IOException {
		N = sc.nextInt(); M = sc.nextInt();
		long [] a = new long [N], A = new long[N];
		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextLong();
			A[i] = sc.nextLong();
		}
		
		long [] b = new long[M], B = new long[M];
		for (int i = 0; i < M; ++i) {
			b[i] = sc.nextLong();
			B[i] = sc.nextLong();
		}

		H = new HashMap<String, Long>();
		return calc(a, b, A, B, 0, 0, a[0], b[0]);
	}

	int N, M;
	Map<String, Long> H;
	
	String key(long na, long nb, long xa, long xb) {
		return na + ":" + nb + ":" + xa + ":" + xb;
	}
	
	long calc(long [] a, long [] b, long [] A, long [] B, int na, int nb, long xa, long xb) {
		if (na == N || nb == M) return 0;
		assert(xa > 0 && xb > 0);
		String K = key(na, nb, xa, xb);
		if (H.containsKey(K))
			return H.get(K);
		
		long res = 0, x = 0, y = 0, z = 0;
		
		if (A[na] == B[nb]) {
			long d = min(xa, xb); xa -= d; xb -= d;
			if (xa == 0) { ++na; if (na < N) xa = a[na]; }
			if (xb == 0) { ++nb; if (nb < M) xb = b[nb]; }
			z = d + calc(a,b,A,B,na,nb,xa,xb);
		} else {
			if (1+na < N) x = calc(a,b,A,B,1+na,nb,a[1+na],xb);
			if (1+nb < M) y = calc(a,b,A,B,na,1+nb,xa,b[1+nb]);
		}
		
		res = max(res,x);
		res = max(res,y);
		res = max(res,z);
		
		H.put(K, res);
		return res;
	}
	
	void init () {
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public C () throws IOException {
		init();
		int N = sc.nextInt();
		for (int n = 1; n <= N; ++n)
			print("Case #" + n + ": " + solve());
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	static MyScanner sc;
	
	static class MyScanner {
		String next() throws IOException {
			newLine();
			return line[index++];
		}
		
		char nextChar() throws IOException {
			return next().charAt(0);
		}
				
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
		
		String nextLine() throws IOException {
			line = null;
			return r.readLine();
		}
		
		String [] nextStrings() throws IOException {
			line = null;
			return r.readLine().split(" ");
		}
		
		char [] nextChars() throws IOException {
			return next().toCharArray();
		}

		int [] nextInts() throws IOException {
			String [] L = nextStrings();
			int [] res = new int [L.length];
			for (int i = 0; i < L.length; ++i)
				res[i] = Integer.parseInt(L[i]);
			return res;
		}	
		
		long [] nextLongs() throws IOException {
			String [] L = nextStrings();
			long [] res = new long [L.length];
			for (int i = 0; i < L.length; ++i)
				res[i] = Long.parseLong(L[i]);
			return res;
		}

		double [] nextDoubles() throws IOException {
			String [] L = nextStrings();
			double [] res = new double [L.length];
			for (int i = 0; i < L.length; ++i)
				res[i] = Double.parseDouble(L[i]);
			return res;
		}

		boolean eol() {
			return index == line.length;
		}

		//////////////////////////////////////////////
		
		private final BufferedReader r;

		MyScanner () throws IOException {
			this(new BufferedReader(new InputStreamReader(System.in)));
		}
		
		MyScanner(BufferedReader r) throws IOException { 
			this.r = r;
		}
		
		private String [] line;
		private int index;

		private void newLine() throws IOException {
			if (line == null || eol()) {
				line = r.readLine().split(" ");
				index = 0;
			}
		}		
	}
	
	static class MyWriter {
		StringWriter sw = new StringWriter();
		PrintWriter pw = new PrintWriter(sw);
		
		void print(Object o) {
			pw.print(o);
		}
		
		void println(Object o) { 
			pw.println(o);
		}
		
		void println() {
			pw.println();
		}
		
		public String toString() {
			return sw.toString();
		}
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public static void main(String[] args) throws IOException {
		start();
		run();
		exit();
	}

	static void start() {
		t = millis();
	}

	static void run () throws IOException {
		sc = new MyScanner ();
		new C();
	}
		
	static void exit () {
		if (DEBUG) {
			System.err.println("------------------");
			System.err.println("Time: " + secs());
		}
		System.exit(0);
	}

	static void print (Object o) {
		System.out.println(o);
		if (DEBUG)
			System.err.println(o + " (Time: " + secs() + ")");
	}
		
	static long t;	

	static long millis() {
		return System.currentTimeMillis();
	}
	
	static double secs() {
		return (millis() - t) / 1000.0;
	}
}
