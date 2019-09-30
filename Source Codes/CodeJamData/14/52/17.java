import java.io.*;
import java.math.BigInteger;
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
	String inputFile = "input/B-small-attempt0.in";
//	String inputFile = "input/B-large.in";
	
	String outputFile = "output.txt";
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
		solve();
		out.close();
	}
	
	
	void solve() throws IOException {
		for (int testCase = 1, testCases = nextInt(); testCase <= testCases; testCase++) {
			System.err.println("Case #" + testCase + ": ");
			solve(testCase);
		}
	}

	int P, Q, N;
	int[] G;
	
	void solve(int testCase) throws IOException {
		out.print("Case #" + testCase + ": ");
		
		P = nextInt();
		Q = nextInt();
		N = nextInt();
		final int[] H = new int [N];
		G = new int [N];
		
		for (int i = 0; i < N; i++) {
			H[i] = nextInt();
			G[i] = nextInt();
		}
		cache = new HashMap<Long, Integer>();
		out.println(rec(Arrays.copyOf(H, N)));
	}
	
	Map<Long, Integer> cache;
	
	int rec(final int[] H) {
		final long hash = hash(H);
		Integer result = cache.get(hash);
		if (result == null) {
			result = 0;
			if (!allZero(H)) {
				for (int i = -1; i < H.length; i++) {
					final int[] h = Arrays.copyOf(H, H.length);
					int cur = 0;
					if (i >= 0) {
						if (h[i] == 0) continue;
						cur += hit(h, i, P);
					}
					for (int j = 0; j < H.length; j++) {
						if (h[j] > 0) {
							hit(h, j, Q);
							break;
						}
					}
					result = max(result, cur + rec(h));
				}
			}
			cache.put(hash, result);
		}
		return result;
	}

	boolean allZero(int[] H) {
		for (final int h : H)
			if (h > 0)
				return false;
		return true;
	}


	int hit(int[] H, int pos, int dmg) {
		if (H[pos] > 0) {
			H[pos] = max(0, H[pos] - dmg);
			if (H[pos] == 0) {
				return G[pos];
			}
		}
		return 0;
	}

	static final Random RANDOM = new Random(7777L);
	static final long BASE = BigInteger.probablePrime(31, RANDOM).longValue();
	
	static long hash(int[] a) {
		long hash = 0L;
		long pow = BASE;
		for (long x : a) {
			hash += pow * x;
			pow *= BASE;
		}
		return hash;
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
