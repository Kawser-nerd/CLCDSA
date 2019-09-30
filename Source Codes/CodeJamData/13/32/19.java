import java.util.*;
import java.io.*;

//import java.math.*;

public class SolB implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolB()).start();
	}

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	private final String FNAME = "B-small-attempt0";
	
	int[] dx = new int[]{-1, 0, 0, 1};
	int[] dy = new int[]{0, -1, 1, 0};
	char[] dirch = new char[]{'W', 'S', 'N', 'E'}; 

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int xf = nextInt();
			int yf = nextInt();
			String ans = "";
			for (int i = 0; i < Math.abs(xf); i++) {
				if (xf < 0) {
					ans += "EW";
				} else {
					ans += "WE";
				}
			}
			for (int i = 0; i < Math.abs(yf); i++) {
				if (yf < 0) {
					ans += "NS";
				} else {
					ans += "SN";
				}
			}
			out.println(ans);
		}
	}
}
