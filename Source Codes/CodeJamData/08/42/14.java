import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			int n = nextInt();
			int m = nextInt();
			int a = nextInt();
			out.print("Case #" + (tt + 1) + ": ");
			boolean found = false;
			outer:
			for (int x1 = 0; x1 <= n; x1++) {
				for (int x2 = 0; x2 <= n; x2++) {
					for (int y1 = 0; y1 <= m; y1++) {
						for (int y2 = 0; y2 <= m; y2++) {
							if (Math.abs(x1 * y2 - x2 * y1) == a) {
								out.println("0 0 " + x1 + " " + y1 + " " + x2 + " " + y2);
								found = true;
								break outer;
							}
						}
					}
				}
			}
			if (!found) {
				out.println("IMPOSSIBLE");
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("b")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}
	
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}
	
}
