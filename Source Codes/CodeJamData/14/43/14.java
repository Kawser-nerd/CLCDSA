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
//	String inputFile = "input/C-small-attempt0.in";
	String inputFile = "input/C-large.in";
	
	String outputFile = "output.txt";
	
	void run() throws IOException {
		in = new BufferedReader(new FileReader(inputFile));
		out = new PrintWriter(outputFile);
		solve();
		out.close();
	}
	
	static final int INF = Integer.MAX_VALUE / 2 - 1;
	
	void solve() throws IOException {
		for (int testCase = 1, testCases = nextInt(); testCase <= testCases; testCase++) {
			System.err.println("Case #" + testCase + ": ");
			solve(testCase);
		}
	}

	final List<Rect> rects = new ArrayList<Main.Rect>();
	
	void solve(int testCase) throws IOException {
		out.print("Case #" + testCase + ": ");
		
		final int width = nextInt();
		final int height = nextInt();
		final int nBuildings = nextInt();
		
		rects.clear();
		rects.add(new Rect(-1, -1, -1, height + 1));
		rects.add(new Rect(width, -1, width, height + 1));
		for (int i = 0; i < nBuildings; i++)
			rects.add(new Rect(nextInt(), nextInt(), nextInt(), nextInt()));
		
		final int start = 0;
		final int end = 1;
		
		final int nVerts = rects.size();
		final int[][] g = new int [nVerts][nVerts];
		for (int i = 0; i < nVerts; i++)
			for (int j = 0; j < nVerts; j++)
				g[i][j] = rectDist(rects.get(i), rects.get(j));
		
//		for (int[] row : g)
//			System.err.println(Arrays.toString(row));
		
		final int[] dist = new int [nVerts];
		final boolean[] used = new boolean [nVerts];
		fill(dist, INF);
		dist[start] = 0;
		
		for (;;) {
			int v = -1;
			for (int i = 0; i < nVerts; i++)
				if (!used[i] && dist[i] != INF && (v == -1 || dist[v] > dist[i]))
					v = i;
			if (v == -1 || v == end) break;
			used[v] = true;
			for (int i = 0; i < nVerts; i++) {
				if (used[i]) continue;
				dist[i] = min(dist[i], dist[v] + g[v][i]);
			}
		}
		
		out.println(dist[end]);
	}
	
	static int rangeDist(int l1, int r1, int l2, int r2) {
		return max(0, max(l1, l2) - min(r1, r2) - 1);
	}
	
	static int rectDist(Rect r1, Rect r2) {
		return max(rangeDist(r1.minX, r1.maxX, r2.minX, r2.maxX), rangeDist(r1.minY, r1.maxY, r2.minY, r2.maxY));
	}
	
	static class Rect {
		final int minX;
		final int minY;
		final int maxX;
		final int maxY;
		
		Rect(int minX, int minY, int maxX, int maxY) {
			this.minX = minX;
			this.minY = minY;
			this.maxX = maxX;
			this.maxY = maxY;
		}
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
