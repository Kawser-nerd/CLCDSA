import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "c";

	private static final String PATTERN = "welcome to code jam";
	
	private static final int MOD = 10000;

	private int[][] dp;
	
	private String text;
	
	private int getValue(final int letter, final int position) {
		if (letter >= PATTERN.length()) {
			return 1;
		}
		if (position >= text.length()) {
			return 0;
		}
		if (dp[letter][position] != -1) {
			return dp[letter][position];
		}
		
		int value = 0;
		for (int i = position; i < text.length(); ++i) {
			if (text.charAt(i) == PATTERN.charAt(letter)) {
				value += getValue(letter + 1, i + 1);
			}
			value %= MOD;
		}
		
		return dp[letter][position] = value;
	}

	private void solve() throws Exception {
		final int testN = nextInt();
		for (int test = 1; test <= testN; ++test) {
			text = reader.readLine();
			final int n = text.length();
			dp = new int[PATTERN.length()][n];
			for (int[] i : dp) {
				Arrays.fill(i, -1);
			}
			
			String answer = "" + getValue(0, 0);
			while (answer.length() < 4) {
				answer = "0" + answer;
			}
			printf("Case #%d: " + answer + "\n", test);
		}
	}

	public void run() {
		try {
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter(
					new File(TASKNAME + ".out"))));

			solve();

			reader.close();
			writer.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(13);
		}

		showWorkTime();
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private String next() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private static void showWorkTime() {
		System.err.printf("%.3f\n",
				(System.currentTimeMillis() - startTime) * 0.001);
	}

	public static void main(String[] args) {
		startTime = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}

	private static long startTime;

	private BufferedReader reader;
	private PrintWriter writer;
	private StringTokenizer tokenizer;
}
