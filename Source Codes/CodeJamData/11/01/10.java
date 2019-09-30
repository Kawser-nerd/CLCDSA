import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	private final boolean useStandardIO = false;
	//private final String inFile = "C:\\Users\\Катя\\Downloads\\A-small-attempt1.in";
	//private final String outFile = "A-small.out";

	 private final String inFile = "C:\\Users\\Катя\\Downloads\\A-large.in";
	 private final String outFile = "A-large.out";

	private void solve() throws IOException {
		int n = nextInt();
		char[] cmd = new char[n];
		int[] pos = new int[n];
		for (int i = 0; i < n; ++i) {
			cmd[i] = nextToken().charAt(0);
			pos[i] = nextInt();
		}
		int curO = 1, curB = 1, p = 0;
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (cmd[i] == 'O') {
				int dist = Math.abs(curO - pos[i]) + 1;
				res += dist;
				curO = pos[i];
				int nextB = -1;
				for (int j = i + 1; j < n; ++j)
					if (cmd[j] == 'B') {
						nextB = pos[j];
						break;
					}
				if (nextB != -1) {
					int dist2 = Math.abs(curB - nextB);
					if (dist2 <= dist) {
						curB = nextB;
					} else {
						if (curB < nextB)
							curB += dist;
						else
							curB -= dist;
					}
				}
			} else {
				int dist = Math.abs(curB - pos[i]) + 1;
				res += dist;
				curB = pos[i];
				int nextO = -1;
				for (int j = i + 1; j < n; ++j)
					if (cmd[j] == 'O') {
						nextO = pos[j];
						break;
					}
				if (nextO != -1) {
					int dist2 = Math.abs(curO - nextO);
					if (dist2 <= dist) {
						curO = nextO;
					} else {
						if (curO < nextO)
							curO += dist;
						else
							curO -= dist;
					}
				}
			}
		}
		writer.println(res);
	}

	public static void main(String[] args) {
		new Thread(null, new A(), "", 64 * 1024 * 1024).start();
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