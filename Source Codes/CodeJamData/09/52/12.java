import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "b";
	
	private static int MOD = 10009;
	
	private static int evalute(char[][] ss, int[] val) {
		int answer = 0;
		for (char[] s : ss) {
			int add = 1;
			for (char c : s) {
				add *= val[c - 'a'];
				add %= MOD;
			}
			answer += add;
			answer %= MOD;
		}
		return answer;
	}
	
	private int[] values;
	
	private char[][] split(String s) {
		ArrayList<char[]> list = new ArrayList<char[]>();
		StringBuilder builder = new StringBuilder();
		for (char c : s.toCharArray()) {
			if (c == '+') {
				list.add(builder.toString().toCharArray());
				builder = new StringBuilder();
			} else {
				builder.append(c);
			}
		}
		list.add(builder.toString().toCharArray());
		final char[][] answer = new char[list.size()][];
		for (int i = 0; i < answer.length; ++i) {
			answer[i] = list.get(i);
		}
		return answer;
	}
	
	private int answer;
	private char[][] splitted;
	private int[][] qntys; 
	
	private void getSums(int depth, int[] qntys) {
		if (depth == 0) {
			answer += evalute(splitted, qntys);
			answer %= MOD;
			return;
		}
		for (int[] a : this.qntys) {
			for (int i = 0; i < a.length; ++i) {
				qntys[i] += a[i];
			}
			getSums(depth - 1, qntys);
			for (int i = 0; i < a.length; ++i) {
				qntys[i] -= a[i];
			}
		}
	}

	private void solve() throws Exception {
		final int testN = nextInt();
		for (int test = 1; test <= testN; ++test) {
			final String pol = nextToken();
			splitted = split(pol);
			final int K = nextInt();
			final int n = nextInt();
			qntys = new int[n][26];
			values = new int[n];
		
			int sum  =0;
			for (int i = 0; i < n; ++i) {
				for (char c : nextToken().toCharArray()) {
					++qntys[i][c - 'a'];
				}
				values[i] = evalute(splitted, qntys[i]);
				sum = (sum + values[i]) % MOD;
			}
			
			printf("Case #%d: ", test, sum);
			for (int i = 1; i <= K; ++i) {
				answer = 0;
				getSums(i, new int[26]);
				print(answer + " ");
			}
			println("");
			writer.flush();
		}
	}

	private BufferedReader reader;
	private PrintWriter writer;
	private StringTokenizer tokenizer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter(TASKNAME
					+ ".out")));

			solve();

			reader.close();
			writer.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(13);
		}
	}

	private void print(final Object o) {
		writer.print(o);
	}

	private void println(final Object o) {
		writer.println(o);
	}

	private void printf(final String format, final Object... o) {
		writer.printf(format, o);
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws InterruptedException {
		final long startTime = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		final Thread thread = new Thread(new Main());
		thread.start();
		thread.join();
		System.err.printf("%.3f\n",
				(System.currentTimeMillis() - startTime) * 0.001);
	}
}
