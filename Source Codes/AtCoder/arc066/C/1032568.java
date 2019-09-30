import java.io.*;
import java.util.*;

public class Main {
	void run() {
		int n = in.nextInt() - 1;
		int[] a = new int[n];
		boolean[] minus = new boolean[n];
		long total = in.nextInt();
		for (int i = 0; i < n; i++) {
			minus[i] = "-".equals(in.next());
			a[i] = in.nextInt();
			total += a[i];
		}
		int i = 0;
		while (i < n && !minus[i]) {
			i++;
		}
		if (i == n) {
			out.println(total);
			return;
		}
		long bestSub = Long.MAX_VALUE;
		long sub = 0;
		while (i < n) {
			int x = a[i];
			long y = 0;
			i++;
			while (i < n && !minus[i]) {
				y += a[i];
				i++;
			}
			bestSub = Math.min(bestSub, sub + x + y);
			sub += x;
		}
		bestSub = Math.min(bestSub, sub);
		out.println(total - 2 * bestSub);
	}

	static MyScanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		boolean stdStreams = true;
		String fileName = Main.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		BufferedReader br;
		if (stdStreams) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader(inputFileName));
			out = new PrintWriter(outputFileName);
		}
		in = new MyScanner(br);
		int tests = 1;//in.nextInt();
		for (int test = 0; test < tests; test++) {
			new Main().run();
		}
		br.close();
		out.close();
	}
	
	static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		MyScanner(BufferedReader br) {
			this.br = br;
		}
		
		void findToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		
		String next() {
			findToken();
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}