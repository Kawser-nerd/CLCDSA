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
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			out.format("Case #%d: ", i + 1);
			solver.solve(in, out);
		}
		
		out.close();
	}
}

class Solver {
	public void solve(InputReader in, PrintWriter out) {
		int a = in.nextInt();
		int n = in.nextInt();
		int[] m = new int[n];
		for (int i = 0; i < n; i++) {
			m[i] = in.nextInt();
		}
		Arrays.sort(m);
		if (a == 1) {
			out.println(n);
			return;
		}
		long cur = a;
		int ans = n;
		int cura = 0;
		for (int i = 0; i < n; i++) {
			ans = Math.min(cura + n - i, ans);
			while (cur <= m[i]) {
				cura++;
				cur += cur - 1;
			}
			cur += m[i];
		}
		ans = Math.min(ans, cura);
		out.println(ans);
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
