import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	private final boolean useStandardIO = false;
	//private final String inFile = "C:\\Users\\Катя\\Downloads\\C-small-attempt0.in";
	//private final String outFile = "C-small.out";

	 private final String inFile = "C:\\Users\\Катя\\Downloads\\C-large.in";
	 private final String outFile = "C-large.out";

	private void solve() throws IOException {
		int n = nextInt(), sum = 0, min = Integer.MAX_VALUE;
		boolean[] bad = new boolean[30];
		for (int i = 0; i < n; ++i) {
			int x = nextInt();
			min = Math.min(x, min);
			sum += x;
			for (int j = 0; j < 30; ++j)
				if ((x & (1 << j)) != 0)
					bad[j] = !bad[j];
		}
		for (int i = 0; i < 30; ++i)
			if (bad[i]) {
				writer.println("NO");
				return;
			}
		writer.println(sum - min);
	}

	public static void main(String[] args) {
		new Thread(null, new C(), "", 64 * 1024 * 1024).start();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			try {
				Locale.setDefault(Locale.US);
			} catch (Exception e) {
			}
			if (useStandardIO) {
				reader = new BufferedReader(new InputStreamReader(System.in));
				writer = new PrintWriter(System.out);
			} else {
				reader = new BufferedReader(new FileReader(inFile));
				writer = new PrintWriter(new FileWriter(outFile));
			}
			tokenizer = null;

			long startTime = System.currentTimeMillis();
			int tests = nextInt();
			for (int i = 1; i <= tests; ++i) {
				writer.printf("Case #%d: ", i);
				solve();
				writer.flush();
				System.err
						.printf("Done %d out of %d test cases. Time passed: %.3f sec.\n",
								i,
								tests,
								(System.currentTimeMillis() - startTime) / 1000.0);
				System.err.flush();
			}

			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
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

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}