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

//	String inputFile = "sample.txt";
//	String inputFile = "t128.txt";
//	String inputFile = "input/A-small-attempt1.in";
	String inputFile = "input/A-large.in";
	
	String outputFile = "output.txt";
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
		solve();
		out.close();
	}
	
	
	void solve() throws IOException {
		for (int testCase = 1, testCases = nextInt(); testCase <= testCases; testCase++) {
			solve(testCase);
		}
	}

	int N;
	int L;
	long[] outlets;
	long[] devices;
	long[] tmp;
	
	boolean[][] can;
	
	void solve(int testCase) throws IOException {
		out.print("Case #" + testCase + ": ");
		System.err.println("test " + testCase);
		
		N = nextInt();
		L = nextInt();
		outlets = new long [N];
		devices = new long [N];
		tmp = new long [N];
		for (int i = 0; i < N; i++) {
			outlets[i] = Long.parseLong(nextToken(), 2);
		}
		for (int i = 0; i < N; i++) {
			devices[i] = Long.parseLong(nextToken(), 2);
		}
		sort(devices);
		
		can = new boolean [L][2];
		for (int i = 0; i < L; i++) {
			can[i][0] = count(outlets, i, 0) == count(devices, i, 0);
			can[i][1] = count(outlets, i, 0) == count(devices, i, 1);
			if (!can[i][0] && !can[i][1]) {
				System.err.println("Pos " + i + " has bad configuration");
				out.println("NOT POSSIBLE");
				return;
			}
		}
		
		for (int answer = 0; answer <= L; answer++) {
			int r = rec(0, 0, answer);
//			System.err.println(r);
			if (r != -1) {
//				assert(r == answer);
				out.println(r);
				return;
			}
		}
		out.println("NOT POSSIBLE");
	}
	
	void print(long[] outlets) {
		for (long x : outlets)
			System.err.println(toBitString(x));
	}


	int count(long[] arr, int pos, int bit) {
		int count = 0;
		final int shift = L - pos - 1;
		for (long x : arr) {
			if (((x >> shift) & 1L) == bit) {
				count++;
			}
		}
		return count;
	}

	int rec(final int pos, final int ops, final int maxOps) {
		if (pos == L) return ops;
		if (can[pos][0] && match(pos + 1)) {
			int r = rec(pos + 1, ops, maxOps);
			if (r != -1) return r;
		}
		if (can[pos][1] && ops < maxOps) {
			invert(pos);
			if (match(pos + 1)) {
				int r = rec(pos + 1, ops + 1, maxOps);
				if (r != -1) return r;
			}
			invert(pos);
		}
		return -1;
	}

	void invert(int pos) {
		final int shift = L - pos - 1;
		for (int i = 0; i < N; i++) {
			outlets[i] ^= 1L << shift;
		}
	}

	boolean match(final int len) {
		final int shift = L - len;
		for (int i = 0; i < N; i++)
			tmp[i] = outlets[i] >> shift;
		sort(tmp);
		for (int i = 0; i < N; i++)
			if (tmp[i] != (devices[i] >> shift))
				return false;
		return true;
	}

	String toBitString(long num) {
		String s = Long.toBinaryString(num);
		while (s.length() < L)
			s = "0" + s;
		return s;
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
