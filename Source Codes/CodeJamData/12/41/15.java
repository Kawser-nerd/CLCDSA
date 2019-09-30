
import java.io.BufferedReader;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class GCJ_R2_A {

	static boolean test = true;

	private void solve() throws Throwable {
		int t = iread();
		for (int i = 0; i < t; i++) {
			solveIt(i + 1);
		}
	}

	private void solveIt(int casenr) throws Throwable {
		int n = iread();
		long[] best = new long[n];
		long[] pos = new long[n];
		long[] len = new long[n];
		boolean[] reached = new boolean[n];

		for (int i = 0; i < n; i++) {
			pos[i] = lread();
			len[i] = lread();
		}
		long D = lread();
		reached[0] = true;
		best[0] = pos[0];

		for (int i = 0; i < best.length; i++) {
			if (reached[i]) {
				for (int k = i + 1; k < n && pos[k] <= pos[i] + best[i]; k++) {
					best[k] = Math.max(best[k], Math.min(pos[k] - pos[i], len[k]));
					reached[k] = true;
				}
			}
		}

		String ans = "NO";
		for (int i = 0; i < n; i++) {
			if (reached[i] && best[i] + pos[i] >= D) {
				ans = "YES";
			}
		}
		String answerString = "Case #" + casenr + ": " + ans;
		out.write(answerString + "\n");
		System.out.println(answerString);
	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {
		new GCJ_R2_A().solve();
		out.close();
	}

	public GCJ_R2_A() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
			out = new BufferedWriter(new FileWriter(getClass().getCanonicalName() + "-out.txt"));
		} else {
			new BufferedReader(inp);
		}
	}

	static InputStreamReader inp = new InputStreamReader(System.in);
	static BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	// static BufferedWriter out;// = new BufferedWriter(new FileWriter("out.txt"));

	static String testDataFile = "A-large.in";
}