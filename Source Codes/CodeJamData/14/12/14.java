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
	
	
	void solve() throws IOException {
		for (int testCase = 1, testCases = nextInt(); testCase <= testCases; testCase++) {
			solve(testCase);
		}
	}

	final int INF = Integer.MAX_VALUE >> 2;
	final int EMPTY = INF + 1;
	
	int vNum;
	MultiList tree;
	
	int[] sizes;
	int[] cache;
	
	void solve(int testCase) throws IOException {
		out.print("Case #" + testCase + ": ");
		
		vNum = nextInt();
		tree = new MultiList(vNum, 2 * vNum);
		
		for (int i = 1; i < vNum; i++) {
			final int u = nextInt() - 1;
			final int v = nextInt() - 1;
			tree.add(u, v);
			tree.add(v, u);
		}
		
		sizes = new int [vNum];
		cache = new int [vNum];
		
		int answer = Integer.MAX_VALUE;
		for (int root = 0; root < vNum; root++) {
			fill(sizes, EMPTY);
			fill(cache, EMPTY);
			answer = min(answer, rec(root, -1));
		}
		out.println(answer);
	}
	
	int rec(int v, int p) {
		if (cache[v] != EMPTY) return cache[v];
		int max1 = -1;
		int max2 = -1;
		for (int i = tree.head[v]; i != 0; i = tree.next[i]) {
			final int nv = tree.vert[i];
			if (nv == p) continue;
			final int profit = size(nv, v) - rec(nv, v);
			if (max1 < profit) {
				max2 = max1;
				max1 = profit;
			} else if (max2 < profit) {
				max2 = profit;
			}
		}
		int ops = size(v, p) - 1;
		if (max2 != -1)
			ops -= max1 + max2;
		return cache[v] = ops;
	}

	int size(int v, int p) {
		if (sizes[v] != EMPTY) return sizes[v];
		int size = 1;
		for (int i = tree.head[v]; i != 0; i = tree.next[i]) {
			final int nv = tree.vert[i];
			if (nv == p) continue;
			size += size(nv, v);
		}
		return sizes[v] = size;
	}

	class MultiList {
		final int[] head;
		final int[] next;
		final int[] vert;
		int cnt = 1;
		
		MultiList(int vNum, int eNum) {
			head = new int [vNum];
			next = new int [eNum + 1];
			vert = new int [eNum + 1];
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
