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
	
	class Point {
		double x, y;
		Point(double q, double w) {
			x = q; y = w;
		}
	}
	
	double dist(Point a, Point b) {
		double x = a.x - b.x;
		double y = a.y - b.y;
		return Math.sqrt(x * x + y * y);
	}
	
	void solve() throws IOException {
		nextInt();
		int m = nextInt();
		Point g1 = new Point(nextInt(), nextInt());
		Point g2 = new Point(nextInt(), nextInt());
		boolean f = false;
		if (dist(g1, g2) < 1e-7) f = true;
		for (int i = 0; i < m; i++) {
			Point a = new Point(nextInt(), nextInt());
			if (f) {
				out.printf("%.7f ", Math.PI * dist(g1, a) * dist(g1, a));
			} else {
				double r1 = dist(g1, a);
				double r2 = dist(g2, a);
				double d = dist(g1, g2);
				double ang2 = Math.acos((r2 * r2 + d * d - r1 * r1) / 2 / (r2 * d)) * 2;
				double ang1 = Math.acos((r1 * r1 + d * d - r2 * r2) / 2 / (r1 * d)) * 2;
				double seg1 = r1 * r1 * ang1 / 2 - r1 * r1 * Math.sin(ang1) / 2;
				double seg2 = r2 * r2 * ang2 / 2 - r2 * r2 * Math.sin(ang2) / 2;
				out.printf("%.7f ", seg1 + seg2);
			}
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
