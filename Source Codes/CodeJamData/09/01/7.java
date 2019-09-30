import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Locale;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
	private static final String TASKNAME = "a";

	private void solve() throws Exception {
		final int l = nextInt();
		final int d = nextInt();
		final int n = nextInt();
		final String[] strings = new String[d];
		for (int i = 0; i < d; ++i) {
			strings[i] = next();
		}
		for (int test = 1; test <= n; ++test) {
			printf("Case #%d: ", test);
			final String s = next();
			HashSet<Character>[] sets = new HashSet[l];
			int position = 0;
			for (int i = 0; i < l; ++i) {
				sets[i] = new HashSet<Character>();
				if (Character.isLetter(s.charAt(position))) {
					sets[i].add(s.charAt(position));
					++position;
				} else {
					++position;
					while (s.charAt(position) != ')') {
						sets[i].add(s.charAt(position));
						++position;
					}
					++position;
				}
			}
			int answer = 0;
			for (int i = 0; i < d; ++i) {
				boolean ok = true;
				for (int j = 0; j < strings[i].length(); ++j) {
					if (!sets[j].contains(strings[i].charAt(j))) {
						ok = false;
						break;
					}
				}
				if (ok) {
					++answer;
				}
			}
			println(answer);
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
