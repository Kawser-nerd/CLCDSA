import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	private final boolean useStandardIO = false;
	// private final String inFile =
	// "C:\\Users\\Катя\\Downloads\\B-small-attempt0.in";
	// private final String outFile = "B-small.out";

	private final String inFile = "C:\\Users\\Катя\\Downloads\\B-large.in";
	private final String outFile = "B-large.out";

	private void solve() throws IOException {
		char[][] combine = new char[256][256];
		int c = nextInt();
		for (int i = 0; i < c; ++i) {
			String s = nextToken();
			combine[s.charAt(0)][s.charAt(1)] = s.charAt(2);
			combine[s.charAt(1)][s.charAt(0)] = s.charAt(2);
		}
		boolean[][] oppose = new boolean[256][256];
		int d = nextInt();
		for (int i = 0; i < d; ++i) {
			String s = nextToken();
			oppose[s.charAt(0)][s.charAt(1)] = true;
			oppose[s.charAt(1)][s.charAt(0)] = true;
		}
		int n = nextInt();
		List<Character> ans = new ArrayList<Character>();
		for (char ch : nextToken().toCharArray()) {
			ans.add(ch);
			if (ans.size() > 1
					&& combine[ans.get(ans.size() - 1)][ans.get(ans.size() - 2)] > 0) {
				char t = combine[ans.get(ans.size() - 1)][ans
						.get(ans.size() - 2)];
				ans.remove(ans.size() - 1);
				ans.remove(ans.size() - 1);
				ans.add(t);
			} else if (ans.size() > 1) {
				for (int i = 0; i < ans.size() - 1; ++i)
					if (oppose[ans.get(i)][ch]) {
						ans.clear();
						break;
					}
			}
		}
		writer.println(Arrays.toString(ans.toArray()));
	}

	public static void main(String[] args) {
		new Thread(null, new B(), "", 64 * 1024 * 1024).start();
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