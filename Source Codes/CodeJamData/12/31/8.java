import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {

	final static boolean DEBUG = false;
	final int MOD = 1000000007;
	final double eps = 1e-9;
	
	public Object solve () throws IOException {
		int N = sc.nextInt();
		int [][] H = new int[N][];
		
		boolean [] LEAF = new boolean[N];
		fill(LEAF, true);
		
		for (int i = 0; i < N; ++i) {
			H[i] = new int[sc.nextInt()];
			for (int j = 0; j < H[i].length; ++j) {
				H[i][j] = sc.nextInt() - 1;
				LEAF[H[i][j]] = false;
			}
		}

		for (int i = 0; i < N; ++i) {
			if (LEAF[i]) {
				Set<Integer> C = new HashSet<Integer>();
				Queue<Integer> Q = new LinkedList<Integer>();
				Q.add(i);
				while (!Q.isEmpty()) {
					int z = Q.poll();
					if (!C.add(z))
						return "Yes";
					for (int j = 0; j < H[z].length; ++j)
						Q.add(H[z][j]);
				}
			}
		}
		return "No";
	}
	
	void init () {
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public A () throws IOException {
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
		new A();
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
