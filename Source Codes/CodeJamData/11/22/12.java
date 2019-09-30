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

	double[] a = new double[1000100];
	
	void solve() throws IOException {
		int c = nextInt();
		int d = nextInt();
		int l = 0;
		for (int i = 0; i < c; i++) {
			int p = nextInt();
			int v = nextInt();
			for (int j = 0; j < v; j++) a[l++] = p;
		}
		double td = a[0];
		double ts = 0;
		for (int i = 1; i < l; i++) {
			if (a[i] + ts - td >= d) {
				double ni = td + d;
				td = Math.max(ni, a[i] - ts);
				continue;
			}
			double dd = d - a[i] - ts + td;
			ts += dd / 2;
			td = a[i] + ts;
		}
		out.printf("%.7f\n", ts);
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
