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
	long bestPlace(long p, long N) {
		if (p == N - 1)
			return N - 1;
		return bestPlace(((p % 2 == 0)?(p / 2):((p - 1) / 2 + 1)), N / 2);
	}
	long worstPlace(long p, long N) {
		if (p == 0)
			return 0;
		return N / 2 + worstPlace(((p % 2 == 0)?(p / 2 - 1):((p - 1) / 2)), N / 2);
	}
	public void solve(InputReader in, PrintWriter out) {
		long n = in.nextLong();
		long p = in.nextLong();
		long N = 1L << n;
		if (p == 1) {
			out.format("%d %d\n", 0, 0);
			return;
		}
		if (p == N) {
			out.format("%d %d\n", N - 1, N - 1);
			return;
		}
		long l = 0;
		long r = N - 1;
		while (l < r - 1) {
			long m = (l + r) / 2;
			if (bestPlace(m, N) <= p - 1)
				l = m;
			else
				r = m;
		}
		long ans1 = l;
		l = 0;
		r = N - 1;
		while (l < r - 1) {
			long m = (l + r) / 2;
			if (worstPlace(m, N) <= p - 1)
				l = m;
			else
				r = m;
		}
		long ans2 = l;
		out.format("%d %d\n", ans2, ans1);
		
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
