import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class Main implements Runnable {

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(inpFile));
		out = new PrintWriter(outFile);
		new Main().run();
		out.close();
	}

	static BufferedReader br;
	static PrintWriter out;
	StringTokenizer st;
	static String fileName = "b";
	static String inpFile = fileName + ".in";
	static String outFile = fileName + ".out";

	String ns() {
		try {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		} catch (Exception e) {
			return null;
		}
	}

	String nline() {
		try {
			return br.readLine();
		} catch (Exception e) {
			return null;
		}
	}

	int ni() {
		return Integer.valueOf(ns());
	}

	long nl() {
		return Long.valueOf(ns());
	}

	double nd() {
		return Double.valueOf(ns());
	}

	int n, k;
	int p = 10009;
	char[] val;

	int[][] ss;
	int[] x;
	int k2;

	int findP() {
		long sum = 0;
		long comp = 1;
		for (int i = 0; i < val.length; i++) {
			if (val[i] == '+') {
				sum += comp;
				comp = 1;
			} else {
				int j = val[i] - 'a';
				int x = 0;
				for (int l = 0; l < k2; l++)
					x += ss[poses[l]][j];
				comp *= x;
				comp %= p;
			}
		}
		sum += comp;
		return (int) (sum % p);
	}

	int[] ans;
	int[] poses;

	void rec(int k1) {
		if (k1 > k)
			return;
		k2 = k1;
		ans[k1] += findP();
		ans[k1] %= p;
		for (int i = 0; i < n; i++) {
			poses[k1] = i;
			rec(k1 + 1);
		}
	}

	public void run() {

		int t = ni();
		int tnum = 1;
		while (t-- > 0) {
			val = ns().toCharArray();
			k = ni();
			n = ni();
			ss = new int[n][26];
			for (int i = 0; i < n; i++) {
				String s = ns();
				for (int j = 0; j < s.length(); j++) {
					ss[i][s.charAt(j) - 'a']++;
				}
			}
			ans = new int[k + 1];
			x = new int[26];
			poses = new int[k + 1];
			rec(0);
			out.print("Case #" + tnum + ": ");
			for (int i = 1; i <= k; i++) {
				out.print(ans[i] + " ");
			}
			out.println();
			System.out.println("Case #" + tnum);
			tnum++;
		}

	}

}
