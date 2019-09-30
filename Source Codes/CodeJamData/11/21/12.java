import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Locale;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Map.Entry;

public class Solution implements Runnable {

	public static void main(String[] args) {
		(new Thread(new Solution())).start();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	BigInteger nextBigInt() throws IOException {
		return new BigInteger(nextToken());
	}
	
	void solve() throws IOException {
		int n = nextInt();
		char[][] a = new char[n][n];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			for (int j = 0; j < n; j++) {
				a[i][j] = s.charAt(j);
			}
		}
		double[] wp = new double[n];
		for (int i = 0; i < n; i++) {
			double ch = 0;
			int zn = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] != '.') {
					if (a[i][j] == '1') {
						ch += 1;
					}
					zn++;
				}
			}
			wp[i] = ch / zn;
		}
		double[] owp = new double[n];
		for (int i = 0; i < n; i++) {
			double swp = 0;
			int cc = 0;
			for (int ii = 0; ii < n; ii++) if (a[i][ii] != '.') {
				cc++;
				double ch = 0;
				int zn = 0;
				for (int j = 0; j < n; j++) if (j != i) {
					if (a[ii][j] != '.') {
						if (a[ii][j] == '1') {
							ch += 1;
						}
						zn++;
					}
				}
				swp += ch / zn;
			}
			owp[i] = swp / cc;
		}
		double[] oowp = new double[n];
		for (int i = 0; i < n; i++) {
			oowp[i] = 0;
			int cc = 0;
			for (int j = 0; j < n; j++) if (a[i][j] != '.') {
				oowp[i] += owp[j];
				cc++;
			}
			oowp[i] /= cc;
		}
		for (int i = 0; i < n; i++) {
			out.println();
			out.printf("%.7f", .25 * wp[i] + .5 * owp[i] + .25 * oowp[i]);
		}
		out.println();
	}
	
	public void run() {
		Locale.setDefault(Locale.UK);
		try {
			in = new BufferedReader(new FileReader(new File("input.txt")));
			out = new PrintWriter(new FileWriter(new File("output.txt")));
			int t = nextInt();
			for (int nn = 1; nn <= t; nn++) {
				out.print("Case #" + nn + ": ");
				solve();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		out.flush();
	}

}
