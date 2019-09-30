import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2016R2A implements Runnable {

	private PrintWriter out;
	
	final String file = "A-large";
	static Random rnd = new Random(42);

	final static String[] names = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	final static String[] fs = {"Z", "Ozwu", "W", "Hg", "U", "Fu", "X", "Sx", "G", "IUfxg"};

	static class InputData {

		String s;
		
		InputData(FastReader in) throws IOException {
			s = in.next();
		}

		int[] cnts = new int[26];
		
		void solve(PrintWriter out) {
			for (char c : s.toCharArray()) {
				cnts[c - 'A']++;
			}
			for (int i = 0; i < 10; ++i) {
				int count = 0;
				for (char c : fs[i].toCharArray()) {
					if (Character.isUpperCase(c)) {
						count += cnts[c - 'A'];
					} else {
						count -= cnts[c - 'a'];
					}
				}
				for (int it = 0; it < count; ++it) {
					out.print(i);
				}
			}
			out.println();
		}
	}
	
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			StringWriter out = new StringWriter();
			data.solve(new PrintWriter(out));
			return out.toString();
		}
		
	}

	public void run() {
		for (char c = 'A'; c <= 'Z'; ++c) {
			int[] vec = new int[10];
			boolean ok = false;
			for (int i = 0; i < 10; ++i) {
				for (char c1 : names[i].toCharArray()) {
					if (c == c1) {
						vec[i]++;
						ok = true;
					}
				}
			}
			if (ok) {
				System.err.print(c + "=");
				boolean first = true;
				for (int i = 0; i < 10; ++i) {
					if (vec[i] > 0) {
						if (first) {
							first = false;
						} else {
							System.err.print("+");
						}
						if (vec[i] > 1) {
							System.err.print(vec[i] + "*");
						}
						System.err.print("x" + i);
					}
				}
				System.err.println("");
			}
		}
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
			out = new PrintWriter(file + ".out");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
		void eat(String s) {
			st = new StringTokenizer(s);
		}
		
		String next() throws IOException {
			while (!st.hasMoreTokens()) {
				String line = in.readLine();
				if (line == null) {
					return null;
				}
				eat(line);
			}
			return st.nextToken();
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new GCJ2016R2A().run();
	}
	
}
