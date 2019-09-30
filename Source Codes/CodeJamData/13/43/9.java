import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			out.format("Case #%d: ", i + 1);
			solver.solve(in, out);
		}
		
		out.close();
	}
}

class Solver {
	int[] r, a, b;
	boolean rec(int p, int n, int[] da, int[] db) {
		if (p == n) {
			return true;
		}
		for (int i = 0; i < n; ++i) {
			if (r[i] == 0)
				if (da[i] + 1 > a[i] || db[i] + 1 > b[i])
					return false;
		}
		for (int i = 0; i < n; ++i) {
			if (r[i] == 0)
				if (da[i] + 1 == a[i] && db[i] + 1 == b[i]) {
					r[i] = p + 1;
					int[] nda, ndb;
					nda = new int[n];
					ndb = new int[n];
					for (int j = 0; j < n; j++) {
						nda[j] = da[j];
						ndb[j] = db[j];
					}
					//nda[i] = Math.max(1, nda[i]);
					//ndb[i] = Math.max(1, ndb[i]);
					nda[i]++;
					ndb[i]++;
					for (int j = 0; j < i; ++j) {
						ndb[j] = Math.max(ndb[j], db[i] + 1);
					}
					for (int j = i + 1; j < n; ++j) {
						nda[j] = Math.max(nda[j], da[i] + 1);
					}
					
					if (rec(p + 1, n, nda, ndb))
						return true;
					r[i] = 0;
				}
		}
		return false;
	}
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		r = new int[n];
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}
		int[] da, db;
		da = new int[n];
		db = new int[n];
		rec(0, n, da, db);
		
		for (int i = 0; i < n; i++) {
			out.format("%d ", r[i]);
		}
		out.println();
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
