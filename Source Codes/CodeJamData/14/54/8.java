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
	String inputFile = "input/D-small-attempt0.in";
//	String inputFile = "input/D-large.in";
	
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

	int vNum;
	int[] costs;
	MultiList tree;
	
	int tick;
	int[][] tin;
	int[][] tout;
	
	int w = 1;
	int[][][][] was;
	int[][][][] cache;
	
	void solve(int testCase) throws IOException {
		out.print("Case #" + testCase + ": ");
		
		vNum = nextInt();
		costs = nextIntArray(vNum);
		tree = new MultiList(vNum, 3 * vNum);
		
		for (int u = 0; u + 1 < vNum; u++) {
			final int v = nextInt() - 1;
			tree.add(u, v);
			tree.add(v, u);
		}
		
		int answer = Integer.MIN_VALUE;
		
		was = new int [2][2][vNum][vNum];
		cache = new int [2][2][vNum][vNum];
		
		tin = new int [vNum][vNum];
		tout = new int [vNum][vNum];
		
		for (int start = 0; start < vNum; start++) {
			tick = 1;
			dfs(start, -1, tin[start], tout[start]);
		}
		
//		System.err.println(solve(7, 0));
		
		for (int start1 = 0; start1 < vNum; start1++) {
			int current = Integer.MAX_VALUE;
			for (int start2 = 0; start2 < vNum; start2++)
				current = min(current, solve(start1, start2));
//			System.err.println(start1 + " " + current);
			answer = max(answer, current);
		}
		out.println(answer);
	}
	
	int solve(int start1, int start2) {
		w++;
		int score1 = costs[start1];
		if (start2 != start1) score1 -= costs[start2];
		return score1 + rec(start1, start2, start1, start2, 0, 0);
	}
	
	int rec(int start1, int start2, int v1, int v2, int s1, int s2) {
		
//		System.err.println(start1 + " " + start2 + " " + v1 + " " + v2 + " " + s1 + " " + s2);
		
		if (was[s1][s2][v1][v2] == w)
			return cache[s1][s2][v1][v2];
		int result = Integer.MIN_VALUE;
		boolean stuck = true;
		if (s1 == 0) {
			for (int i = tree.head[v1]; i != 0; i = tree.next[i]) {
				final int nv = tree.vert[i];
				if (!used(start1, v1, v1, nv) && !used(start2, v2, v1, nv)) {
					stuck = false;
					final int score1 = isAncestor(nv, v2, tin[start2], tout[start2]) ? 0 : costs[nv];
					result = max(result, score1 - rec(start2, start1, v2, nv, s2, s1));
				}
			}
		}
		if (stuck)
			result = s2 == 0 ? -rec(start2, start1, v2, v1, s2, 1) : 0;
		was[s1][s2][v1][v2] = w;
		return cache[s1][s2][v1][v2] = result;
	}

	boolean used(int u, int v, int x, int y) {
		final int[] ti = tin[u];
		final int[] to = tout[u];
		return isAncestor(x, v, ti, to) && isAncestor(y, v, ti, to);
	}

	static boolean isStrictAncestor(int u, int v, int[] tin, int[] tout) {
		return tin[u] < tin[v] && tout[v] < tout[u];
	}
	
	static boolean isAncestor(int u, int v, int[] tin, int[] tout) {
		return tin[u] <= tin[v] && tout[v] <= tout[u];
	}

	void dfs(int v, int p, int[] tin, int[] tout) {
		tin[v] = tick++;
		for (int i = tree.head[v]; i != 0; i = tree.next[i]) {
			final int nv = tree.vert[i];
			if (nv != p) dfs(nv, v, tin, tout);
		}
		tout[v] = tick++;
	}

	static class MultiList {
		final int[] head;
		final int[] next;
		final int[] vert;
		int cnt = 1;

		MultiList(int hNum, int size) {
			head = new int [hNum];
			next = new int [size + 1];
			vert = new int [size + 1];
		}
		
		void add(int u, int v) {
			next[cnt] = head[u];
			vert[cnt] = v;
			head[u] = cnt++;
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
