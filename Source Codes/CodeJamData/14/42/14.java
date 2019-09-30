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
//	String inputFile = "input/B-small-attempt0.in";
	String inputFile = "input/B-large.in";
	
	String outputFile = "output.txt";
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
		solve();
		out.close();
	}
	
	static final int INF = Integer.MAX_VALUE / 3;
	
	void solve() throws IOException {
		for (int testCase = 1, testCases = nextInt(); testCase <= testCases; testCase++) {
			System.err.println(testCase);
			solve(testCase);
		}
	}

	void solve(int testCase) throws IOException {
		out.print("Case #" + testCase + ": ");
		
		final int n = nextInt();
		final int[] a = nextIntArray(n);
		final int[] set = getOrderedSet(a);
		final Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < set.length; i++)
			map.put(set[i], i + 1);
		for (int i = 0; i < n; i++)
			a[i] = map.get(a[i]);
		out.println(solve(a));
	}
	
	int solve(int[] a) {
		final int n = a.length;
		final int[] costL = new int [n + 1];
		final int[] costR = new int [n + 1];
		for (int x = 1; x <= n; x++) {
			int subL = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] < x) {
					subL++;
				} else if (x == a[i]) {
					final int cntL = i;
					final int cntR = n - 1 - i;
					final int subR = x - 1 - subL;
					costL[x] = cntL - subL;
					costR[x] = cntR - subR;
					break;
				}
			}
		}
		
//		System.err.println(Arrays.toString(costL));
//		System.err.println(Arrays.toString(costR));
		
		final int[][] lastL = new int [n + 1][n + 1];
		final int[][] lastR = new int [n + 1][n + 1];
		for (final int[] row : lastL) fill(row, INF);
		for (final int[] row : lastR) fill(row, INF);
		
		lastL[1][0] = costL[1];
		lastR[0][1] = costR[1];
		
		for (int c = 2; c <= n; c++) {
			
			/* Last left */ {
				final int l = c - 1;
				for (int r = 0; r <= n; r++) {
					final int curCost = lastL[l][r];
					if (curCost == INF) continue;
					
					/* Put left */
					lastL[c][r] = min(lastL[c][r], curCost + costL[c]);
					
					/* Put right */
					lastR[l][c] = min(lastR[l][c], curCost + costR[c]);
				}
			}
			
			/* Last right */ {
				final int r = c - 1;
				for (int l = 0; l <= n; l++) {
					final int curCost = lastR[l][r];
					if (curCost == INF) continue;
					
					/* Put left */
					lastL[c][r] = min(lastL[c][r], curCost + costL[c]);
					
					/* Put right */
					lastR[l][c] = min(lastR[l][c], curCost + costR[c]);
				}
			}
		}
		
		int result = INF;
		for (int r = 0; r <= n; r++)
			result = min(result, lastL[n][r]);
		for (int l = 0; l <= n; l++)
			result = min(result, lastR[l][n]);
		return result;
	}


	static void swap(int[] a, int i, int j) {
		final int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	static int[] getOrderedSet(int[] a) {
		final int[] set = Arrays.copyOf(a, a.length);
		if (a.length == 0) return set;
		sort(set);
		int k = 1;
		int prev = set[0];
		for (int i = 1; i < a.length; i++) {
			if (prev != set[i]) {
				set[k++] = prev = set[i];
			}
		}
		return Arrays.copyOf(set, k);
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
