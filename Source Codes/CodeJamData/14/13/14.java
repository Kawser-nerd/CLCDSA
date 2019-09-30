import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.fill;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;

public class Main {
	public static void main(String[] args) throws IOException {
		long prevTime = System.currentTimeMillis();
		new Main().run();
		System.err.println("Total time: " + (System.currentTimeMillis() - prevTime) + " ms");
		System.err.println("Memory status: " + memoryStatus());
	}

	static final Random RND = new Random(7777L);
	
//	String inputFile = "sample.txt";
	String inputFile = "input/C-small-attempt0.in";
	
	String outputFile = "output.txt";
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
		solve();
		out.close();
	}
	
	int cnt = 0;
	
	void solve() throws IOException {
		for (int testCase = 1, testCases = nextInt(); testCase <= testCases; testCase++) {
			solve(testCase);
		}
		System.err.println(cnt);
	}

	void solve(int testCase) throws IOException {
		out.print("Case #" + testCase + ": ");
		int n = nextInt();
		int[] a = nextIntArray(n);
		double p = 0.0;
		for (int i = 0; i < n; i++)
			p += p(n, i, a[i]);
		System.err.println(p);
		
		if (p > 1.057)
			cnt++;
		
		out.println(p > 1.055 ? "BAD" : "GOOD");
	}
	
	double p(int len, int pos, int num) {
		final double uniform = 1.0 / len;
		if (num == 0 || pos == len - 1)
			return uniform;
		final int dist = abs(pos - num);
		final double min = 0.9 * uniform;
		final double max = 1.25 * uniform;
		final double rel = (len - dist) / (double) len;
		if (num <= pos) {
			return uniform + rel * (min - uniform);
		}
		return uniform + rel * (max - uniform);				
	}

	void calcProbs(int n, int iters) {
		int[][] cnt = new int [n][n];
		int[] perm = new int [n];
		for (int it = 0; it < iters; it++) {
			for (int i = 0; i < n; i++)
				perm[i] = i;
			badShuffle(perm);
			for (int i = 0; i < n; i++)
				cnt[i][perm[i]]++;
		}
		System.err.println("n=" + n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.printf(Locale.US, "%.3f ", cnt[i][j] / (double) iters);
			}
			System.out.println();
		}
	}
	
	static void badShuffle(int[] a) {
		for (int i = 0; i < a.length; i++)
			swap(a, i, RND.nextInt(a.length));
	}
	
	static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	/*************************************************************** 
	 * Input 
	 **************************************************************/
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	int[] nextIntArray(int size) throws IOException {
		int[] ret = new int [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextInt();
		return ret;
	}
	
	long[] nextLongArray(int size) throws IOException {
		long[] ret = new long [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextLong();
		return ret;
	}
	
	double[] nextDoubleArray(int size) throws IOException {
		double[] ret = new double [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextDouble();
		return ret;
	}
	
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
	
	/*************************************************************** 
	 * Output 
	 **************************************************************/
	void printRepeat(String s, int count) {
		for (int i = 0; i < count; i++)
			out.print(s);
	}
	
	void printArray(int[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(long[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array, String spec) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.printf(Locale.US, spec, array[i]);
		}
		out.println();
	}
	
	void printArray(Object[] array) {
		if (array == null || array.length == 0)
			return;
		boolean blank = false;
		for (Object x : array) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	@SuppressWarnings("rawtypes")
	void printCollection(Collection collection) {
		if (collection == null || collection.isEmpty())
			return;
		boolean blank = false;
		for (Object x : collection) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	/*************************************************************** 
	 * Utility
	 **************************************************************/
	static String memoryStatus() {
		return (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory() >> 20) + "/" + (Runtime.getRuntime().totalMemory() >> 20) + " MB";
	}
	
	static void checkMemory() {
		System.err.println(memoryStatus());
	}
	
	static long prevTimeStamp = Long.MIN_VALUE;
	
	static void updateTimer() {
		prevTimeStamp = System.currentTimeMillis();
	}
	
	static long elapsedTime() {
		return (System.currentTimeMillis() - prevTimeStamp);
	}
	
	static void checkTimer() {
		System.err.println(elapsedTime() + " ms");
	}
}
