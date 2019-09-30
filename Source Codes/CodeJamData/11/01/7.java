import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
	String file = "a";

	private void solve() throws IOException {
		int tn = nextInt();
		for (int testN = 1; testN <= tn; ++testN) {
			int time = 0;
			int[] t = new int[] {0, 0};
			int[] p = new int[] {1, 1};
			int n = nextInt();
			for (int i = 0; i < n; ++i) {
				String whoC = next();
				int who = 0;
				if (whoC.equals("B")) {
					who = 1;
				}
				int np = nextInt();
				t[who] = time = Math.max(time, Math.abs(p[who] - np) + t[who]) + 1;
				p[who] = np;
			}
			out.printf("Case #%d: %d\n", testN, time);
		}
	}

	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	StringTokenizer tok;
	PrintWriter out;
	BufferedReader br;

	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			out = new PrintWriter(new FileWriter(file + ".out"));
			br = new BufferedReader(new FileReader(file + ".in"));
			tok = new StringTokenizer("");
			while (hasNext()) {
				solve();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	boolean hasNext() throws IOException {
		while (!tok.hasMoreElements()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			tok = new StringTokenizer(line);
		}
		return true;
	}

	String next() throws IOException {
		if (hasNext()) {
			return tok.nextToken();
		}
		throw new IOException("No more tokens");
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

	String nextLine() throws IOException {
		if (hasNext()) {
			return tok.nextToken("\n");
		}
		throw new IOException("No more tokens");
	}
}
