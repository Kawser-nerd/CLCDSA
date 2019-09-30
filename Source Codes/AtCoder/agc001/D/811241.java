import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {

	void solve() {
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = sc.nextIntArray(M);
		
		if (M == 1) {
			
			if (A[0] == 1) {
				print(A);
				out.println(1);
				out.println(1);
				return;
			}
			
			int[] B = new int[]{A[0] - 1, 1};
			print(A);
			out.println(B.length);
			print(B);
			return;
		}
		if (M == 2) {
			int[] B = new int[2];
			int bsize = 0;
			if (A[0] - 1 > 0) B[bsize++] = A[0] - 1;
			B[bsize++] = A[1] + 1;
			print(A);
			out.println(bsize);
			print(B, bsize);
			return;
		}
		
		int odd = 0;
		for (int a: A) if (a % 2 == 1) odd++;
		if (odd > 2) {
			out.println("Impossible");
			return;
		}
		
		A = ordering(A);
//		tr(A);
		
		int[] B = new int[A.length];
		int bsize = 0;
		if (A[0] - 1 > 0) B[bsize++] = A[0] - 1;
		for (int i = 1; i < A.length - 1; i++) B[bsize++] = A[i];
		B[bsize++] = A[A.length - 1] + 1;
		
		print(A);
		out.println(bsize);
		print(Arrays.copyOf(B, bsize));
	}
	
	int[] ordering(int[] A) {
		for (int i = 1; i + 1 < A.length; i++) {
			if (A[i] % 2 == 1) {
				int j = 0;
				if (A[j] % 2 == 0) { int t = A[i]; A[i] = A[j]; A[j] = t; }
				else {
					j = A.length - 1;
					{ int t = A[i]; A[i] = A[j]; A[j] = t; }
				}
				
			}
		}
		return A;
	}
	
	static void tr(Object... os) { System.err.println(deepToString(os)); }
	static void tr(int[][] as) { for (int[] a : as) tr(a); }

	void print(int[] a, int n) {
		if (n > 0) {
			out.print(a[0]);
			for (int i = 1; i < n; i++) out.print(" " + a[i]);
		}
		out.println();
	}
	void print(int[] a) {
		print(a, a.length);
	}


	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	MyScanner sc = null;
	PrintWriter out = null;
	public void run() throws Exception {
		sc = new MyScanner(System.in);
		out = new PrintWriter(System.out);
		for (;sc.hasNext();) {
			solve();
			out.flush();
		}
		out.close();
	}

	class MyScanner {
		String line;
		BufferedReader reader;
		StringTokenizer tokenizer;

		public MyScanner(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}
		public void eat() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					line = reader.readLine();
					if (line == null) {
						tokenizer = null;
						return;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		public String next() {
			eat();
			return tokenizer.nextToken();
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		public boolean hasNext() {
			eat();
			return (tokenizer != null && tokenizer.hasMoreElements());
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}
	}
}