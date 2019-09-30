import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Solution {

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	private String filename = "large";

	int n;
	char[][] v;

	double calcWP(int team) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < n; ++i) {
			if (v[team][i] != '.')
				++b;
			if (v[team][i] == '1')
				++a;
		}
		return (double) a / (double) b;
	}

	double calcWP1(int team, int who) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < n; ++i) {
			if (i == who)
				continue;
			if (v[team][i] != '.')
				++b;
			if (v[team][i] == '1')
				++a;
		}
		return (double) a / (double) b;
	}

	double calcOWP(int team) {
		double ret = 0.0;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (v[team][i] != '.') {
				ret += calcWP1(i, team);
				++cnt;
			}
		return ret / (double) cnt;
	}

	double calcOOWP(int team) {
		double ret = 0.0;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (v[team][i] != '.') {
				ret += calcOWP(i);
				++cnt;
			}
		return ret / (double) cnt;
	}

	void solve() throws IOException {
		int tests = ni();
		for (int test = 1; test <= tests; ++test) {
			n = ni();
			v = new char[n][n];
			for (int i = 0; i < n; ++i)
				v[i] = ns().toCharArray();
			out.println("Case #" + test + ":");
			for (int i = 0; i < n; ++i) {
				double rpi = 0.25 * calcWP(i) + 0.5 * calcOWP(i) + 0.25
						* calcOOWP(i);
				out.println(rpi);
			}
		}
	}

	public Solution() throws IOException {
		in = new BufferedReader(new FileReader(filename + ".in"));
		out = new PrintWriter(filename + ".out");
		solve();
		in.close();
		out.close();
	}

	String ns() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int ni() throws IOException {
		return Integer.valueOf(ns());
	}

	long nl() throws IOException {
		return Long.valueOf(ns());
	}

	double nd() throws IOException {
		return Double.valueOf(ns());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
